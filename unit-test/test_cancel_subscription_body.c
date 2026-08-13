#ifndef cancel_subscription_body_TEST
#define cancel_subscription_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cancel_subscription_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cancel_subscription_body.h"
cancel_subscription_body_t* instantiate_cancel_subscription_body(int include_optional);



cancel_subscription_body_t* instantiate_cancel_subscription_body(int include_optional) {
  cancel_subscription_body_t* cancel_subscription_body = NULL;
  if (include_optional) {
    cancel_subscription_body = cancel_subscription_body_create(
      "0",
      1
    );
  } else {
    cancel_subscription_body = cancel_subscription_body_create(
      "0",
      1
    );
  }

  return cancel_subscription_body;
}


#ifdef cancel_subscription_body_MAIN

void test_cancel_subscription_body(int include_optional) {
    cancel_subscription_body_t* cancel_subscription_body_1 = instantiate_cancel_subscription_body(include_optional);

	cJSON* jsoncancel_subscription_body_1 = cancel_subscription_body_convertToJSON(cancel_subscription_body_1);
	printf("cancel_subscription_body :\n%s\n", cJSON_Print(jsoncancel_subscription_body_1));
	cancel_subscription_body_t* cancel_subscription_body_2 = cancel_subscription_body_parseFromJSON(jsoncancel_subscription_body_1);
	cJSON* jsoncancel_subscription_body_2 = cancel_subscription_body_convertToJSON(cancel_subscription_body_2);
	printf("repeating cancel_subscription_body:\n%s\n", cJSON_Print(jsoncancel_subscription_body_2));
}

int main() {
  test_cancel_subscription_body(1);
  test_cancel_subscription_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // cancel_subscription_body_MAIN
#endif // cancel_subscription_body_TEST
