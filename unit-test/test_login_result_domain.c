#ifndef login_result_domain_TEST
#define login_result_domain_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_domain_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result_domain.h"
login_result_domain_t* instantiate_login_result_domain(int include_optional);

#include "test_login_result_domain_trial.c"
#include "test_login_result_domain_webplayer.c"
#include "test_login_result_domain_snapshot_sharing_permissions.c"
#include "test_login_result_domain_device_auto_shutdown.c"
#include "test_login_result_domain_disabled.c"


login_result_domain_t* instantiate_login_result_domain(int include_optional) {
  login_result_domain_t* login_result_domain = NULL;
  if (include_optional) {
    login_result_domain = login_result_domain_create(
      "0",
      "0",
      "0",
      1.337,
      1,
      1,
      0,
      "0",
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_login_result_domain_trial(0),
       // false, not to have infinite recursion
      instantiate_login_result_domain_webplayer(0),
       // false, not to have infinite recursion
      instantiate_login_result_domain_snapshot_sharing_permissions(0),
       // false, not to have infinite recursion
      instantiate_login_result_domain_device_auto_shutdown(0),
       // false, not to have infinite recursion
      instantiate_login_result_domain_disabled(0)
    );
  } else {
    login_result_domain = login_result_domain_create(
      "0",
      "0",
      "0",
      1.337,
      1,
      1,
      0,
      "0",
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      "0",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return login_result_domain;
}


#ifdef login_result_domain_MAIN

void test_login_result_domain(int include_optional) {
    login_result_domain_t* login_result_domain_1 = instantiate_login_result_domain(include_optional);

	cJSON* jsonlogin_result_domain_1 = login_result_domain_convertToJSON(login_result_domain_1);
	printf("login_result_domain :\n%s\n", cJSON_Print(jsonlogin_result_domain_1));
	login_result_domain_t* login_result_domain_2 = login_result_domain_parseFromJSON(jsonlogin_result_domain_1);
	cJSON* jsonlogin_result_domain_2 = login_result_domain_convertToJSON(login_result_domain_2);
	printf("repeating login_result_domain:\n%s\n", cJSON_Print(jsonlogin_result_domain_2));
}

int main() {
  test_login_result_domain(1);
  test_login_result_domain(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_domain_MAIN
#endif // login_result_domain_TEST
