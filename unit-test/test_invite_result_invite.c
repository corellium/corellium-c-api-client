#ifndef invite_result_invite_TEST
#define invite_result_invite_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_result_invite_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_result_invite.h"
invite_result_invite_t* instantiate_invite_result_invite(int include_optional);

#include "test_invite_settings.c"


invite_result_invite_t* instantiate_invite_result_invite(int include_optional) {
  invite_result_invite_t* invite_result_invite = NULL;
  if (include_optional) {
    invite_result_invite = invite_result_invite_create(
      "5ac8f0be-616d-45b9-b0af-e586fc65ad19",
      "jane.doe@example.com",
       // false, not to have infinite recursion
      instantiate_invite_settings(0)
    );
  } else {
    invite_result_invite = invite_result_invite_create(
      "5ac8f0be-616d-45b9-b0af-e586fc65ad19",
      "jane.doe@example.com",
      NULL
    );
  }

  return invite_result_invite;
}


#ifdef invite_result_invite_MAIN

void test_invite_result_invite(int include_optional) {
    invite_result_invite_t* invite_result_invite_1 = instantiate_invite_result_invite(include_optional);

	cJSON* jsoninvite_result_invite_1 = invite_result_invite_convertToJSON(invite_result_invite_1);
	printf("invite_result_invite :\n%s\n", cJSON_Print(jsoninvite_result_invite_1));
	invite_result_invite_t* invite_result_invite_2 = invite_result_invite_parseFromJSON(jsoninvite_result_invite_1);
	cJSON* jsoninvite_result_invite_2 = invite_result_invite_convertToJSON(invite_result_invite_2);
	printf("repeating invite_result_invite:\n%s\n", cJSON_Print(jsoninvite_result_invite_2));
}

int main() {
  test_invite_result_invite(1);
  test_invite_result_invite(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_result_invite_MAIN
#endif // invite_result_invite_TEST
