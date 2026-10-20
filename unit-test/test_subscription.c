#ifndef subscription_TEST
#define subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/subscription.h"
subscription_t* instantiate_subscription(int include_optional);

#include "test_subscription_trial.c"


subscription_t* instantiate_subscription(int include_optional) {
  subscription_t* subscription = NULL;
  if (include_optional) {
    subscription = subscription_create(
       // false, not to have infinite recursion
      instantiate_subscription_trial(0),
      "active",
      "usage",
      "Viper Essentials",
      "2027-01-15T00:00:00.000Z",
      true,
      false,
      true,
      "period_end"
    );
  } else {
    subscription = subscription_create(
      NULL,
      "active",
      "usage",
      "Viper Essentials",
      "2027-01-15T00:00:00.000Z",
      true,
      false,
      true,
      "period_end"
    );
  }

  return subscription;
}


#ifdef subscription_MAIN

void test_subscription(int include_optional) {
    subscription_t* subscription_1 = instantiate_subscription(include_optional);

	cJSON* jsonsubscription_1 = subscription_convertToJSON(subscription_1);
	printf("subscription :\n%s\n", cJSON_Print(jsonsubscription_1));
	subscription_t* subscription_2 = subscription_parseFromJSON(jsonsubscription_1);
	cJSON* jsonsubscription_2 = subscription_convertToJSON(subscription_2);
	printf("repeating subscription:\n%s\n", cJSON_Print(jsonsubscription_2));
}

int main() {
  test_subscription(1);
  test_subscription(0);

  printf("Hello world \n");
  return 0;
}

#endif // subscription_MAIN
#endif // subscription_TEST
