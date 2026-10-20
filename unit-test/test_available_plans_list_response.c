#ifndef available_plans_list_response_TEST
#define available_plans_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define available_plans_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/available_plans_list_response.h"
available_plans_list_response_t* instantiate_available_plans_list_response(int include_optional);



available_plans_list_response_t* instantiate_available_plans_list_response(int include_optional) {
  available_plans_list_response_t* available_plans_list_response = NULL;
  if (include_optional) {
    available_plans_list_response = available_plans_list_response_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    available_plans_list_response = available_plans_list_response_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return available_plans_list_response;
}


#ifdef available_plans_list_response_MAIN

void test_available_plans_list_response(int include_optional) {
    available_plans_list_response_t* available_plans_list_response_1 = instantiate_available_plans_list_response(include_optional);

	cJSON* jsonavailable_plans_list_response_1 = available_plans_list_response_convertToJSON(available_plans_list_response_1);
	printf("available_plans_list_response :\n%s\n", cJSON_Print(jsonavailable_plans_list_response_1));
	available_plans_list_response_t* available_plans_list_response_2 = available_plans_list_response_parseFromJSON(jsonavailable_plans_list_response_1);
	cJSON* jsonavailable_plans_list_response_2 = available_plans_list_response_convertToJSON(available_plans_list_response_2);
	printf("repeating available_plans_list_response:\n%s\n", cJSON_Print(jsonavailable_plans_list_response_2));
}

int main() {
  test_available_plans_list_response(1);
  test_available_plans_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // available_plans_list_response_MAIN
#endif // available_plans_list_response_TEST
