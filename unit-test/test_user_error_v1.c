#ifndef user_error_v1_TEST
#define user_error_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_error_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_error_v1.h"
user_error_v1_t* instantiate_user_error_v1(int include_optional);



user_error_v1_t* instantiate_user_error_v1(int include_optional) {
  user_error_v1_t* user_error_v1 = NULL;
  if (include_optional) {
    user_error_v1 = user_error_v1_create(
      "0",
      corellium_api_user_error_v1_ERRORID_UserError,
      "0"
    );
  } else {
    user_error_v1 = user_error_v1_create(
      "0",
      corellium_api_user_error_v1_ERRORID_UserError,
      "0"
    );
  }

  return user_error_v1;
}


#ifdef user_error_v1_MAIN

void test_user_error_v1(int include_optional) {
    user_error_v1_t* user_error_v1_1 = instantiate_user_error_v1(include_optional);

	cJSON* jsonuser_error_v1_1 = user_error_v1_convertToJSON(user_error_v1_1);
	printf("user_error_v1 :\n%s\n", cJSON_Print(jsonuser_error_v1_1));
	user_error_v1_t* user_error_v1_2 = user_error_v1_parseFromJSON(jsonuser_error_v1_1);
	cJSON* jsonuser_error_v1_2 = user_error_v1_convertToJSON(user_error_v1_2);
	printf("repeating user_error_v1:\n%s\n", cJSON_Print(jsonuser_error_v1_2));
}

int main() {
  test_user_error_v1(1);
  test_user_error_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_error_v1_MAIN
#endif // user_error_v1_TEST
