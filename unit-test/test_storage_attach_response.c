#ifndef storage_attach_response_TEST
#define storage_attach_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_attach_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_attach_response.h"
storage_attach_response_t* instantiate_storage_attach_response(int include_optional);



storage_attach_response_t* instantiate_storage_attach_response(int include_optional) {
  storage_attach_response_t* storage_attach_response = NULL;
  if (include_optional) {
    storage_attach_response = storage_attach_response_create(
      "0",
      "0",
      "0"
    );
  } else {
    storage_attach_response = storage_attach_response_create(
      "0",
      "0",
      "0"
    );
  }

  return storage_attach_response;
}


#ifdef storage_attach_response_MAIN

void test_storage_attach_response(int include_optional) {
    storage_attach_response_t* storage_attach_response_1 = instantiate_storage_attach_response(include_optional);

	cJSON* jsonstorage_attach_response_1 = storage_attach_response_convertToJSON(storage_attach_response_1);
	printf("storage_attach_response :\n%s\n", cJSON_Print(jsonstorage_attach_response_1));
	storage_attach_response_t* storage_attach_response_2 = storage_attach_response_parseFromJSON(jsonstorage_attach_response_1);
	cJSON* jsonstorage_attach_response_2 = storage_attach_response_convertToJSON(storage_attach_response_2);
	printf("repeating storage_attach_response:\n%s\n", cJSON_Print(jsonstorage_attach_response_2));
}

int main() {
  test_storage_attach_response(1);
  test_storage_attach_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_attach_response_MAIN
#endif // storage_attach_response_TEST
