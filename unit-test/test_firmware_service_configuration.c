#ifndef firmware_service_configuration_TEST
#define firmware_service_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_service_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_service_configuration.h"
firmware_service_configuration_t* instantiate_firmware_service_configuration(int include_optional);



firmware_service_configuration_t* instantiate_firmware_service_configuration(int include_optional) {
  firmware_service_configuration_t* firmware_service_configuration = NULL;
  if (include_optional) {
    firmware_service_configuration = firmware_service_configuration_create(
      1,
      1,
      1,
      1,
      1,
      list_createList()
    );
  } else {
    firmware_service_configuration = firmware_service_configuration_create(
      1,
      1,
      1,
      1,
      1,
      list_createList()
    );
  }

  return firmware_service_configuration;
}


#ifdef firmware_service_configuration_MAIN

void test_firmware_service_configuration(int include_optional) {
    firmware_service_configuration_t* firmware_service_configuration_1 = instantiate_firmware_service_configuration(include_optional);

	cJSON* jsonfirmware_service_configuration_1 = firmware_service_configuration_convertToJSON(firmware_service_configuration_1);
	printf("firmware_service_configuration :\n%s\n", cJSON_Print(jsonfirmware_service_configuration_1));
	firmware_service_configuration_t* firmware_service_configuration_2 = firmware_service_configuration_parseFromJSON(jsonfirmware_service_configuration_1);
	cJSON* jsonfirmware_service_configuration_2 = firmware_service_configuration_convertToJSON(firmware_service_configuration_2);
	printf("repeating firmware_service_configuration:\n%s\n", cJSON_Print(jsonfirmware_service_configuration_2));
}

int main() {
  test_firmware_service_configuration(1);
  test_firmware_service_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_service_configuration_MAIN
#endif // firmware_service_configuration_TEST
