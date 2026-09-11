#ifndef login_result_disabled_TEST
#define login_result_disabled_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_disabled_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result_disabled.h"
login_result_disabled_t* instantiate_login_result_disabled(int include_optional);



login_result_disabled_t* instantiate_login_result_disabled(int include_optional) {
  login_result_disabled_t* login_result_disabled = NULL;
  if (include_optional) {
    login_result_disabled = login_result_disabled_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    login_result_disabled = login_result_disabled_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return login_result_disabled;
}


#ifdef login_result_disabled_MAIN

void test_login_result_disabled(int include_optional) {
    login_result_disabled_t* login_result_disabled_1 = instantiate_login_result_disabled(include_optional);

	cJSON* jsonlogin_result_disabled_1 = login_result_disabled_convertToJSON(login_result_disabled_1);
	printf("login_result_disabled :\n%s\n", cJSON_Print(jsonlogin_result_disabled_1));
	login_result_disabled_t* login_result_disabled_2 = login_result_disabled_parseFromJSON(jsonlogin_result_disabled_1);
	cJSON* jsonlogin_result_disabled_2 = login_result_disabled_convertToJSON(login_result_disabled_2);
	printf("repeating login_result_disabled:\n%s\n", cJSON_Print(jsonlogin_result_disabled_2));
}

int main() {
  test_login_result_disabled(1);
  test_login_result_disabled(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_disabled_MAIN
#endif // login_result_disabled_TEST
