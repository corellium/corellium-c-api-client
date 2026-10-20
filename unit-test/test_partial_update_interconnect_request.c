#ifndef partial_update_interconnect_request_TEST
#define partial_update_interconnect_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partial_update_interconnect_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partial_update_interconnect_request.h"
partial_update_interconnect_request_t* instantiate_partial_update_interconnect_request(int include_optional);



partial_update_interconnect_request_t* instantiate_partial_update_interconnect_request(int include_optional) {
  partial_update_interconnect_request_t* partial_update_interconnect_request = NULL;
  if (include_optional) {
    partial_update_interconnect_request = partial_update_interconnect_request_create(
      "0",
      list_createList()
    );
  } else {
    partial_update_interconnect_request = partial_update_interconnect_request_create(
      "0",
      list_createList()
    );
  }

  return partial_update_interconnect_request;
}


#ifdef partial_update_interconnect_request_MAIN

void test_partial_update_interconnect_request(int include_optional) {
    partial_update_interconnect_request_t* partial_update_interconnect_request_1 = instantiate_partial_update_interconnect_request(include_optional);

	cJSON* jsonpartial_update_interconnect_request_1 = partial_update_interconnect_request_convertToJSON(partial_update_interconnect_request_1);
	printf("partial_update_interconnect_request :\n%s\n", cJSON_Print(jsonpartial_update_interconnect_request_1));
	partial_update_interconnect_request_t* partial_update_interconnect_request_2 = partial_update_interconnect_request_parseFromJSON(jsonpartial_update_interconnect_request_1);
	cJSON* jsonpartial_update_interconnect_request_2 = partial_update_interconnect_request_convertToJSON(partial_update_interconnect_request_2);
	printf("repeating partial_update_interconnect_request:\n%s\n", cJSON_Print(jsonpartial_update_interconnect_request_2));
}

int main() {
  test_partial_update_interconnect_request(1);
  test_partial_update_interconnect_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // partial_update_interconnect_request_MAIN
#endif // partial_update_interconnect_request_TEST
