#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	struct Record {
		Image image;
		string name;
		int age;
	};

private:
	int recordCount;
	Record* currentRecord;
	std::vector <int> recordPositions; // stores the index locations of all  all records



public:
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index, std::string);

	int GetRecordCount() { return recordCount; };

};

