#include "DataFile.h"
#include <fstream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	Clear();
}

void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record;
	r->image = i;
	r->name = name;
	r->age = age;


	recordCount++;
}

DataFile::Record* DataFile::GetRecord(int index, std::string filename)// because get record needs to access the infile stream directly now a new parameter had to be made 
{
	ifstream infile(filename, ios::binary);

	infile.read((char*)&recordCount, sizeof(int));



	for (int i = 0; i < index; i++)
	{
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));
		infile.seekg(nameSize + ageSize + imageSize,ios_base::cur);

		//previously the constructor used copied the character sequence assuming it was already null terminated
	  //The fact that  our char sequence wasnt null terminated was causing the the script to overread.
	   //the new constructor uses the name size to clarify where the  code should stop reading ;
	}

	int nameSize = 0;
	int ageSize = 0;
	int width = 0, height = 0, format = 0, imageSize = 0;

	infile.read((char*)&width, sizeof(int));
	infile.read((char*)&height, sizeof(int));

	imageSize = sizeof(Color) * width * height;

	infile.read((char*)&nameSize, sizeof(int));
	infile.read((char*)&ageSize, sizeof(int));

	char* imgdata = new char[imageSize];
	infile.read(imgdata, imageSize);

	Image img = LoadImageEx((Color*)imgdata, width, height);
	char* name = new char[nameSize]();
	int age = 0;

	infile.read((char*)name, nameSize);
	infile.read((char*)&age, ageSize);

	Record* r = new Record();
	r->image = img;
	r->name = string(name, nameSize); //previously the constructor used copied the character sequence assuming it was already null terminated
	r->age = age;	        		  //The fact that  our char sequence wasnt null terminated was causing the the script to overread.
	//the new constructor uses the name size to clarify where the  code should stop reading ;

	delete[] imgdata;
	delete[] name;
	currentRecord = r;

	infile.close();

	return currentRecord; // return the record required
}