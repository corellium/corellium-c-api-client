#ifndef revoke_invites_body_TEST
#define revoke_invites_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define revoke_invites_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/revoke_invites_body.h"
revoke_invites_body_t* instantiate_revoke_invites_body(int include_optional);



revoke_invites_body_t* instantiate_revoke_invites_body(int include_optional) {
  revoke_invites_body_t* revoke_invites_body = NULL;
  if (include_optional) {
    revoke_invites_body = revoke_invites_body_create(
      list_createList()
    );
  } else {
    revoke_invites_body = revoke_invites_body_create(
      list_createList()
    );
  }

  return revoke_invites_body;
}


#ifdef revoke_invites_body_MAIN

void test_revoke_invites_body(int include_optional) {
    revoke_invites_body_t* revoke_invites_body_1 = instantiate_revoke_invites_body(include_optional);

	cJSON* jsonrevoke_invites_body_1 = revoke_invites_body_convertToJSON(revoke_invites_body_1);
	printf("revoke_invites_body :\n%s\n", cJSON_Print(jsonrevoke_invites_body_1));
	revoke_invites_body_t* revoke_invites_body_2 = revoke_invites_body_parseFromJSON(jsonrevoke_invites_body_1);
	cJSON* jsonrevoke_invites_body_2 = revoke_invites_body_convertToJSON(revoke_invites_body_2);
	printf("repeating revoke_invites_body:\n%s\n", cJSON_Print(jsonrevoke_invites_body_2));
}

int main() {
  test_revoke_invites_body(1);
  test_revoke_invites_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // revoke_invites_body_MAIN
#endif // revoke_invites_body_TEST
