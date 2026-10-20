#ifndef firmware_service_config_download_ipsw_filters_TEST
#define firmware_service_config_download_ipsw_filters_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_service_config_download_ipsw_filters_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_service_config_download_ipsw_filters.h"
firmware_service_config_download_ipsw_filters_t* instantiate_firmware_service_config_download_ipsw_filters(int include_optional);



firmware_service_config_download_ipsw_filters_t* instantiate_firmware_service_config_download_ipsw_filters(int include_optional) {
  firmware_service_config_download_ipsw_filters_t* firmware_service_config_download_ipsw_filters = NULL;
  if (include_optional) {
    firmware_service_config_download_ipsw_filters = firmware_service_config_download_ipsw_filters_create(
      list_createList(),
      "checkbox",
      "Cache firmware",
      "Cache firmwares in /var/ipsw",
      "boolean"
    );
  } else {
    firmware_service_config_download_ipsw_filters = firmware_service_config_download_ipsw_filters_create(
      list_createList(),
      "checkbox",
      "Cache firmware",
      "Cache firmwares in /var/ipsw",
      "boolean"
    );
  }

  return firmware_service_config_download_ipsw_filters;
}


#ifdef firmware_service_config_download_ipsw_filters_MAIN

void test_firmware_service_config_download_ipsw_filters(int include_optional) {
    firmware_service_config_download_ipsw_filters_t* firmware_service_config_download_ipsw_filters_1 = instantiate_firmware_service_config_download_ipsw_filters(include_optional);

	cJSON* jsonfirmware_service_config_download_ipsw_filters_1 = firmware_service_config_download_ipsw_filters_convertToJSON(firmware_service_config_download_ipsw_filters_1);
	printf("firmware_service_config_download_ipsw_filters :\n%s\n", cJSON_Print(jsonfirmware_service_config_download_ipsw_filters_1));
	firmware_service_config_download_ipsw_filters_t* firmware_service_config_download_ipsw_filters_2 = firmware_service_config_download_ipsw_filters_parseFromJSON(jsonfirmware_service_config_download_ipsw_filters_1);
	cJSON* jsonfirmware_service_config_download_ipsw_filters_2 = firmware_service_config_download_ipsw_filters_convertToJSON(firmware_service_config_download_ipsw_filters_2);
	printf("repeating firmware_service_config_download_ipsw_filters:\n%s\n", cJSON_Print(jsonfirmware_service_config_download_ipsw_filters_2));
}

int main() {
  test_firmware_service_config_download_ipsw_filters(1);
  test_firmware_service_config_download_ipsw_filters(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_service_config_download_ipsw_filters_MAIN
#endif // firmware_service_config_download_ipsw_filters_TEST
