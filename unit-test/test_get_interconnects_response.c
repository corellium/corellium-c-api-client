#ifndef get_interconnects_response_TEST
#define get_interconnects_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_interconnects_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_interconnects_response.h"
get_interconnects_response_t* instantiate_get_interconnects_response(int include_optional);



get_interconnects_response_t* instantiate_get_interconnects_response(int include_optional) {
  get_interconnects_response_t* get_interconnects_response = NULL;
  if (include_optional) {
    get_interconnects_response = get_interconnects_response_create(
      list_createList(),
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    get_interconnects_response = get_interconnects_response_create(
      list_createList(),
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return get_interconnects_response;
}


#ifdef get_interconnects_response_MAIN

void test_get_interconnects_response(int include_optional) {
    get_interconnects_response_t* get_interconnects_response_1 = instantiate_get_interconnects_response(include_optional);

	cJSON* jsonget_interconnects_response_1 = get_interconnects_response_convertToJSON(get_interconnects_response_1);
	printf("get_interconnects_response :\n%s\n", cJSON_Print(jsonget_interconnects_response_1));
	get_interconnects_response_t* get_interconnects_response_2 = get_interconnects_response_parseFromJSON(jsonget_interconnects_response_1);
	cJSON* jsonget_interconnects_response_2 = get_interconnects_response_convertToJSON(get_interconnects_response_2);
	printf("repeating get_interconnects_response:\n%s\n", cJSON_Print(jsonget_interconnects_response_2));
}

int main() {
  test_get_interconnects_response(1);
  test_get_interconnects_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_interconnects_response_MAIN
#endif // get_interconnects_response_TEST
