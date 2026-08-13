#ifndef interconnect_response_TEST
#define interconnect_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define interconnect_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/interconnect_response.h"
interconnect_response_t* instantiate_interconnect_response(int include_optional);



interconnect_response_t* instantiate_interconnect_response(int include_optional) {
  interconnect_response_t* interconnect_response = NULL;
  if (include_optional) {
    interconnect_response = interconnect_response_create(
      "0",
      "0",
      "0",
      corellium_api_interconnect_response_TYPE_hub,
      "0",
      "0",
      list_createList(),
      "0",
      "0"
    );
  } else {
    interconnect_response = interconnect_response_create(
      "0",
      "0",
      "0",
      corellium_api_interconnect_response_TYPE_hub,
      "0",
      "0",
      list_createList(),
      "0",
      "0"
    );
  }

  return interconnect_response;
}


#ifdef interconnect_response_MAIN

void test_interconnect_response(int include_optional) {
    interconnect_response_t* interconnect_response_1 = instantiate_interconnect_response(include_optional);

	cJSON* jsoninterconnect_response_1 = interconnect_response_convertToJSON(interconnect_response_1);
	printf("interconnect_response :\n%s\n", cJSON_Print(jsoninterconnect_response_1));
	interconnect_response_t* interconnect_response_2 = interconnect_response_parseFromJSON(jsoninterconnect_response_1);
	cJSON* jsoninterconnect_response_2 = interconnect_response_convertToJSON(interconnect_response_2);
	printf("repeating interconnect_response:\n%s\n", cJSON_Print(jsoninterconnect_response_2));
}

int main() {
  test_interconnect_response(1);
  test_interconnect_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // interconnect_response_MAIN
#endif // interconnect_response_TEST
