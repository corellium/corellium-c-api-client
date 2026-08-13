#ifndef revoke_invites_response_TEST
#define revoke_invites_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revoke_invites_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revoke_invites_response.h"
revoke_invites_response_t* instantiate_revoke_invites_response(int include_optional);



revoke_invites_response_t* instantiate_revoke_invites_response(int include_optional) {
  revoke_invites_response_t* revoke_invites_response = NULL;
  if (include_optional) {
    revoke_invites_response = revoke_invites_response_create(
      56
    );
  } else {
    revoke_invites_response = revoke_invites_response_create(
      56
    );
  }

  return revoke_invites_response;
}


#ifdef revoke_invites_response_MAIN

void test_revoke_invites_response(int include_optional) {
    revoke_invites_response_t* revoke_invites_response_1 = instantiate_revoke_invites_response(include_optional);

	cJSON* jsonrevoke_invites_response_1 = revoke_invites_response_convertToJSON(revoke_invites_response_1);
	printf("revoke_invites_response :\n%s\n", cJSON_Print(jsonrevoke_invites_response_1));
	revoke_invites_response_t* revoke_invites_response_2 = revoke_invites_response_parseFromJSON(jsonrevoke_invites_response_1);
	cJSON* jsonrevoke_invites_response_2 = revoke_invites_response_convertToJSON(revoke_invites_response_2);
	printf("repeating revoke_invites_response:\n%s\n", cJSON_Print(jsonrevoke_invites_response_2));
}

int main() {
  test_revoke_invites_response(1);
  test_revoke_invites_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // revoke_invites_response_MAIN
#endif // revoke_invites_response_TEST
