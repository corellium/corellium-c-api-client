#ifndef storage_list_TEST
#define storage_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_list.h"
storage_list_t* instantiate_storage_list(int include_optional);



storage_list_t* instantiate_storage_list(int include_optional) {
  storage_list_t* storage_list = NULL;
  if (include_optional) {
    storage_list = storage_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    storage_list = storage_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return storage_list;
}


#ifdef storage_list_MAIN

void test_storage_list(int include_optional) {
    storage_list_t* storage_list_1 = instantiate_storage_list(include_optional);

	cJSON* jsonstorage_list_1 = storage_list_convertToJSON(storage_list_1);
	printf("storage_list :\n%s\n", cJSON_Print(jsonstorage_list_1));
	storage_list_t* storage_list_2 = storage_list_parseFromJSON(jsonstorage_list_1);
	cJSON* jsonstorage_list_2 = storage_list_convertToJSON(storage_list_2);
	printf("repeating storage_list:\n%s\n", cJSON_Print(jsonstorage_list_2));
}

int main() {
  test_storage_list(1);
  test_storage_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_list_MAIN
#endif // storage_list_TEST
