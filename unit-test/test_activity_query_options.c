#ifndef activity_query_options_TEST
#define activity_query_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_query_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_query_options.h"
activity_query_options_t* instantiate_activity_query_options(int include_optional);



activity_query_options_t* instantiate_activity_query_options(int include_optional) {
  activity_query_options_t* activity_query_options = NULL;
  if (include_optional) {
    activity_query_options = activity_query_options_create(
      0,
      10,
      0,
      "-createdAt",
      "0",
      "0",
      "0",
      "0",
      "2026-05-22T13:58:34Z",
      "2026-05-22T00:00Z"
    );
  } else {
    activity_query_options = activity_query_options_create(
      0,
      10,
      0,
      "-createdAt",
      "0",
      "0",
      "0",
      "0",
      "2026-05-22T13:58:34Z",
      "2026-05-22T00:00Z"
    );
  }

  return activity_query_options;
}


#ifdef activity_query_options_MAIN

void test_activity_query_options(int include_optional) {
    activity_query_options_t* activity_query_options_1 = instantiate_activity_query_options(include_optional);

	cJSON* jsonactivity_query_options_1 = activity_query_options_convertToJSON(activity_query_options_1);
	printf("activity_query_options :\n%s\n", cJSON_Print(jsonactivity_query_options_1));
	activity_query_options_t* activity_query_options_2 = activity_query_options_parseFromJSON(jsonactivity_query_options_1);
	cJSON* jsonactivity_query_options_2 = activity_query_options_convertToJSON(activity_query_options_2);
	printf("repeating activity_query_options:\n%s\n", cJSON_Print(jsonactivity_query_options_2));
}

int main() {
  test_activity_query_options(1);
  test_activity_query_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_query_options_MAIN
#endif // activity_query_options_TEST
