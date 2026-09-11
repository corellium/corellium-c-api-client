#ifndef login_result_domain_webplayer_TEST
#define login_result_domain_webplayer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_domain_webplayer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result_domain_webplayer.h"
login_result_domain_webplayer_t* instantiate_login_result_domain_webplayer(int include_optional);



login_result_domain_webplayer_t* instantiate_login_result_domain_webplayer(int include_optional) {
  login_result_domain_webplayer_t* login_result_domain_webplayer = NULL;
  if (include_optional) {
    login_result_domain_webplayer = login_result_domain_webplayer_create(
      1,
      list_createList()
    );
  } else {
    login_result_domain_webplayer = login_result_domain_webplayer_create(
      1,
      list_createList()
    );
  }

  return login_result_domain_webplayer;
}


#ifdef login_result_domain_webplayer_MAIN

void test_login_result_domain_webplayer(int include_optional) {
    login_result_domain_webplayer_t* login_result_domain_webplayer_1 = instantiate_login_result_domain_webplayer(include_optional);

	cJSON* jsonlogin_result_domain_webplayer_1 = login_result_domain_webplayer_convertToJSON(login_result_domain_webplayer_1);
	printf("login_result_domain_webplayer :\n%s\n", cJSON_Print(jsonlogin_result_domain_webplayer_1));
	login_result_domain_webplayer_t* login_result_domain_webplayer_2 = login_result_domain_webplayer_parseFromJSON(jsonlogin_result_domain_webplayer_1);
	cJSON* jsonlogin_result_domain_webplayer_2 = login_result_domain_webplayer_convertToJSON(login_result_domain_webplayer_2);
	printf("repeating login_result_domain_webplayer:\n%s\n", cJSON_Print(jsonlogin_result_domain_webplayer_2));
}

int main() {
  test_login_result_domain_webplayer(1);
  test_login_result_domain_webplayer(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_domain_webplayer_MAIN
#endif // login_result_domain_webplayer_TEST
