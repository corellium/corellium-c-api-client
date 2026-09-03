#ifndef user_error_response_TEST
#define user_error_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_error_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_error_response.h"
user_error_response_t* instantiate_user_error_response(int include_optional);



user_error_response_t* instantiate_user_error_response(int include_optional) {
  user_error_response_t* user_error_response = NULL;
  if (include_optional) {
    user_error_response = user_error_response_create(
      "0",
      corellium_api_user_error_response_ERRORID_UserErrors,
      "0",
      "0",
      list_createList(),
      list_createList(),
      list_createList()
    );
  } else {
    user_error_response = user_error_response_create(
      "0",
      corellium_api_user_error_response_ERRORID_UserErrors,
      "0",
      "0",
      list_createList(),
      list_createList(),
      list_createList()
    );
  }

  return user_error_response;
}


#ifdef user_error_response_MAIN

void test_user_error_response(int include_optional) {
    user_error_response_t* user_error_response_1 = instantiate_user_error_response(include_optional);

	cJSON* jsonuser_error_response_1 = user_error_response_convertToJSON(user_error_response_1);
	printf("user_error_response :\n%s\n", cJSON_Print(jsonuser_error_response_1));
	user_error_response_t* user_error_response_2 = user_error_response_parseFromJSON(jsonuser_error_response_1);
	cJSON* jsonuser_error_response_2 = user_error_response_convertToJSON(user_error_response_2);
	printf("repeating user_error_response:\n%s\n", cJSON_Print(jsonuser_error_response_2));
}

int main() {
  test_user_error_response(1);
  test_user_error_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_error_response_MAIN
#endif // user_error_response_TEST
