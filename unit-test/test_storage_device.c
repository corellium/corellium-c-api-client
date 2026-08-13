#ifndef storage_device_TEST
#define storage_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_device.h"
storage_device_t* instantiate_storage_device(int include_optional);



storage_device_t* instantiate_storage_device(int include_optional) {
  storage_device_t* storage_device = NULL;
  if (include_optional) {
    storage_device = storage_device_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      corellium_api_storage_device_MOUNTPOLICY_RO,
      corellium_api_storage_device_STATUS_mounted,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    storage_device = storage_device_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      corellium_api_storage_device_MOUNTPOLICY_RO,
      corellium_api_storage_device_STATUS_mounted,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return storage_device;
}


#ifdef storage_device_MAIN

void test_storage_device(int include_optional) {
    storage_device_t* storage_device_1 = instantiate_storage_device(include_optional);

	cJSON* jsonstorage_device_1 = storage_device_convertToJSON(storage_device_1);
	printf("storage_device :\n%s\n", cJSON_Print(jsonstorage_device_1));
	storage_device_t* storage_device_2 = storage_device_parseFromJSON(jsonstorage_device_1);
	cJSON* jsonstorage_device_2 = storage_device_convertToJSON(storage_device_2);
	printf("repeating storage_device:\n%s\n", cJSON_Print(jsonstorage_device_2));
}

int main() {
  test_storage_device(1);
  test_storage_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_device_MAIN
#endif // storage_device_TEST
