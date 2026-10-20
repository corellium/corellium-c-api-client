#ifndef device_TEST
#define device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/device.h"
device_t* instantiate_device(int include_optional);



device_t* instantiate_device(int include_optional) {
  device_t* device = NULL;
  if (include_optional) {
    device = device_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    device = device_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return device;
}


#ifdef device_MAIN

void test_device(int include_optional) {
    device_t* device_1 = instantiate_device(include_optional);

	cJSON* jsondevice_1 = device_convertToJSON(device_1);
	printf("device :\n%s\n", cJSON_Print(jsondevice_1));
	device_t* device_2 = device_parseFromJSON(jsondevice_1);
	cJSON* jsondevice_2 = device_convertToJSON(device_2);
	printf("repeating device:\n%s\n", cJSON_Print(jsondevice_2));
}

int main() {
  test_device(1);
  test_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // device_MAIN
#endif // device_TEST
