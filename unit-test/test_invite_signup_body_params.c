#ifndef invite_signup_body_params_TEST
#define invite_signup_body_params_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_signup_body_params_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_signup_body_params.h"
invite_signup_body_params_t* instantiate_invite_signup_body_params(int include_optional);



invite_signup_body_params_t* instantiate_invite_signup_body_params(int include_optional) {
  invite_signup_body_params_t* invite_signup_body_params = NULL;
  if (include_optional) {
    invite_signup_body_params = invite_signup_body_params_create(
      "0",
      "0",
      "0",
      1
    );
  } else {
    invite_signup_body_params = invite_signup_body_params_create(
      "0",
      "0",
      "0",
      1
    );
  }

  return invite_signup_body_params;
}


#ifdef invite_signup_body_params_MAIN

void test_invite_signup_body_params(int include_optional) {
    invite_signup_body_params_t* invite_signup_body_params_1 = instantiate_invite_signup_body_params(include_optional);

	cJSON* jsoninvite_signup_body_params_1 = invite_signup_body_params_convertToJSON(invite_signup_body_params_1);
	printf("invite_signup_body_params :\n%s\n", cJSON_Print(jsoninvite_signup_body_params_1));
	invite_signup_body_params_t* invite_signup_body_params_2 = invite_signup_body_params_parseFromJSON(jsoninvite_signup_body_params_1);
	cJSON* jsoninvite_signup_body_params_2 = invite_signup_body_params_convertToJSON(invite_signup_body_params_2);
	printf("repeating invite_signup_body_params:\n%s\n", cJSON_Print(jsoninvite_signup_body_params_2));
}

int main() {
  test_invite_signup_body_params(1);
  test_invite_signup_body_params(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_signup_body_params_MAIN
#endif // invite_signup_body_params_TEST
