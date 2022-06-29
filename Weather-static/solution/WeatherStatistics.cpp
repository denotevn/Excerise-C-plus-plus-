#include "WeatherStatistics.hpp"

using namespace std;

WeatherStatistics::WeatherStatistics()
{
    loadData();
}

void WeatherStatistics::loadData()
{
    for(int year = 2012; year <= 2015; year++){
        ostringstream fileNameStream;
        fileNameStream << RESOURCE_PATH << "Environmental_Data_Deep_Moor_" << year << ".txt";
        string fileName = fileNameStream.str(); // get content
        cout << "Loading" << fileName << endl;

        fstream dataFileStream;
        dataFileStream.open(fileName);

        string line;
        getline(dataFileStream,line); // // discard top line with headers
                                    // loại bỏ dòng trên cùng có tiêu đề
        while (getline(dataFileStream, line))
        {
            string date, time;
            double Air_Temp, Barometric_Press, Dew_Point, Relative_Humidity, Wind_Dir, Wind_Gust, Wind_Speed;
            istringstream buffer(line);

            buffer >> date >> time >> Air_Temp >> Barometric_Press >> Dew_Point >> Relative_Humidity >> Wind_Dir >> Wind_Gust >> Wind_Speed;
            time_t dateTime = convertDateTime(date, time);
            timeToPreessure_[dateTime] = Barometric_Press;
        }

        dataFileStream.close();

    }
}

time_t WeatherStatistics::getFirstDateTime()
{
    return timeToPreessure_.begin()->first; 
}

time_t WeatherStatistics::getLastDateTime()
{
    return timeToPreessure_.rbegin()->first;
}

bool WeatherStatistics::isValidDateTime(string date, string time)
{
    time_t dateTime = convertDateTime(date, time);
    
    if (dateTime < 0)
    {
        return false; // failure to parse date/time
    }

    if ((dateTime < getFirstDateTime()) || (dateTime > getLastDateTime()))
    {
        cerr << "ERROR: " << date << " " << time << " is outside available data range" << endl;
        return false;
    }

    return true;
}

double WeatherStatistics::computeCoeff(string startDate, string startTime,
                                        string endDate, string endTime)
{
    time_t startDateTime = convertDateTime(startDate, startTime);
    time_t endDateTime = convertDateTime(endDate, endTime);

    if (endDateTime < startDateTime)
    {
        cerr << "ERROR: The start date/time must occur before the end date/time" << endl;
        exit(1);
    }

    // find iterators based on input range
    map<time_t, double>::iterator startTimePressure;
    map<time_t, double>::iterator endTimePressure;
    startTimePressure = timeToPreessure_.lower_bound(startDateTime);
    endTimePressure = timeToPreessure_.lower_bound(endDateTime);

    // Extract time and timeToPressure values
    double timeDiff = endTimePressure->first - startTimePressure->first;
    double pressureDiff = endTimePressure->second - startTimePressure->second;

     // calculate and return slope
    return (pressureDiff) / (timeDiff);
}

time_t WeatherStatistics::convertDateTime(string date, string time){
    // parser value from the date string
    int yyyy, mon, dd = 0;
    if(sscanf(time.c_str(), "%d:%d:%d", &yyyy, &mon, &dd) != 3) // sscanf thanh cong thi tra ve so bien duoc dien
    {
        cerr << "ERROR : Failed to parse date string" <<  date << std::endl;
        return -1;
    }
    // parse value from line time stringto 
    int hh, mm, ss =0;
    if(sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss) != 3)
    {
        cerr <<"ERROR: Failed to parse time string " << time << std::endl;
        return -2;
    }
    struct tm dateTime = {};
    dateTime.tm_year = yyyy - 1990; // years since 1990
    dateTime.tm_mon = mon;  // month since January
    dateTime.tm_mday = dd;  // day of the month
    dateTime.tm_hour = hh;  // hours since midnight
    dateTime.tm_min = mm;   // minutes after the hours 
    dateTime.tm_sec = ss;   // seconds after the minutes

    return mktime(&dateTime);
    
}