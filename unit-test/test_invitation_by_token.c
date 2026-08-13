#ifndef invitation_by_token_TEST
#define invitation_by_token_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invitation_by_token_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invitation_by_token.h"
invitation_by_token_t* instantiate_invitation_by_token(int include_optional);

#include "test_invite_settings.c"


invitation_by_token_t* instantiate_invitation_by_token(int include_optional) {
  invitation_by_token_t* invitation_by_token = NULL;
  if (include_optional) {
    invitation_by_token = invitation_by_token_create(
      "0",
      "0",
      "0",
      "0",
      1,
       // false, not to have infinite recursion
      instantiate_invite_settings(0)
    );
  } else {
    invitation_by_token = invitation_by_token_create(
      "0",
      "0",
      "0",
      "0",
      1,
      NULL
    );
  }

  return invitation_by_token;
}


#ifdef invitation_by_token_MAIN

void test_invitation_by_token(int include_optional) {
    invitation_by_token_t* invitation_by_token_1 = instantiate_invitation_by_token(include_optional);

	cJSON* jsoninvitation_by_token_1 = invitation_by_token_convertToJSON(invitation_by_token_1);
	printf("invitation_by_token :\n%s\n", cJSON_Print(jsoninvitation_by_token_1));
	invitation_by_token_t* invitation_by_token_2 = invitation_by_token_parseFromJSON(jsoninvitation_by_token_1);
	cJSON* jsoninvitation_by_token_2 = invitation_by_token_convertToJSON(invitation_by_token_2);
	printf("repeating invitation_by_token:\n%s\n", cJSON_Print(jsoninvitation_by_token_2));
}

int main() {
  test_invitation_by_token(1);
  test_invitation_by_token(0);

  printf("Hello world \n");
  return 0;
}

#endif // invitation_by_token_MAIN
#endif // invitation_by_token_TEST
