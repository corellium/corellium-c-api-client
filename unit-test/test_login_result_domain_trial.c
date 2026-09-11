#ifndef login_result_domain_trial_TEST
#define login_result_domain_trial_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_domain_trial_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result_domain_trial.h"
login_result_domain_trial_t* instantiate_login_result_domain_trial(int include_optional);



login_result_domain_trial_t* instantiate_login_result_domain_trial(int include_optional) {
  login_result_domain_trial_t* login_result_domain_trial = NULL;
  if (include_optional) {
    login_result_domain_trial = login_result_domain_trial_create(
      1.337,
      1.337
    );
  } else {
    login_result_domain_trial = login_result_domain_trial_create(
      1.337,
      1.337
    );
  }

  return login_result_domain_trial;
}


#ifdef login_result_domain_trial_MAIN

void test_login_result_domain_trial(int include_optional) {
    login_result_domain_trial_t* login_result_domain_trial_1 = instantiate_login_result_domain_trial(include_optional);

	cJSON* jsonlogin_result_domain_trial_1 = login_result_domain_trial_convertToJSON(login_result_domain_trial_1);
	printf("login_result_domain_trial :\n%s\n", cJSON_Print(jsonlogin_result_domain_trial_1));
	login_result_domain_trial_t* login_result_domain_trial_2 = login_result_domain_trial_parseFromJSON(jsonlogin_result_domain_trial_1);
	cJSON* jsonlogin_result_domain_trial_2 = login_result_domain_trial_convertToJSON(login_result_domain_trial_2);
	printf("repeating login_result_domain_trial:\n%s\n", cJSON_Print(jsonlogin_result_domain_trial_2));
}

int main() {
  test_login_result_domain_trial(1);
  test_login_result_domain_trial(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_domain_trial_MAIN
#endif // login_result_domain_trial_TEST
