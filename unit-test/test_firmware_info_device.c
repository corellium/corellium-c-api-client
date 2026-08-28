#ifndef firmware_info_device_TEST
#define firmware_info_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_info_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_info_device.h"
firmware_info_device_t* instantiate_firmware_info_device(int include_optional);



firmware_info_device_t* instantiate_firmware_info_device(int include_optional) {
  firmware_info_device_t* firmware_info_device = NULL;
  if (include_optional) {
    firmware_info_device = firmware_info_device_create(
      "0",
      list_createList()
    );
  } else {
    firmware_info_device = firmware_info_device_create(
      "0",
      list_createList()
    );
  }

  return firmware_info_device;
}


#ifdef firmware_info_device_MAIN

void test_firmware_info_device(int include_optional) {
    firmware_info_device_t* firmware_info_device_1 = instantiate_firmware_info_device(include_optional);

	cJSON* jsonfirmware_info_device_1 = firmware_info_device_convertToJSON(firmware_info_device_1);
	printf("firmware_info_device :\n%s\n", cJSON_Print(jsonfirmware_info_device_1));
	firmware_info_device_t* firmware_info_device_2 = firmware_info_device_parseFromJSON(jsonfirmware_info_device_1);
	cJSON* jsonfirmware_info_device_2 = firmware_info_device_convertToJSON(firmware_info_device_2);
	printf("repeating firmware_info_device:\n%s\n", cJSON_Print(jsonfirmware_info_device_2));
}

int main() {
  test_firmware_info_device(1);
  test_firmware_info_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_info_device_MAIN
#endif // firmware_info_device_TEST
