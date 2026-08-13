#ifndef available_trial_plan_TEST
#define available_trial_plan_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define available_trial_plan_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/available_trial_plan.h"
available_trial_plan_t* instantiate_available_trial_plan(int include_optional);



available_trial_plan_t* instantiate_available_trial_plan(int include_optional) {
  available_trial_plan_t* available_trial_plan = NULL;
  if (include_optional) {
    available_trial_plan = available_trial_plan_create(
      "0",
      "0",
      "0",
      1,
      56,
      56,
      56
    );
  } else {
    available_trial_plan = available_trial_plan_create(
      "0",
      "0",
      "0",
      1,
      56,
      56,
      56
    );
  }

  return available_trial_plan;
}


#ifdef available_trial_plan_MAIN

void test_available_trial_plan(int include_optional) {
    available_trial_plan_t* available_trial_plan_1 = instantiate_available_trial_plan(include_optional);

	cJSON* jsonavailable_trial_plan_1 = available_trial_plan_convertToJSON(available_trial_plan_1);
	printf("available_trial_plan :\n%s\n", cJSON_Print(jsonavailable_trial_plan_1));
	available_trial_plan_t* available_trial_plan_2 = available_trial_plan_parseFromJSON(jsonavailable_trial_plan_1);
	cJSON* jsonavailable_trial_plan_2 = available_trial_plan_convertToJSON(available_trial_plan_2);
	printf("repeating available_trial_plan:\n%s\n", cJSON_Print(jsonavailable_trial_plan_2));
}

int main() {
  test_available_trial_plan(1);
  test_available_trial_plan(0);

  printf("Hello world \n");
  return 0;
}

#endif // available_trial_plan_MAIN
#endif // available_trial_plan_TEST
