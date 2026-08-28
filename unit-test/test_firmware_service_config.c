#ifndef firmware_service_config_TEST
#define firmware_service_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_service_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_service_config.h"
firmware_service_config_t* instantiate_firmware_service_config(int include_optional);

#include "test_firmware_service_config_cache_firmware.c"
#include "test_firmware_service_config_cache_firmware.c"
#include "test_firmware_service_config_cache_firmware.c"
#include "test_firmware_service_config_cache_firmware.c"
#include "test_firmware_service_config_cache_firmware.c"
#include "test_firmware_service_config_download_ipsw_filters.c"


firmware_service_config_t* instantiate_firmware_service_config(int include_optional) {
  firmware_service_config_t* firmware_service_config = NULL;
  if (include_optional) {
    firmware_service_config = firmware_service_config_create(
       // false, not to have infinite recursion
      instantiate_firmware_service_config_cache_firmware(0),
       // false, not to have infinite recursion
      instantiate_firmware_service_config_cache_firmware(0),
       // false, not to have infinite recursion
      instantiate_firmware_service_config_cache_firmware(0),
       // false, not to have infinite recursion
      instantiate_firmware_service_config_cache_firmware(0),
       // false, not to have infinite recursion
      instantiate_firmware_service_config_cache_firmware(0),
       // false, not to have infinite recursion
      instantiate_firmware_service_config_download_ipsw_filters(0)
    );
  } else {
    firmware_service_config = firmware_service_config_create(
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return firmware_service_config;
}


#ifdef firmware_service_config_MAIN

void test_firmware_service_config(int include_optional) {
    firmware_service_config_t* firmware_service_config_1 = instantiate_firmware_service_config(include_optional);

	cJSON* jsonfirmware_service_config_1 = firmware_service_config_convertToJSON(firmware_service_config_1);
	printf("firmware_service_config :\n%s\n", cJSON_Print(jsonfirmware_service_config_1));
	firmware_service_config_t* firmware_service_config_2 = firmware_service_config_parseFromJSON(jsonfirmware_service_config_1);
	cJSON* jsonfirmware_service_config_2 = firmware_service_config_convertToJSON(firmware_service_config_2);
	printf("repeating firmware_service_config:\n%s\n", cJSON_Print(jsonfirmware_service_config_2));
}

int main() {
  test_firmware_service_config(1);
  test_firmware_service_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_service_config_MAIN
#endif // firmware_service_config_TEST
