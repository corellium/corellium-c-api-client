#ifndef api_token_result_TEST
#define api_token_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_token_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_token_result.h"
api_token_result_t* instantiate_api_token_result(int include_optional);



api_token_result_t* instantiate_api_token_result(int include_optional) {
  api_token_result_t* api_token_result = NULL;
  if (include_optional) {
    api_token_result = api_token_result_create(
      "<token>"
    );
  } else {
    api_token_result = api_token_result_create(
      "<token>"
    );
  }

  return api_token_result;
}


#ifdef api_token_result_MAIN

void test_api_token_result(int include_optional) {
    api_token_result_t* api_token_result_1 = instantiate_api_token_result(include_optional);

	cJSON* jsonapi_token_result_1 = api_token_result_convertToJSON(api_token_result_1);
	printf("api_token_result :\n%s\n", cJSON_Print(jsonapi_token_result_1));
	api_token_result_t* api_token_result_2 = api_token_result_parseFromJSON(jsonapi_token_result_1);
	cJSON* jsonapi_token_result_2 = api_token_result_convertToJSON(api_token_result_2);
	printf("repeating api_token_result:\n%s\n", cJSON_Print(jsonapi_token_result_2));
}

int main() {
  test_api_token_result(1);
  test_api_token_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_token_result_MAIN
#endif // api_token_result_TEST
