#ifndef storage_already_mounted_response_TEST
#define storage_already_mounted_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_already_mounted_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_already_mounted_response.h"
storage_already_mounted_response_t* instantiate_storage_already_mounted_response(int include_optional);



storage_already_mounted_response_t* instantiate_storage_already_mounted_response(int include_optional) {
  storage_already_mounted_response_t* storage_already_mounted_response = NULL;
  if (include_optional) {
    storage_already_mounted_response = storage_already_mounted_response_create(
      "0",
      "0",
      "0"
    );
  } else {
    storage_already_mounted_response = storage_already_mounted_response_create(
      "0",
      "0",
      "0"
    );
  }

  return storage_already_mounted_response;
}


#ifdef storage_already_mounted_response_MAIN

void test_storage_already_mounted_response(int include_optional) {
    storage_already_mounted_response_t* storage_already_mounted_response_1 = instantiate_storage_already_mounted_response(include_optional);

	cJSON* jsonstorage_already_mounted_response_1 = storage_already_mounted_response_convertToJSON(storage_already_mounted_response_1);
	printf("storage_already_mounted_response :\n%s\n", cJSON_Print(jsonstorage_already_mounted_response_1));
	storage_already_mounted_response_t* storage_already_mounted_response_2 = storage_already_mounted_response_parseFromJSON(jsonstorage_already_mounted_response_1);
	cJSON* jsonstorage_already_mounted_response_2 = storage_already_mounted_response_convertToJSON(storage_already_mounted_response_2);
	printf("repeating storage_already_mounted_response:\n%s\n", cJSON_Print(jsonstorage_already_mounted_response_2));
}

int main() {
  test_storage_already_mounted_response(1);
  test_storage_already_mounted_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_already_mounted_response_MAIN
#endif // storage_already_mounted_response_TEST
