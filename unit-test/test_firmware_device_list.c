#ifndef firmware_device_list_TEST
#define firmware_device_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_device_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_device_list.h"
firmware_device_list_t* instantiate_firmware_device_list(int include_optional);



firmware_device_list_t* instantiate_firmware_device_list(int include_optional) {
  firmware_device_list_t* firmware_device_list = NULL;
  if (include_optional) {
    firmware_device_list = firmware_device_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    firmware_device_list = firmware_device_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return firmware_device_list;
}


#ifdef firmware_device_list_MAIN

void test_firmware_device_list(int include_optional) {
    firmware_device_list_t* firmware_device_list_1 = instantiate_firmware_device_list(include_optional);

	cJSON* jsonfirmware_device_list_1 = firmware_device_list_convertToJSON(firmware_device_list_1);
	printf("firmware_device_list :\n%s\n", cJSON_Print(jsonfirmware_device_list_1));
	firmware_device_list_t* firmware_device_list_2 = firmware_device_list_parseFromJSON(jsonfirmware_device_list_1);
	cJSON* jsonfirmware_device_list_2 = firmware_device_list_convertToJSON(firmware_device_list_2);
	printf("repeating firmware_device_list:\n%s\n", cJSON_Print(jsonfirmware_device_list_2));
}

int main() {
  test_firmware_device_list(1);
  test_firmware_device_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_device_list_MAIN
#endif // firmware_device_list_TEST
