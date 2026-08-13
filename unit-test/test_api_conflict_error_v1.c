#ifndef api_conflict_error_v1_TEST
#define api_conflict_error_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_conflict_error_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_conflict_error_v1.h"
api_conflict_error_v1_t* instantiate_api_conflict_error_v1(int include_optional);



api_conflict_error_v1_t* instantiate_api_conflict_error_v1(int include_optional) {
  api_conflict_error_v1_t* api_conflict_error_v1 = NULL;
  if (include_optional) {
    api_conflict_error_v1 = api_conflict_error_v1_create(
      "0",
      corellium_api_api_conflict_error_v1_ERRORID_Conflict,
      0
    );
  } else {
    api_conflict_error_v1 = api_conflict_error_v1_create(
      "0",
      corellium_api_api_conflict_error_v1_ERRORID_Conflict,
      0
    );
  }

  return api_conflict_error_v1;
}


#ifdef api_conflict_error_v1_MAIN

void test_api_conflict_error_v1(int include_optional) {
    api_conflict_error_v1_t* api_conflict_error_v1_1 = instantiate_api_conflict_error_v1(include_optional);

	cJSON* jsonapi_conflict_error_v1_1 = api_conflict_error_v1_convertToJSON(api_conflict_error_v1_1);
	printf("api_conflict_error_v1 :\n%s\n", cJSON_Print(jsonapi_conflict_error_v1_1));
	api_conflict_error_v1_t* api_conflict_error_v1_2 = api_conflict_error_v1_parseFromJSON(jsonapi_conflict_error_v1_1);
	cJSON* jsonapi_conflict_error_v1_2 = api_conflict_error_v1_convertToJSON(api_conflict_error_v1_2);
	printf("repeating api_conflict_error_v1:\n%s\n", cJSON_Print(jsonapi_conflict_error_v1_2));
}

int main() {
  test_api_conflict_error_v1(1);
  test_api_conflict_error_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_conflict_error_v1_MAIN
#endif // api_conflict_error_v1_TEST
