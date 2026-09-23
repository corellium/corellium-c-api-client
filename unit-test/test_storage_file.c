#ifndef storage_file_TEST
#define storage_file_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_file_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_file.h"
storage_file_t* instantiate_storage_file(int include_optional);



storage_file_t* instantiate_storage_file(int include_optional) {
  storage_file_t* storage_file = NULL;
  if (include_optional) {
    storage_file = storage_file_create(
      "firmware.ipsw",
      "ipsw",
      corellium_api_storage_file_TYPE_file,
      2147483648,
      "2026-03-17T11:41:05Z"
    );
  } else {
    storage_file = storage_file_create(
      "firmware.ipsw",
      "ipsw",
      corellium_api_storage_file_TYPE_file,
      2147483648,
      "2026-03-17T11:41:05Z"
    );
  }

  return storage_file;
}


#ifdef storage_file_MAIN

void test_storage_file(int include_optional) {
    storage_file_t* storage_file_1 = instantiate_storage_file(include_optional);

	cJSON* jsonstorage_file_1 = storage_file_convertToJSON(storage_file_1);
	printf("storage_file :\n%s\n", cJSON_Print(jsonstorage_file_1));
	storage_file_t* storage_file_2 = storage_file_parseFromJSON(jsonstorage_file_1);
	cJSON* jsonstorage_file_2 = storage_file_convertToJSON(storage_file_2);
	printf("repeating storage_file:\n%s\n", cJSON_Print(jsonstorage_file_2));
}

int main() {
  test_storage_file(1);
  test_storage_file(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_file_MAIN
#endif // storage_file_TEST
