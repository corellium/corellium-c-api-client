#ifndef stripe_checkout_complete_body_TEST
#define stripe_checkout_complete_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stripe_checkout_complete_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stripe_checkout_complete_body.h"
stripe_checkout_complete_body_t* instantiate_stripe_checkout_complete_body(int include_optional);



stripe_checkout_complete_body_t* instantiate_stripe_checkout_complete_body(int include_optional) {
  stripe_checkout_complete_body_t* stripe_checkout_complete_body = NULL;
  if (include_optional) {
    stripe_checkout_complete_body = stripe_checkout_complete_body_create(
      "0"
    );
  } else {
    stripe_checkout_complete_body = stripe_checkout_complete_body_create(
      "0"
    );
  }

  return stripe_checkout_complete_body;
}


#ifdef stripe_checkout_complete_body_MAIN

void test_stripe_checkout_complete_body(int include_optional) {
    stripe_checkout_complete_body_t* stripe_checkout_complete_body_1 = instantiate_stripe_checkout_complete_body(include_optional);

	cJSON* jsonstripe_checkout_complete_body_1 = stripe_checkout_complete_body_convertToJSON(stripe_checkout_complete_body_1);
	printf("stripe_checkout_complete_body :\n%s\n", cJSON_Print(jsonstripe_checkout_complete_body_1));
	stripe_checkout_complete_body_t* stripe_checkout_complete_body_2 = stripe_checkout_complete_body_parseFromJSON(jsonstripe_checkout_complete_body_1);
	cJSON* jsonstripe_checkout_complete_body_2 = stripe_checkout_complete_body_convertToJSON(stripe_checkout_complete_body_2);
	printf("repeating stripe_checkout_complete_body:\n%s\n", cJSON_Print(jsonstripe_checkout_complete_body_2));
}

int main() {
  test_stripe_checkout_complete_body(1);
  test_stripe_checkout_complete_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // stripe_checkout_complete_body_MAIN
#endif // stripe_checkout_complete_body_TEST
