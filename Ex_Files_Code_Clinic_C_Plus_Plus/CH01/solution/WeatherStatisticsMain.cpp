/**
 * WeatherStatisticsMain.cpp by Olivia Stone for Code Clinic: C++
 **/

#include <iostream>
#include <string>

#include "WeatherStatistics.hpp"

using namespace std;

int main() {
	
    WeatherStatistics stats;

	// request start date/time from user
    string startDate, startTime;
	cout << endl << "Enter START DATE as yyyy_mm_dd: ";
	cin >> startDate;
	cout << "Enter START TIME as hh:mm:ss (24-hour): ";
	cin >> startTime;

    if (!stats.isValidDateTime(startDate, startTime))
    {
        return 1;
    }

	// request end date/time from user
    string endDate, endTime;
	cout << "Enter END DATE as yyyy_mm_dd: ";
	cin >> endDate;
	cout << "Enter END TIME as hh:mm:ss (24-hour): ";
	cin >> endTime;

    if (!stats.isValidDateTime(endDate, endTime))
    {
        return 1;
    }

	double coeff = stats.computeCoeff(startDate, startTime, 
                                      endDate, endTime);

    cout << endl << "Coefficient: " << coeff * 24 * 60 * 60 << " inHg/day" << endl;

    // determine if it's sunny or stormy
    if (coeff < 0)
    {
        cout << "Stormy conditions... Looks like you might need an umbrella!" << endl;
    }
    else
    {
        cout << "Sunny conditions... Don't forget your sunscreen!" << endl;
    }

    return 0;
}