/**
 * GeolocationRequest.hpp by Olivia Stone for Code Clinic: C++
 **/

#ifndef GEOLOCATIONREQUEST_H_
#define GEOLOCATIONREQUEST_H_

#include <iostream>
#include <cstring>
#include <string>

#include "cJSON.h"     // JSON support https://github.com/DaveGamble/cJSON
#include "curl\curl.h" // curl support https://curl.haxx.se/

#define GEO_API_BASE_URL "https://www.googleapis.com/geolocation/v1/geolocate?key="
#define GEO_API_KEY "AIzaSyBbzftXRb-82QIOH0T3_FUMif402VdVo-c" /* YOUR API KEY */
#define GEO_API_REQUEST_URL GEO_API_BASE_URL GEO_API_KEY

class GeolocationRequest
{
public:
	void getLocation(char *jsonPayload);
	void printLocationInfo(char *response);

private:
	struct MemoryStruct
	{
		char *memory;
		size_t size;
	};

	static size_t writeMemoryCallback(void *contents,
	                                  size_t size,
									  size_t nmemb,
									  void *userp);
};

#endif // GEOLOCATIONREQUEST_H_