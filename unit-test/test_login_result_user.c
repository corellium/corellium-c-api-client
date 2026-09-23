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
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "jane.doe",
      "Jane Doe",
      "jane.doe@example.com",
      false,
      "2026-03-17T11:41:05.000Z",
      "jane.doe@example.com",
      "<redacted>",
      {"apiToken":{"prefix":"<token-prefix>","lastAuthDate":"2026-03-17T11:41:05.000Z","lastAddress":"10.0.10.5"},"lastVPNType":"ovpn"}
    );
  } else {
    login_result_user = login_result_user_create(
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "jane.doe",
      "Jane Doe",
      "jane.doe@example.com",
      false,
      "2026-03-17T11:41:05.000Z",
      "jane.doe@example.com",
      "<redacted>",
      {"apiToken":{"prefix":"<token-prefix>","lastAuthDate":"2026-03-17T11:41:05.000Z","lastAddress":"10.0.10.5"},"lastVPNType":"ovpn"}
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
