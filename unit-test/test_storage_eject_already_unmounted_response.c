#ifndef storage_eject_already_unmounted_response_TEST
#define storage_eject_already_unmounted_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_eject_already_unmounted_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_eject_already_unmounted_response.h"
storage_eject_already_unmounted_response_t* instantiate_storage_eject_already_unmounted_response(int include_optional);



storage_eject_already_unmounted_response_t* instantiate_storage_eject_already_unmounted_response(int include_optional) {
  storage_eject_already_unmounted_response_t* storage_eject_already_unmounted_response = NULL;
  if (include_optional) {
    storage_eject_already_unmounted_response = storage_eject_already_unmounted_response_create(
      "Device is already unmounted."
    );
  } else {
    storage_eject_already_unmounted_response = storage_eject_already_unmounted_response_create(
      "Device is already unmounted."
    );
  }

  return storage_eject_already_unmounted_response;
}


#ifdef storage_eject_already_unmounted_response_MAIN

void test_storage_eject_already_unmounted_response(int include_optional) {
    storage_eject_already_unmounted_response_t* storage_eject_already_unmounted_response_1 = instantiate_storage_eject_already_unmounted_response(include_optional);

	cJSON* jsonstorage_eject_already_unmounted_response_1 = storage_eject_already_unmounted_response_convertToJSON(storage_eject_already_unmounted_response_1);
	printf("storage_eject_already_unmounted_response :\n%s\n", cJSON_Print(jsonstorage_eject_already_unmounted_response_1));
	storage_eject_already_unmounted_response_t* storage_eject_already_unmounted_response_2 = storage_eject_already_unmounted_response_parseFromJSON(jsonstorage_eject_already_unmounted_response_1);
	cJSON* jsonstorage_eject_already_unmounted_response_2 = storage_eject_already_unmounted_response_convertToJSON(storage_eject_already_unmounted_response_2);
	printf("repeating storage_eject_already_unmounted_response:\n%s\n", cJSON_Print(jsonstorage_eject_already_unmounted_response_2));
}

int main() {
  test_storage_eject_already_unmounted_response(1);
  test_storage_eject_already_unmounted_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_eject_already_unmounted_response_MAIN
#endif // storage_eject_already_unmounted_response_TEST
