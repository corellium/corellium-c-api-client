#ifndef login_result_TEST
#define login_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result.h"
login_result_t* instantiate_login_result(int include_optional);



login_result_t* instantiate_login_result(int include_optional) {
  login_result_t* login_result = NULL;
  if (include_optional) {
    login_result = login_result_create(
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    login_result = login_result_create(
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return login_result;
}


#ifdef login_result_MAIN

void test_login_result(int include_optional) {
    login_result_t* login_result_1 = instantiate_login_result(include_optional);

	cJSON* jsonlogin_result_1 = login_result_convertToJSON(login_result_1);
	printf("login_result :\n%s\n", cJSON_Print(jsonlogin_result_1));
	login_result_t* login_result_2 = login_result_parseFromJSON(jsonlogin_result_1);
	cJSON* jsonlogin_result_2 = login_result_convertToJSON(login_result_2);
	printf("repeating login_result:\n%s\n", cJSON_Print(jsonlogin_result_2));
}

int main() {
  test_login_result(1);
  test_login_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_MAIN
#endif // login_result_TEST
