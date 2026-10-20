#ifndef activity_v1_TEST
#define activity_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_v1.h"
activity_v1_t* instantiate_activity_v1(int include_optional);



activity_v1_t* instantiate_activity_v1(int include_optional) {
  activity_v1_t* activity_v1 = NULL;
  if (include_optional) {
    activity_v1 = activity_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      0,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    activity_v1 = activity_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      0,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return activity_v1;
}


#ifdef activity_v1_MAIN

void test_activity_v1(int include_optional) {
    activity_v1_t* activity_v1_1 = instantiate_activity_v1(include_optional);

	cJSON* jsonactivity_v1_1 = activity_v1_convertToJSON(activity_v1_1);
	printf("activity_v1 :\n%s\n", cJSON_Print(jsonactivity_v1_1));
	activity_v1_t* activity_v1_2 = activity_v1_parseFromJSON(jsonactivity_v1_1);
	cJSON* jsonactivity_v1_2 = activity_v1_convertToJSON(activity_v1_2);
	printf("repeating activity_v1:\n%s\n", cJSON_Print(jsonactivity_v1_2));
}

int main() {
  test_activity_v1(1);
  test_activity_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_v1_MAIN
#endif // activity_v1_TEST
