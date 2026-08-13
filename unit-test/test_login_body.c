#ifndef login_body_TEST
#define login_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_body.h"
login_body_t* instantiate_login_body(int include_optional);



login_body_t* instantiate_login_body(int include_optional) {
  login_body_t* login_body = NULL;
  if (include_optional) {
    login_body = login_body_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    login_body = login_body_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  }

  return login_body;
}


#ifdef login_body_MAIN

void test_login_body(int include_optional) {
    login_body_t* login_body_1 = instantiate_login_body(include_optional);

	cJSON* jsonlogin_body_1 = login_body_convertToJSON(login_body_1);
	printf("login_body :\n%s\n", cJSON_Print(jsonlogin_body_1));
	login_body_t* login_body_2 = login_body_parseFromJSON(jsonlogin_body_1);
	cJSON* jsonlogin_body_2 = login_body_convertToJSON(login_body_2);
	printf("repeating login_body:\n%s\n", cJSON_Print(jsonlogin_body_2));
}

int main() {
  test_login_body(1);
  test_login_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_body_MAIN
#endif // login_body_TEST
