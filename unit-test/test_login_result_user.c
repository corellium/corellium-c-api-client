#ifndef login_result_user_TEST
#define login_result_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result_user.h"
login_result_user_t* instantiate_login_result_user(int include_optional);



login_result_user_t* instantiate_login_result_user(int include_optional) {
  login_result_user_t* login_result_user = NULL;
  if (include_optional) {
    login_result_user = login_result_user_create(
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      "0",
      "0",
      0
    );
  } else {
    login_result_user = login_result_user_create(
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      "0",
      "0",
      0
    );
  }

  return login_result_user;
}


#ifdef login_result_user_MAIN

void test_login_result_user(int include_optional) {
    login_result_user_t* login_result_user_1 = instantiate_login_result_user(include_optional);

	cJSON* jsonlogin_result_user_1 = login_result_user_convertToJSON(login_result_user_1);
	printf("login_result_user :\n%s\n", cJSON_Print(jsonlogin_result_user_1));
	login_result_user_t* login_result_user_2 = login_result_user_parseFromJSON(jsonlogin_result_user_1);
	cJSON* jsonlogin_result_user_2 = login_result_user_convertToJSON(login_result_user_2);
	printf("repeating login_result_user:\n%s\n", cJSON_Print(jsonlogin_result_user_2));
}

int main() {
  test_login_result_user(1);
  test_login_result_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_user_MAIN
#endif // login_result_user_TEST
