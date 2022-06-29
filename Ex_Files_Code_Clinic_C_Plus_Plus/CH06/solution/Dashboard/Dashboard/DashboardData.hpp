/**
 * DashboardData.hpp by Olivia Stone for Code Clinic: C++
 **/

#ifndef	DASHBOARDDATA_H_
#define DASHBOARDDATA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>

#define CSV_DATA_PATH ".\\resource\\dashBoardData.csv"

using namespace std;

class DashboardData
{
public:
	void loadData();
	void getData();
	string getTime();
	int getPulsometer();
	double getEngine();
	int getRed();
	int getBlue();
	int getGreen();

private:
	struct status {
		int pulsometer;
		double engine;
		int red;
		int blue;
		int green;
	} currentStatus_;

	string dataTime_ = "hh:mm:ss";
	map<string, status> dbData_; 
};

#endif // DASHBOARDDATA_H_