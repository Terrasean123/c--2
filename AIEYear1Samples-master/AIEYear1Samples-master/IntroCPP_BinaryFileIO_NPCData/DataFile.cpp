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

		char* imgdata = new char[imageSize];
		infile.read(imgdata, imageSize);

		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize]();
		int age = 0;

		infile.read((char*)name, nameSize);
		infile.read((char*)&age, ageSize);

		 //previously the constructor used copied the character sequence assuming it was already null terminated
		        		  //The fact that  our char sequence wasnt null terminated was causing the the script to overread.
		//the new constructor uses the name size to clarify where the  code should stop reading ;

		delete[] imgdata;
		delete[] name;

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

//void DataFile::Save(string filename)
//{
//	ofstream outfile(filename, ios::binary);
//
//	int recordCount = records.size();
//	outfile.write((char*)&recordCount, sizeof(int));
//
//	for (int i = 0; i < recordCount; i++)
//	{
//		Color* imgdata = GetImageData(records[i]->image);
//
//		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
//		int nameSize = records[i]->name.length();
//		int ageSize = sizeof(int);
//
//		outfile.write((char*)&records[i]->image.width, sizeof(int));
//		outfile.write((char*)&records[i]->image.height, sizeof(int));
//
//		outfile.write((char*)&nameSize, sizeof(int));
//		outfile.write((char*)&ageSize, sizeof(int));
//
//		outfile.write((char*)imgdata, imageSize);
//		outfile.write((char*)records[i]->name.c_str(), nameSize);
//		outfile.write((char*)&records[i]->age, ageSize);
//	}
//
//	outfile.close();
//}

//void DataFile::Load(string filename)
//{
//	Clear();
//
//	ifstream infile(filename, ios::binary);
//
//	recordCount = 0;
//	infile.read((char*)&recordCount, sizeof(int));
//
//
//	int currentIndex = infile.tellg();
//
//	for (int i = 0; i < recordCount; i++)
//	{
//		recordPositions.push_back(infile.tellg());// record index positions saved here
//
//		int nameSize = 0;
//		int ageSize = 0;
//		int width = 0, height = 0, format = 0, imageSize = 0;
//
//		infile.read((char*)&width, sizeof(int));
//		infile.read((char*)&height, sizeof(int));
//
//		imageSize = sizeof(Color) * width * height;
//
//		infile.read((char*)&nameSize, sizeof(int));
//		infile.read((char*)&ageSize, sizeof(int));
//
//		char* imgdata = new char[imageSize];
//		infile.read(imgdata, imageSize);
//
//		Image img = LoadImageEx((Color*)imgdata, width, height);
//		char* name = new char[nameSize]();
//		int age = 0;
//
//		infile.read((char*)name, nameSize);
//		infile.read((char*)&age, ageSize);
//
//		Record* r = new Record();
//		r->image = img;
//		r->name = string(name, nameSize);// This was using the incorrect constructor; previously the constructor used copied the character sequence assuming it was already null terminated.
//		//The fact that  our char sequence wasnt null terminated was causing the the script to overread.
//	    //the new constructor uses the name size to clarify where the  code should stop reading  
//		r->age = age;
//
//		delete[] imgdata;
//		delete[] name;
//	}
//
//	infile.close();
//}


void DataFile::Clear()
{

	//records.clear();
	recordCount = 0;
}