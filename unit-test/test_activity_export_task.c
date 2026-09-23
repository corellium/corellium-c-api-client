#ifndef activity_export_task_TEST
#define activity_export_task_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_export_task_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_export_task.h"
activity_export_task_t* instantiate_activity_export_task(int include_optional);



activity_export_task_t* instantiate_activity_export_task(int include_optional) {
  activity_export_task_t* activity_export_task = NULL;
  if (include_optional) {
    activity_export_task = activity_export_task_create(
      "activity-export/722cdce5-6f71-4f4a-b2b6-c00f11c015f6",
      "2026-03-14T09:12:47Z",
      corellium_api_activity_export_task_STATUS_in-progress,
      {"handlerName":"activity-export","exportType":"text/csv","domainId":"c29762d1-45d7-489d-a3a2-9dadc43978ba","userId":"e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320","apiVersion":"v3"},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    activity_export_task = activity_export_task_create(
      "activity-export/722cdce5-6f71-4f4a-b2b6-c00f11c015f6",
      "2026-03-14T09:12:47Z",
      corellium_api_activity_export_task_STATUS_in-progress,
      {"handlerName":"activity-export","exportType":"text/csv","domainId":"c29762d1-45d7-489d-a3a2-9dadc43978ba","userId":"e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320","apiVersion":"v3"},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return activity_export_task;
}


#ifdef activity_export_task_MAIN

void test_activity_export_task(int include_optional) {
    activity_export_task_t* activity_export_task_1 = instantiate_activity_export_task(include_optional);

	cJSON* jsonactivity_export_task_1 = activity_export_task_convertToJSON(activity_export_task_1);
	printf("activity_export_task :\n%s\n", cJSON_Print(jsonactivity_export_task_1));
	activity_export_task_t* activity_export_task_2 = activity_export_task_parseFromJSON(jsonactivity_export_task_1);
	cJSON* jsonactivity_export_task_2 = activity_export_task_convertToJSON(activity_export_task_2);
	printf("repeating activity_export_task:\n%s\n", cJSON_Print(jsonactivity_export_task_2));
}

int main() {
  test_activity_export_task(1);
  test_activity_export_task(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_export_task_MAIN
#endif // activity_export_task_TEST
