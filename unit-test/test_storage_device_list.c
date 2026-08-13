#ifndef storage_device_list_TEST
#define storage_device_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_device_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_device_list.h"
storage_device_list_t* instantiate_storage_device_list(int include_optional);



storage_device_list_t* instantiate_storage_device_list(int include_optional) {
  storage_device_list_t* storage_device_list = NULL;
  if (include_optional) {
    storage_device_list = storage_device_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    storage_device_list = storage_device_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return storage_device_list;
}


#ifdef storage_device_list_MAIN

void test_storage_device_list(int include_optional) {
    storage_device_list_t* storage_device_list_1 = instantiate_storage_device_list(include_optional);

	cJSON* jsonstorage_device_list_1 = storage_device_list_convertToJSON(storage_device_list_1);
	printf("storage_device_list :\n%s\n", cJSON_Print(jsonstorage_device_list_1));
	storage_device_list_t* storage_device_list_2 = storage_device_list_parseFromJSON(jsonstorage_device_list_1);
	cJSON* jsonstorage_device_list_2 = storage_device_list_convertToJSON(storage_device_list_2);
	printf("repeating storage_device_list:\n%s\n", cJSON_Print(jsonstorage_device_list_2));
}

int main() {
  test_storage_device_list(1);
  test_storage_device_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_device_list_MAIN
#endif // storage_device_list_TEST
