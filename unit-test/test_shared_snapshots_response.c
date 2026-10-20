#ifndef shared_snapshots_response_TEST
#define shared_snapshots_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shared_snapshots_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shared_snapshots_response.h"
shared_snapshots_response_t* instantiate_shared_snapshots_response(int include_optional);



shared_snapshots_response_t* instantiate_shared_snapshots_response(int include_optional) {
  shared_snapshots_response_t* shared_snapshots_response = NULL;
  if (include_optional) {
    shared_snapshots_response = shared_snapshots_response_create(
      list_createList(),
      list_createList()
    );
  } else {
    shared_snapshots_response = shared_snapshots_response_create(
      list_createList(),
      list_createList()
    );
  }

  return shared_snapshots_response;
}


#ifdef shared_snapshots_response_MAIN

void test_shared_snapshots_response(int include_optional) {
    shared_snapshots_response_t* shared_snapshots_response_1 = instantiate_shared_snapshots_response(include_optional);

	cJSON* jsonshared_snapshots_response_1 = shared_snapshots_response_convertToJSON(shared_snapshots_response_1);
	printf("shared_snapshots_response :\n%s\n", cJSON_Print(jsonshared_snapshots_response_1));
	shared_snapshots_response_t* shared_snapshots_response_2 = shared_snapshots_response_parseFromJSON(jsonshared_snapshots_response_1);
	cJSON* jsonshared_snapshots_response_2 = shared_snapshots_response_convertToJSON(shared_snapshots_response_2);
	printf("repeating shared_snapshots_response:\n%s\n", cJSON_Print(jsonshared_snapshots_response_2));
}

int main() {
  test_shared_snapshots_response(1);
  test_shared_snapshots_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // shared_snapshots_response_MAIN
#endif // shared_snapshots_response_TEST
