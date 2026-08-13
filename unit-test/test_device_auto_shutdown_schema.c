#ifndef device_auto_shutdown_schema_TEST
#define device_auto_shutdown_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define device_auto_shutdown_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/device_auto_shutdown_schema.h"
device_auto_shutdown_schema_t* instantiate_device_auto_shutdown_schema(int include_optional);



device_auto_shutdown_schema_t* instantiate_device_auto_shutdown_schema(int include_optional) {
  device_auto_shutdown_schema_t* device_auto_shutdown_schema = NULL;
  if (include_optional) {
    device_auto_shutdown_schema = device_auto_shutdown_schema_create(
      1,
      0
    );
  } else {
    device_auto_shutdown_schema = device_auto_shutdown_schema_create(
      1,
      0
    );
  }

  return device_auto_shutdown_schema;
}


#ifdef device_auto_shutdown_schema_MAIN

void test_device_auto_shutdown_schema(int include_optional) {
    device_auto_shutdown_schema_t* device_auto_shutdown_schema_1 = instantiate_device_auto_shutdown_schema(include_optional);

	cJSON* jsondevice_auto_shutdown_schema_1 = device_auto_shutdown_schema_convertToJSON(device_auto_shutdown_schema_1);
	printf("device_auto_shutdown_schema :\n%s\n", cJSON_Print(jsondevice_auto_shutdown_schema_1));
	device_auto_shutdown_schema_t* device_auto_shutdown_schema_2 = device_auto_shutdown_schema_parseFromJSON(jsondevice_auto_shutdown_schema_1);
	cJSON* jsondevice_auto_shutdown_schema_2 = device_auto_shutdown_schema_convertToJSON(device_auto_shutdown_schema_2);
	printf("repeating device_auto_shutdown_schema:\n%s\n", cJSON_Print(jsondevice_auto_shutdown_schema_2));
}

int main() {
  test_device_auto_shutdown_schema(1);
  test_device_auto_shutdown_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // device_auto_shutdown_schema_MAIN
#endif // device_auto_shutdown_schema_TEST
