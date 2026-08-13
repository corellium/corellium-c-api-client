#ifndef available_trial_plan_list_TEST
#define available_trial_plan_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define available_trial_plan_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/available_trial_plan_list.h"
available_trial_plan_list_t* instantiate_available_trial_plan_list(int include_optional);



available_trial_plan_list_t* instantiate_available_trial_plan_list(int include_optional) {
  available_trial_plan_list_t* available_trial_plan_list = NULL;
  if (include_optional) {
    available_trial_plan_list = available_trial_plan_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    available_trial_plan_list = available_trial_plan_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return available_trial_plan_list;
}


#ifdef available_trial_plan_list_MAIN

void test_available_trial_plan_list(int include_optional) {
    available_trial_plan_list_t* available_trial_plan_list_1 = instantiate_available_trial_plan_list(include_optional);

	cJSON* jsonavailable_trial_plan_list_1 = available_trial_plan_list_convertToJSON(available_trial_plan_list_1);
	printf("available_trial_plan_list :\n%s\n", cJSON_Print(jsonavailable_trial_plan_list_1));
	available_trial_plan_list_t* available_trial_plan_list_2 = available_trial_plan_list_parseFromJSON(jsonavailable_trial_plan_list_1);
	cJSON* jsonavailable_trial_plan_list_2 = available_trial_plan_list_convertToJSON(available_trial_plan_list_2);
	printf("repeating available_trial_plan_list:\n%s\n", cJSON_Print(jsonavailable_trial_plan_list_2));
}

int main() {
  test_available_trial_plan_list(1);
  test_available_trial_plan_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // available_trial_plan_list_MAIN
#endif // available_trial_plan_list_TEST
