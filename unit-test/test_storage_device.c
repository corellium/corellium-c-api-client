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
      "73357171-23a0-4a3e-8661-216dbfbdd7ab",
      "/dev/sdb1",
      "ext4",
      "4a3f2e1d-8c7b-4a19-9e2f-6d5c4b3a2190",
      "EXTERNAL_SSD",
      "0123456789ABCDEF",
      "SanDisk",
      "Ultra USB 3.0",
      corellium_api_storage_device_MOUNTPOLICY_RO,
      corellium_api_storage_device_STATUS_mounted,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    storage_device = storage_device_create(
      "73357171-23a0-4a3e-8661-216dbfbdd7ab",
      "/dev/sdb1",
      "ext4",
      "4a3f2e1d-8c7b-4a19-9e2f-6d5c4b3a2190",
      "EXTERNAL_SSD",
      "0123456789ABCDEF",
      "SanDisk",
      "Ultra USB 3.0",
      corellium_api_storage_device_MOUNTPOLICY_RO,
      corellium_api_storage_device_STATUS_mounted,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
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
