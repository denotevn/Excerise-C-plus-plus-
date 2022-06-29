#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>

#ifndef WEATHERSTATISTICS_H_
#define WEATHERSTATISTICS_H_
#define RESOURCE_PATH "../resource/"

class WeatherStatistics
{
    public:
        WeatherStatistics();
        bool isValidDateTime(std::string data, std::string time); // std::time 
        // std::time return the current callendar time encoded as a std::tie_t object
        double computeCoeff(std::string startDate, std::string startTime, std::string endDate, std::string endTime);
    private:
        std::map<time_t, double> timeToPreessure_;
        void loadData();
        time_t getFirstDateTime();
        time_t getLastDateTime();
        time_t convertDateTime(std::string date, std::string time);

};

#endif // WEATHERSTATISTICS_H_