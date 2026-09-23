#ifndef firmware_service_config_cache_firmware_TEST
#define firmware_service_config_cache_firmware_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_service_config_cache_firmware_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_service_config_cache_firmware.h"
firmware_service_config_cache_firmware_t* instantiate_firmware_service_config_cache_firmware(int include_optional);



firmware_service_config_cache_firmware_t* instantiate_firmware_service_config_cache_firmware(int include_optional) {
  firmware_service_config_cache_firmware_t* firmware_service_config_cache_firmware = NULL;
  if (include_optional) {
    firmware_service_config_cache_firmware = firmware_service_config_cache_firmware_create(
      true,
      "checkbox",
      "Cache firmware",
      "Cache firmwares in /var/ipsw",
      "boolean"
    );
  } else {
    firmware_service_config_cache_firmware = firmware_service_config_cache_firmware_create(
      true,
      "checkbox",
      "Cache firmware",
      "Cache firmwares in /var/ipsw",
      "boolean"
    );
  }

  return firmware_service_config_cache_firmware;
}


#ifdef firmware_service_config_cache_firmware_MAIN

void test_firmware_service_config_cache_firmware(int include_optional) {
    firmware_service_config_cache_firmware_t* firmware_service_config_cache_firmware_1 = instantiate_firmware_service_config_cache_firmware(include_optional);

	cJSON* jsonfirmware_service_config_cache_firmware_1 = firmware_service_config_cache_firmware_convertToJSON(firmware_service_config_cache_firmware_1);
	printf("firmware_service_config_cache_firmware :\n%s\n", cJSON_Print(jsonfirmware_service_config_cache_firmware_1));
	firmware_service_config_cache_firmware_t* firmware_service_config_cache_firmware_2 = firmware_service_config_cache_firmware_parseFromJSON(jsonfirmware_service_config_cache_firmware_1);
	cJSON* jsonfirmware_service_config_cache_firmware_2 = firmware_service_config_cache_firmware_convertToJSON(firmware_service_config_cache_firmware_2);
	printf("repeating firmware_service_config_cache_firmware:\n%s\n", cJSON_Print(jsonfirmware_service_config_cache_firmware_2));
}

int main() {
  test_firmware_service_config_cache_firmware(1);
  test_firmware_service_config_cache_firmware(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_service_config_cache_firmware_MAIN
#endif // firmware_service_config_cache_firmware_TEST
