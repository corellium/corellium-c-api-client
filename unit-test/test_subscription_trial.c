#ifndef subscription_trial_TEST
#define subscription_trial_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define subscription_trial_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/subscription_trial.h"
subscription_trial_t* instantiate_subscription_trial(int include_optional);



subscription_trial_t* instantiate_subscription_trial(int include_optional) {
  subscription_trial_t* subscription_trial = NULL;
  if (include_optional) {
    subscription_trial = subscription_trial_create(
      corellium_api_subscription_trial_STATUS_not_started,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      0,
      0
    );
  } else {
    subscription_trial = subscription_trial_create(
      corellium_api_subscription_trial_STATUS_not_started,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      0,
      0
    );
  }

  return subscription_trial;
}


#ifdef subscription_trial_MAIN

void test_subscription_trial(int include_optional) {
    subscription_trial_t* subscription_trial_1 = instantiate_subscription_trial(include_optional);

	cJSON* jsonsubscription_trial_1 = subscription_trial_convertToJSON(subscription_trial_1);
	printf("subscription_trial :\n%s\n", cJSON_Print(jsonsubscription_trial_1));
	subscription_trial_t* subscription_trial_2 = subscription_trial_parseFromJSON(jsonsubscription_trial_1);
	cJSON* jsonsubscription_trial_2 = subscription_trial_convertToJSON(subscription_trial_2);
	printf("repeating subscription_trial:\n%s\n", cJSON_Print(jsonsubscription_trial_2));
}

int main() {
  test_subscription_trial(1);
  test_subscription_trial(0);

  printf("Hello world \n");
  return 0;
}

#endif // subscription_trial_MAIN
#endif // subscription_trial_TEST
