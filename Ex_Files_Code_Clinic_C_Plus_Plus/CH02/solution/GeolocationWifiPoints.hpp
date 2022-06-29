/**
 * GeolocationWifiPoints.hpp by Olivia Stone for Code Clinic: C++
 **/

#ifndef GEOLOCATIONWIFIPOINTS_H_
#define GEOLOCATIONWIFIPOINTS_H_

#include <iostream>
#include <string>
#include <list>

#include <windows.h>
#include <wlanapi.h>

#include "cJSON.h" // JSON support https://github.com/DaveGamble/cJSON

class GeolocationWifiPoints
{
public:
	int getWifiNetworks();
	char* buildRequestJSON();

private:
	struct wifiAP {
		char macAddress[44];
		long signalStrength;
	};

	std::list<wifiAP> wifiAPlist_;
};

#endif // GEOLOCATIONWIFIPOINTS_H_