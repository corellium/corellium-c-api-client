#ifndef stripe_webhook_ack_TEST
#define stripe_webhook_ack_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stripe_webhook_ack_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stripe_webhook_ack.h"
stripe_webhook_ack_t* instantiate_stripe_webhook_ack(int include_optional);



stripe_webhook_ack_t* instantiate_stripe_webhook_ack(int include_optional) {
  stripe_webhook_ack_t* stripe_webhook_ack = NULL;
  if (include_optional) {
    stripe_webhook_ack = stripe_webhook_ack_create(
      1,
      "0"
    );
  } else {
    stripe_webhook_ack = stripe_webhook_ack_create(
      1,
      "0"
    );
  }

  return stripe_webhook_ack;
}


#ifdef stripe_webhook_ack_MAIN

void test_stripe_webhook_ack(int include_optional) {
    stripe_webhook_ack_t* stripe_webhook_ack_1 = instantiate_stripe_webhook_ack(include_optional);

	cJSON* jsonstripe_webhook_ack_1 = stripe_webhook_ack_convertToJSON(stripe_webhook_ack_1);
	printf("stripe_webhook_ack :\n%s\n", cJSON_Print(jsonstripe_webhook_ack_1));
	stripe_webhook_ack_t* stripe_webhook_ack_2 = stripe_webhook_ack_parseFromJSON(jsonstripe_webhook_ack_1);
	cJSON* jsonstripe_webhook_ack_2 = stripe_webhook_ack_convertToJSON(stripe_webhook_ack_2);
	printf("repeating stripe_webhook_ack:\n%s\n", cJSON_Print(jsonstripe_webhook_ack_2));
}

int main() {
  test_stripe_webhook_ack(1);
  test_stripe_webhook_ack(0);

  printf("Hello world \n");
  return 0;
}

#endif // stripe_webhook_ack_MAIN
#endif // stripe_webhook_ack_TEST
