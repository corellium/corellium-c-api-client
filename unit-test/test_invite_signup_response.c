#ifndef invite_signup_response_TEST
#define invite_signup_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_signup_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_signup_response.h"
invite_signup_response_t* instantiate_invite_signup_response(int include_optional);



invite_signup_response_t* instantiate_invite_signup_response(int include_optional) {
  invite_signup_response_t* invite_signup_response = NULL;
  if (include_optional) {
    invite_signup_response = invite_signup_response_create(
      "0"
    );
  } else {
    invite_signup_response = invite_signup_response_create(
      "0"
    );
  }

  return invite_signup_response;
}


#ifdef invite_signup_response_MAIN

void test_invite_signup_response(int include_optional) {
    invite_signup_response_t* invite_signup_response_1 = instantiate_invite_signup_response(include_optional);

	cJSON* jsoninvite_signup_response_1 = invite_signup_response_convertToJSON(invite_signup_response_1);
	printf("invite_signup_response :\n%s\n", cJSON_Print(jsoninvite_signup_response_1));
	invite_signup_response_t* invite_signup_response_2 = invite_signup_response_parseFromJSON(jsoninvite_signup_response_1);
	cJSON* jsoninvite_signup_response_2 = invite_signup_response_convertToJSON(invite_signup_response_2);
	printf("repeating invite_signup_response:\n%s\n", cJSON_Print(jsoninvite_signup_response_2));
}

int main() {
  test_invite_signup_response(1);
  test_invite_signup_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_signup_response_MAIN
#endif // invite_signup_response_TEST
