#ifndef invite_signup_body_TEST
#define invite_signup_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_signup_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_signup_body.h"
invite_signup_body_t* instantiate_invite_signup_body(int include_optional);

#include "test_invite_signup_body_params.c"


invite_signup_body_t* instantiate_invite_signup_body(int include_optional) {
  invite_signup_body_t* invite_signup_body = NULL;
  if (include_optional) {
    invite_signup_body = invite_signup_body_create(
      "0",
       // false, not to have infinite recursion
      instantiate_invite_signup_body_params(0)
    );
  } else {
    invite_signup_body = invite_signup_body_create(
      "0",
      NULL
    );
  }

  return invite_signup_body;
}


#ifdef invite_signup_body_MAIN

void test_invite_signup_body(int include_optional) {
    invite_signup_body_t* invite_signup_body_1 = instantiate_invite_signup_body(include_optional);

	cJSON* jsoninvite_signup_body_1 = invite_signup_body_convertToJSON(invite_signup_body_1);
	printf("invite_signup_body :\n%s\n", cJSON_Print(jsoninvite_signup_body_1));
	invite_signup_body_t* invite_signup_body_2 = invite_signup_body_parseFromJSON(jsoninvite_signup_body_1);
	cJSON* jsoninvite_signup_body_2 = invite_signup_body_convertToJSON(invite_signup_body_2);
	printf("repeating invite_signup_body:\n%s\n", cJSON_Print(jsoninvite_signup_body_2));
}

int main() {
  test_invite_signup_body(1);
  test_invite_signup_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_signup_body_MAIN
#endif // invite_signup_body_TEST
