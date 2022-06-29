/**
 * DashboardData.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "DashboardData.hpp"

using namespace std;

void DashboardData::loadData()
{
	dbData_.clear();

	fstream dataFile;
	dataFile.open(CSV_DATA_PATH);

	cout << CSV_DATA_PATH << endl;

	status lineData;
	string line, strElement, timestamp, lineTime;
	getline(dataFile, line); // skip header row

	while (dataFile.good())
	{
		getline(dataFile, line);
		stringstream ssElement(line);

		getline(ssElement, timestamp, ',');
		lineTime = timestamp.substr(timestamp.find("T") + 1, 8);

		getline(ssElement, strElement, ',');
		lineData.pulsometer = stoi(strElement);

		getline(ssElement, strElement, ',');
		lineData.engine = stod(strElement);

		getline(ssElement, strElement, ',');
		lineData.red = stoi(strElement);

		getline(ssElement, strElement, ',');
		lineData.blue = stoi(strElement);

		getline(ssElement, strElement, '\r');
		lineData.green = stoi(strElement);

		dbData_[lineTime] = lineData;
	}

	dataFile.close();
}

void DashboardData::getData()
{
	time_t rawTime;
	time(&rawTime);

	struct tm * sysTime = localtime(&rawTime);

	// format time to hh:mm:ss
	strftime((char*)dataTime_.c_str(), 80, "%T", sysTime);

	currentStatus_ = dbData_[dataTime_];
}

string DashboardData::getTime()
{
	return dataTime_;
}

int DashboardData::getPulsometer()
{
	return currentStatus_.pulsometer;
}

double DashboardData::getEngine()
{
	return currentStatus_.engine;
}

int DashboardData::getRed()
{
	return currentStatus_.red;
}

int DashboardData::getBlue()
{
	return currentStatus_.blue;
}

int DashboardData::getGreen()
{
	return currentStatus_.green;
}