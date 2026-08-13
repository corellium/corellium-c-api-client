#ifndef invitation_v1_TEST
#define invitation_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invitation_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invitation_v1.h"
invitation_v1_t* instantiate_invitation_v1(int include_optional);



invitation_v1_t* instantiate_invitation_v1(int include_optional) {
  invitation_v1_t* invitation_v1 = NULL;
  if (include_optional) {
    invitation_v1 = invitation_v1_create(
      "0",
      "0",
      0
    );
  } else {
    invitation_v1 = invitation_v1_create(
      "0",
      "0",
      0
    );
  }

  return invitation_v1;
}


#ifdef invitation_v1_MAIN

void test_invitation_v1(int include_optional) {
    invitation_v1_t* invitation_v1_1 = instantiate_invitation_v1(include_optional);

	cJSON* jsoninvitation_v1_1 = invitation_v1_convertToJSON(invitation_v1_1);
	printf("invitation_v1 :\n%s\n", cJSON_Print(jsoninvitation_v1_1));
	invitation_v1_t* invitation_v1_2 = invitation_v1_parseFromJSON(jsoninvitation_v1_1);
	cJSON* jsoninvitation_v1_2 = invitation_v1_convertToJSON(invitation_v1_2);
	printf("repeating invitation_v1:\n%s\n", cJSON_Print(jsoninvitation_v1_2));
}

int main() {
  test_invitation_v1(1);
  test_invitation_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // invitation_v1_MAIN
#endif // invitation_v1_TEST
