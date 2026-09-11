#ifndef activity_resource_starts_with_filter_TEST
#define activity_resource_starts_with_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_resource_starts_with_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_resource_starts_with_filter.h"
activity_resource_starts_with_filter_t* instantiate_activity_resource_starts_with_filter(int include_optional);



activity_resource_starts_with_filter_t* instantiate_activity_resource_starts_with_filter(int include_optional) {
  activity_resource_starts_with_filter_t* activity_resource_starts_with_filter = NULL;
  if (include_optional) {
    activity_resource_starts_with_filter = activity_resource_starts_with_filter_create(
      0
    );
  } else {
    activity_resource_starts_with_filter = activity_resource_starts_with_filter_create(
      0
    );
  }

  return activity_resource_starts_with_filter;
}


#ifdef activity_resource_starts_with_filter_MAIN

void test_activity_resource_starts_with_filter(int include_optional) {
    activity_resource_starts_with_filter_t* activity_resource_starts_with_filter_1 = instantiate_activity_resource_starts_with_filter(include_optional);

	cJSON* jsonactivity_resource_starts_with_filter_1 = activity_resource_starts_with_filter_convertToJSON(activity_resource_starts_with_filter_1);
	printf("activity_resource_starts_with_filter :\n%s\n", cJSON_Print(jsonactivity_resource_starts_with_filter_1));
	activity_resource_starts_with_filter_t* activity_resource_starts_with_filter_2 = activity_resource_starts_with_filter_parseFromJSON(jsonactivity_resource_starts_with_filter_1);
	cJSON* jsonactivity_resource_starts_with_filter_2 = activity_resource_starts_with_filter_convertToJSON(activity_resource_starts_with_filter_2);
	printf("repeating activity_resource_starts_with_filter:\n%s\n", cJSON_Print(jsonactivity_resource_starts_with_filter_2));
}

int main() {
  test_activity_resource_starts_with_filter(1);
  test_activity_resource_starts_with_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_resource_starts_with_filter_MAIN
#endif // activity_resource_starts_with_filter_TEST
