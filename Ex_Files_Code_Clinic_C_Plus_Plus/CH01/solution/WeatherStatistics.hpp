/**
 * WeatherStatistics.hpp by Olivia Stone for Code Clinic: C++
 **/

#ifndef WEATHERSTATISTICS_H_
#define WEATHERSTATISTICS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>

#define RESOURCE_PATH "../resources/"

class WeatherStatistics
{
public:
    WeatherStatistics();
	bool isValidDateTime(std::string date, std::string time);
	double computeCoeff(std::string startDate, std::string startTime,
	                    std::string endDate, std::string endTime);

private: 
	std::map<time_t, double> timeToPressure_;

	void loadData();
	time_t getFirstDateTime();
	time_t getLastDateTime();
	time_t convertDateTime(std::string date, std::string time);
};

#endif // WEATHERSTATISTICS_H_