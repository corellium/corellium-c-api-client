#ifndef firmware_device_TEST
#define firmware_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_device.h"
firmware_device_t* instantiate_firmware_device(int include_optional);



firmware_device_t* instantiate_firmware_device(int include_optional) {
  firmware_device_t* firmware_device = NULL;
  if (include_optional) {
    firmware_device = firmware_device_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    firmware_device = firmware_device_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return firmware_device;
}


#ifdef firmware_device_MAIN

void test_firmware_device(int include_optional) {
    firmware_device_t* firmware_device_1 = instantiate_firmware_device(include_optional);

	cJSON* jsonfirmware_device_1 = firmware_device_convertToJSON(firmware_device_1);
	printf("firmware_device :\n%s\n", cJSON_Print(jsonfirmware_device_1));
	firmware_device_t* firmware_device_2 = firmware_device_parseFromJSON(jsonfirmware_device_1);
	cJSON* jsonfirmware_device_2 = firmware_device_convertToJSON(firmware_device_2);
	printf("repeating firmware_device:\n%s\n", cJSON_Print(jsonfirmware_device_2));
}

int main() {
  test_firmware_device(1);
  test_firmware_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_device_MAIN
#endif // firmware_device_TEST
