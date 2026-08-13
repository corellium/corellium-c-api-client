#ifndef storage_queue_error_TEST
#define storage_queue_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_queue_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_queue_error.h"
storage_queue_error_t* instantiate_storage_queue_error(int include_optional);



storage_queue_error_t* instantiate_storage_queue_error(int include_optional) {
  storage_queue_error_t* storage_queue_error = NULL;
  if (include_optional) {
    storage_queue_error = storage_queue_error_create(
      "0",
      "0",
      "0"
    );
  } else {
    storage_queue_error = storage_queue_error_create(
      "0",
      "0",
      "0"
    );
  }

  return storage_queue_error;
}


#ifdef storage_queue_error_MAIN

void test_storage_queue_error(int include_optional) {
    storage_queue_error_t* storage_queue_error_1 = instantiate_storage_queue_error(include_optional);

	cJSON* jsonstorage_queue_error_1 = storage_queue_error_convertToJSON(storage_queue_error_1);
	printf("storage_queue_error :\n%s\n", cJSON_Print(jsonstorage_queue_error_1));
	storage_queue_error_t* storage_queue_error_2 = storage_queue_error_parseFromJSON(jsonstorage_queue_error_1);
	cJSON* jsonstorage_queue_error_2 = storage_queue_error_convertToJSON(storage_queue_error_2);
	printf("repeating storage_queue_error:\n%s\n", cJSON_Print(jsonstorage_queue_error_2));
}

int main() {
  test_storage_queue_error(1);
  test_storage_queue_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_queue_error_MAIN
#endif // storage_queue_error_TEST
