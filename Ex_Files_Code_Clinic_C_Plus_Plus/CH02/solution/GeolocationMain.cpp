/**
 * GeolocationMain.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "GeolocationRequest.hpp"
#include "GeolocationWifiPoints.hpp"

int main()
{
	// find wifi access points
	GeolocationWifiPoints wifiAccess;
	wifiAccess.getWifiNetworks();
	char * jsonPayload = wifiAccess.buildRequestJSON();

	// request and display location info
	GeolocationRequest request;
	request.getLocation(jsonPayload);

	return 0;
}