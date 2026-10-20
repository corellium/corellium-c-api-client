#ifndef uncancel_subscription_body_TEST
#define uncancel_subscription_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define uncancel_subscription_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/uncancel_subscription_body.h"
uncancel_subscription_body_t* instantiate_uncancel_subscription_body(int include_optional);



uncancel_subscription_body_t* instantiate_uncancel_subscription_body(int include_optional) {
  uncancel_subscription_body_t* uncancel_subscription_body = NULL;
  if (include_optional) {
    uncancel_subscription_body = uncancel_subscription_body_create(
      "c29762d1-45d7-489d-a3a2-9dadc43978ba"
    );
  } else {
    uncancel_subscription_body = uncancel_subscription_body_create(
      "c29762d1-45d7-489d-a3a2-9dadc43978ba"
    );
  }

  return uncancel_subscription_body;
}


#ifdef uncancel_subscription_body_MAIN

void test_uncancel_subscription_body(int include_optional) {
    uncancel_subscription_body_t* uncancel_subscription_body_1 = instantiate_uncancel_subscription_body(include_optional);

	cJSON* jsonuncancel_subscription_body_1 = uncancel_subscription_body_convertToJSON(uncancel_subscription_body_1);
	printf("uncancel_subscription_body :\n%s\n", cJSON_Print(jsonuncancel_subscription_body_1));
	uncancel_subscription_body_t* uncancel_subscription_body_2 = uncancel_subscription_body_parseFromJSON(jsonuncancel_subscription_body_1);
	cJSON* jsonuncancel_subscription_body_2 = uncancel_subscription_body_convertToJSON(uncancel_subscription_body_2);
	printf("repeating uncancel_subscription_body:\n%s\n", cJSON_Print(jsonuncancel_subscription_body_2));
}

int main() {
  test_uncancel_subscription_body(1);
  test_uncancel_subscription_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // uncancel_subscription_body_MAIN
#endif // uncancel_subscription_body_TEST
