/**
 * GeolocationWifiPoints.cpp by Olivia Stone for Code Clinic: C++
 **/

#include "GeolocationWifiPoints.hpp"

using namespace std;

int GeolocationWifiPoints::getWifiNetworks()
{
	// initialize variables
	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2; 
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwBResult = 0;
	DWORD dwRetVal = 0;
	wifiAP accessPoint{ "00:00:00:00:00:00", 0 };

	// variables used for WlanEnumInterfaces
	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;
	PWLAN_BSS_LIST pBssList = NULL;
	PWLAN_BSS_ENTRY pBssEntry = NULL;

	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) 
	{
		cerr << "ERROR: WlanOpenHandle failed with error: " << dwResult << endl;
		return 1;
	}

	dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwResult != ERROR_SUCCESS) 
	{
		cerr << "ERROR: WlanEnumInterfaces failed with error: " << dwResult << endl;
		return 1;
	}
	else 
	{
		for (int i = 0; i < (int)pIfList->dwNumberOfItems; i++)
		{
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];

			//Get Network Bss List
			dwBResult = WlanGetNetworkBssList(hClient,
												&pIfInfo->InterfaceGuid,
												NULL,
												dot11_BSS_type_any,
												0,
												0,
												&pBssList);

			if (dwBResult != ERROR_SUCCESS)
			{
				cerr << "ERROR: WlanGetBssList failed with error: " << dwBResult << endl;
				dwRetVal = 1;
			}
			else 
			{
				cout << endl << "Found " << pBssList->dwNumberOfItems << " access points" << endl;

				for (int k = 0; k < pBssList->dwNumberOfItems; k++)
				{
					pBssEntry =
						(WLAN_BSS_ENTRY *)& pBssList->wlanBssEntries[k];

					sprintf(accessPoint.macAddress,
							"%02X:%02X:%02X:%02X:%02X:%02X",
							pBssEntry->dot11Bssid[0],
							pBssEntry->dot11Bssid[1], 
							pBssEntry->dot11Bssid[2],
							pBssEntry->dot11Bssid[3],
							pBssEntry->dot11Bssid[4],
							pBssEntry->dot11Bssid[5]);

					accessPoint.signalStrength = pBssEntry->lRssi;
					wifiAPlist_.push_back(accessPoint);
				}
			}	
		}
	}

	return dwRetVal;
}

char* GeolocationWifiPoints::buildRequestJSON()
{
	cJSON *wifiAccessPoints = NULL;
	char *outputJSON = NULL;

	// create JSON object for considerIp
	cJSON *locationRequest = cJSON_CreateObject();
	if (cJSON_AddStringToObject(locationRequest, "considerIp", "true") == NULL)
	{
		goto end;
	}

	// create JSON object for wifiAccessPoints
	wifiAccessPoints = cJSON_AddArrayToObject(locationRequest, "wifiAccessPoints");
	if (wifiAccessPoints == NULL)
	{
		goto end;
	}

	// build JSON Request for each wifi point
	for (list<wifiAP>::iterator i = wifiAPlist_.begin(); i != wifiAPlist_.end(); ++i)
	{
		cJSON *accessPoint = cJSON_CreateObject();
		if (cJSON_AddStringToObject(accessPoint, "macAddress", i->macAddress) == NULL)
		{
			goto end;
		}

		if (cJSON_AddNumberToObject(accessPoint, "signalStrength", i->signalStrength) == NULL)
		{
			goto end;
		}

		cJSON_AddItemToArray(wifiAccessPoints, accessPoint);

		outputJSON = cJSON_Print(locationRequest);
		if (outputJSON == NULL)
		{
			cerr << "ERROR: Failed to print JSON for the wifi access points" << endl;
		}
	}

end:
	cJSON_Delete(locationRequest);

	return outputJSON;
}