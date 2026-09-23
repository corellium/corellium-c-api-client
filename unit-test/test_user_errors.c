#ifndef user_errors_TEST
#define user_errors_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_errors_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_errors.h"
user_errors_t* instantiate_user_errors(int include_optional);



user_errors_t* instantiate_user_errors(int include_optional) {
  user_errors_t* user_errors = NULL;
  if (include_optional) {
    user_errors = user_errors_create(
      "One or more fields were rejected",
      corellium_api_user_errors_ERRORID_UserErrors,
      list_createList()
    );
  } else {
    user_errors = user_errors_create(
      "One or more fields were rejected",
      corellium_api_user_errors_ERRORID_UserErrors,
      list_createList()
    );
  }

  return user_errors;
}


#ifdef user_errors_MAIN

void test_user_errors(int include_optional) {
    user_errors_t* user_errors_1 = instantiate_user_errors(include_optional);

	cJSON* jsonuser_errors_1 = user_errors_convertToJSON(user_errors_1);
	printf("user_errors :\n%s\n", cJSON_Print(jsonuser_errors_1));
	user_errors_t* user_errors_2 = user_errors_parseFromJSON(jsonuser_errors_1);
	cJSON* jsonuser_errors_2 = user_errors_convertToJSON(user_errors_2);
	printf("repeating user_errors:\n%s\n", cJSON_Print(jsonuser_errors_2));
}

int main() {
  test_user_errors(1);
  test_user_errors(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_errors_MAIN
#endif // user_errors_TEST
