#ifndef user_errors_v1_TEST
#define user_errors_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_errors_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_errors_v1.h"
user_errors_v1_t* instantiate_user_errors_v1(int include_optional);



user_errors_v1_t* instantiate_user_errors_v1(int include_optional) {
  user_errors_v1_t* user_errors_v1 = NULL;
  if (include_optional) {
    user_errors_v1 = user_errors_v1_create(
      "0",
      corellium_api_user_errors_v1_ERRORID_UserErrors,
      list_createList()
    );
  } else {
    user_errors_v1 = user_errors_v1_create(
      "0",
      corellium_api_user_errors_v1_ERRORID_UserErrors,
      list_createList()
    );
  }

  return user_errors_v1;
}


#ifdef user_errors_v1_MAIN

void test_user_errors_v1(int include_optional) {
    user_errors_v1_t* user_errors_v1_1 = instantiate_user_errors_v1(include_optional);

	cJSON* jsonuser_errors_v1_1 = user_errors_v1_convertToJSON(user_errors_v1_1);
	printf("user_errors_v1 :\n%s\n", cJSON_Print(jsonuser_errors_v1_1));
	user_errors_v1_t* user_errors_v1_2 = user_errors_v1_parseFromJSON(jsonuser_errors_v1_1);
	cJSON* jsonuser_errors_v1_2 = user_errors_v1_convertToJSON(user_errors_v1_2);
	printf("repeating user_errors_v1:\n%s\n", cJSON_Print(jsonuser_errors_v1_2));
}

int main() {
  test_user_errors_v1(1);
  test_user_errors_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_errors_v1_MAIN
#endif // user_errors_v1_TEST
