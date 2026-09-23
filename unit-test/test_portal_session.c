#ifndef portal_session_TEST
#define portal_session_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define portal_session_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/portal_session.h"
portal_session_t* instantiate_portal_session(int include_optional);



portal_session_t* instantiate_portal_session(int include_optional) {
  portal_session_t* portal_session = NULL;
  if (include_optional) {
    portal_session = portal_session_create(
      "https://billing.stripe.com/p/session/test_xxxxxxxxxxxxxxxxxxxxxxxx"
    );
  } else {
    portal_session = portal_session_create(
      "https://billing.stripe.com/p/session/test_xxxxxxxxxxxxxxxxxxxxxxxx"
    );
  }

  return portal_session;
}


#ifdef portal_session_MAIN

void test_portal_session(int include_optional) {
    portal_session_t* portal_session_1 = instantiate_portal_session(include_optional);

	cJSON* jsonportal_session_1 = portal_session_convertToJSON(portal_session_1);
	printf("portal_session :\n%s\n", cJSON_Print(jsonportal_session_1));
	portal_session_t* portal_session_2 = portal_session_parseFromJSON(jsonportal_session_1);
	cJSON* jsonportal_session_2 = portal_session_convertToJSON(portal_session_2);
	printf("repeating portal_session:\n%s\n", cJSON_Print(jsonportal_session_2));
}

int main() {
  test_portal_session(1);
  test_portal_session(0);

  printf("Hello world \n");
  return 0;
}

#endif // portal_session_MAIN
#endif // portal_session_TEST
