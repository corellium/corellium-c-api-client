#ifndef activity_export_tasks_TEST
#define activity_export_tasks_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_export_tasks_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_export_tasks.h"
activity_export_tasks_t* instantiate_activity_export_tasks(int include_optional);



activity_export_tasks_t* instantiate_activity_export_tasks(int include_optional) {
  activity_export_tasks_t* activity_export_tasks = NULL;
  if (include_optional) {
    activity_export_tasks = activity_export_tasks_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      corellium_api_activity_export_tasks_STATUS_in-progress,
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    activity_export_tasks = activity_export_tasks_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      corellium_api_activity_export_tasks_STATUS_in-progress,
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return activity_export_tasks;
}


#ifdef activity_export_tasks_MAIN

void test_activity_export_tasks(int include_optional) {
    activity_export_tasks_t* activity_export_tasks_1 = instantiate_activity_export_tasks(include_optional);

	cJSON* jsonactivity_export_tasks_1 = activity_export_tasks_convertToJSON(activity_export_tasks_1);
	printf("activity_export_tasks :\n%s\n", cJSON_Print(jsonactivity_export_tasks_1));
	activity_export_tasks_t* activity_export_tasks_2 = activity_export_tasks_parseFromJSON(jsonactivity_export_tasks_1);
	cJSON* jsonactivity_export_tasks_2 = activity_export_tasks_convertToJSON(activity_export_tasks_2);
	printf("repeating activity_export_tasks:\n%s\n", cJSON_Print(jsonactivity_export_tasks_2));
}

int main() {
  test_activity_export_tasks(1);
  test_activity_export_tasks(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_export_tasks_MAIN
#endif // activity_export_tasks_TEST
