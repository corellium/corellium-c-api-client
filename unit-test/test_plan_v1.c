#ifndef plan_v1_TEST
#define plan_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plan_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plan_v1.h"
plan_v1_t* instantiate_plan_v1(int include_optional);



plan_v1_t* instantiate_plan_v1(int include_optional) {
  plan_v1_t* plan_v1 = NULL;
  if (include_optional) {
    plan_v1 = plan_v1_create(
      "0",
      "0"
    );
  } else {
    plan_v1 = plan_v1_create(
      "0",
      "0"
    );
  }

  return plan_v1;
}


#ifdef plan_v1_MAIN

void test_plan_v1(int include_optional) {
    plan_v1_t* plan_v1_1 = instantiate_plan_v1(include_optional);

	cJSON* jsonplan_v1_1 = plan_v1_convertToJSON(plan_v1_1);
	printf("plan_v1 :\n%s\n", cJSON_Print(jsonplan_v1_1));
	plan_v1_t* plan_v1_2 = plan_v1_parseFromJSON(jsonplan_v1_1);
	cJSON* jsonplan_v1_2 = plan_v1_convertToJSON(plan_v1_2);
	printf("repeating plan_v1:\n%s\n", cJSON_Print(jsonplan_v1_2));
}

int main() {
  test_plan_v1(1);
  test_plan_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // plan_v1_MAIN
#endif // plan_v1_TEST
