#ifndef subscribe_to_trial_body_TEST
#define subscribe_to_trial_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define subscribe_to_trial_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/subscribe_to_trial_body.h"
subscribe_to_trial_body_t* instantiate_subscribe_to_trial_body(int include_optional);



subscribe_to_trial_body_t* instantiate_subscribe_to_trial_body(int include_optional) {
  subscribe_to_trial_body_t* subscribe_to_trial_body = NULL;
  if (include_optional) {
    subscribe_to_trial_body = subscribe_to_trial_body_create(
      "TRIAL2026",
      "<redacted>",
      true,
      "acme-corp",
      false,
      "jane.doe@example.com",
      "Jane Doe",
      "okta|00u1a2b3c4d5e6f7g8h9"
    );
  } else {
    subscribe_to_trial_body = subscribe_to_trial_body_create(
      "TRIAL2026",
      "<redacted>",
      true,
      "acme-corp",
      false,
      "jane.doe@example.com",
      "Jane Doe",
      "okta|00u1a2b3c4d5e6f7g8h9"
    );
  }

  return subscribe_to_trial_body;
}


#ifdef subscribe_to_trial_body_MAIN

void test_subscribe_to_trial_body(int include_optional) {
    subscribe_to_trial_body_t* subscribe_to_trial_body_1 = instantiate_subscribe_to_trial_body(include_optional);

	cJSON* jsonsubscribe_to_trial_body_1 = subscribe_to_trial_body_convertToJSON(subscribe_to_trial_body_1);
	printf("subscribe_to_trial_body :\n%s\n", cJSON_Print(jsonsubscribe_to_trial_body_1));
	subscribe_to_trial_body_t* subscribe_to_trial_body_2 = subscribe_to_trial_body_parseFromJSON(jsonsubscribe_to_trial_body_1);
	cJSON* jsonsubscribe_to_trial_body_2 = subscribe_to_trial_body_convertToJSON(subscribe_to_trial_body_2);
	printf("repeating subscribe_to_trial_body:\n%s\n", cJSON_Print(jsonsubscribe_to_trial_body_2));
}

int main() {
  test_subscribe_to_trial_body(1);
  test_subscribe_to_trial_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // subscribe_to_trial_body_MAIN
#endif // subscribe_to_trial_body_TEST
