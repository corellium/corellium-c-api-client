#ifndef device_usage_TEST
#define device_usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define device_usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/device_usage.h"
device_usage_t* instantiate_device_usage(int include_optional);



device_usage_t* instantiate_device_usage(int include_optional) {
  device_usage_t* device_usage = NULL;
  if (include_optional) {
    device_usage = device_usage_create(
      1.337,
      1.337
    );
  } else {
    device_usage = device_usage_create(
      1.337,
      1.337
    );
  }

  return device_usage;
}


#ifdef device_usage_MAIN

void test_device_usage(int include_optional) {
    device_usage_t* device_usage_1 = instantiate_device_usage(include_optional);

	cJSON* jsondevice_usage_1 = device_usage_convertToJSON(device_usage_1);
	printf("device_usage :\n%s\n", cJSON_Print(jsondevice_usage_1));
	device_usage_t* device_usage_2 = device_usage_parseFromJSON(jsondevice_usage_1);
	cJSON* jsondevice_usage_2 = device_usage_convertToJSON(device_usage_2);
	printf("repeating device_usage:\n%s\n", cJSON_Print(jsondevice_usage_2));
}

int main() {
  test_device_usage(1);
  test_device_usage(0);

  printf("Hello world \n");
  return 0;
}

#endif // device_usage_MAIN
#endif // device_usage_TEST
