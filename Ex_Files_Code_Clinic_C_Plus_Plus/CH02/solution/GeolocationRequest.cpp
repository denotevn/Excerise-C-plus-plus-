/**
 * GeolocationRequest.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "GeolocationRequest.hpp"

using namespace std;

void GeolocationRequest::getLocation(char *jsonPayload)
{
	// initialize curl 
	curl_global_init(CURL_GLOBAL_ALL);
	CURL *curl = curl_easy_init();

	// sumbit POST request to Google Geolocation API
	if (curl) 
	{
		// set content type 
		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, "Accept: application/json");
		headers = curl_slist_append(headers, "Content-Type: application/json");
		
		// memory to store POST response 
		struct MemoryStruct chunk;
		chunk.memory = NULL;
		chunk.size = 0; // memory will be grown as needed by writeMemoryCallback() function

		// set curl options 
		curl_easy_setopt(curl, CURLOPT_URL, GEO_API_REQUEST_URL);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback); // send all data to this function
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk); // pass 'chunk' struct to callback

		// Perform the request, res will get the return code 
		CURLcode res = curl_easy_perform(curl);
		if (res != CURLE_OK) 
		{
			cerr << "ERROR: curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
		}
		else 
		{
			// chunk.memory points to a memory block that is chunk.size bytes big and contains the response
			printLocationInfo(chunk.memory);
		}

		// cleanup libcurl
		curl_easy_cleanup(curl);
		curl_global_cleanup();
		free(chunk.memory);
	}
	else
	{
		cerr << "ERROR: curl_easy_init() failed" << endl;
	}
}

void GeolocationRequest::printLocationInfo(char *response) 
{
	const cJSON *location = NULL;
	const cJSON *latitude = NULL;
	const cJSON *longitude = NULL;
	const cJSON *accuracy = NULL;

	cJSON *parsedJSON = cJSON_Parse(response);
	if (parsedJSON == NULL) 
	{
		const char *errorPtr = cJSON_GetErrorPtr();
		if (errorPtr != NULL) 
		{
			cerr << "ERROR: cJSON_GetErrorPty returned: " << errorPtr << endl;
		}
		goto end;
	}

	location = cJSON_GetObjectItemCaseSensitive(parsedJSON, "location");
	if (location == NULL)
	{
		goto end;
	}

	latitude = cJSON_GetObjectItemCaseSensitive(location, "lat");
	longitude = cJSON_GetObjectItemCaseSensitive(location, "lng");
	accuracy = cJSON_GetObjectItemCaseSensitive(parsedJSON, "accuracy");
	if ((latitude != NULL) && (longitude != NULL) && (accuracy != NULL))
	{
		cout << endl << "You are within " << cJSON_Print(accuracy) << "m of "
		                                  << cJSON_Print(latitude) << "N "
								          << cJSON_Print(longitude) << "E" << endl;
	}

end:
	cJSON_Delete(parsedJSON);
}

/* memory callback to capture response from curl POST request */
size_t GeolocationRequest::writeMemoryCallback(void *contents, size_t size, size_t nmemb, void* userp) 
{
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	char *ptr = (char *)realloc(mem->memory, mem->size + realsize + 1);
	if (!ptr) {
		cerr << "ERROR: writeMemoryCallback failed to allocate memory" << endl;
		return 0;
	}

	mem->memory = ptr;
	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}