#ifndef activity_export_task_list_TEST
#define activity_export_task_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_export_task_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_export_task_list.h"
activity_export_task_list_t* instantiate_activity_export_task_list(int include_optional);



activity_export_task_list_t* instantiate_activity_export_task_list(int include_optional) {
  activity_export_task_list_t* activity_export_task_list = NULL;
  if (include_optional) {
    activity_export_task_list = activity_export_task_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    activity_export_task_list = activity_export_task_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return activity_export_task_list;
}


#ifdef activity_export_task_list_MAIN

void test_activity_export_task_list(int include_optional) {
    activity_export_task_list_t* activity_export_task_list_1 = instantiate_activity_export_task_list(include_optional);

	cJSON* jsonactivity_export_task_list_1 = activity_export_task_list_convertToJSON(activity_export_task_list_1);
	printf("activity_export_task_list :\n%s\n", cJSON_Print(jsonactivity_export_task_list_1));
	activity_export_task_list_t* activity_export_task_list_2 = activity_export_task_list_parseFromJSON(jsonactivity_export_task_list_1);
	cJSON* jsonactivity_export_task_list_2 = activity_export_task_list_convertToJSON(activity_export_task_list_2);
	printf("repeating activity_export_task_list:\n%s\n", cJSON_Print(jsonactivity_export_task_list_2));
}

int main() {
  test_activity_export_task_list(1);
  test_activity_export_task_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_export_task_list_MAIN
#endif // activity_export_task_list_TEST
