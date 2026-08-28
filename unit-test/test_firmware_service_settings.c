#ifndef firmware_service_settings_TEST
#define firmware_service_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_service_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_service_settings.h"
firmware_service_settings_t* instantiate_firmware_service_settings(int include_optional);



firmware_service_settings_t* instantiate_firmware_service_settings(int include_optional) {
  firmware_service_settings_t* firmware_service_settings = NULL;
  if (include_optional) {
    firmware_service_settings = firmware_service_settings_create(
      1,
      1,
      1,
      1,
      1,
      list_createList()
    );
  } else {
    firmware_service_settings = firmware_service_settings_create(
      1,
      1,
      1,
      1,
      1,
      list_createList()
    );
  }

  return firmware_service_settings;
}


#ifdef firmware_service_settings_MAIN

void test_firmware_service_settings(int include_optional) {
    firmware_service_settings_t* firmware_service_settings_1 = instantiate_firmware_service_settings(include_optional);

	cJSON* jsonfirmware_service_settings_1 = firmware_service_settings_convertToJSON(firmware_service_settings_1);
	printf("firmware_service_settings :\n%s\n", cJSON_Print(jsonfirmware_service_settings_1));
	firmware_service_settings_t* firmware_service_settings_2 = firmware_service_settings_parseFromJSON(jsonfirmware_service_settings_1);
	cJSON* jsonfirmware_service_settings_2 = firmware_service_settings_convertToJSON(firmware_service_settings_2);
	printf("repeating firmware_service_settings:\n%s\n", cJSON_Print(jsonfirmware_service_settings_2));
}

int main() {
  test_firmware_service_settings(1);
  test_firmware_service_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_service_settings_MAIN
#endif // firmware_service_settings_TEST
