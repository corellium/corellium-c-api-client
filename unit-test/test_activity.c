#ifndef activity_TEST
#define activity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity.h"
activity_t* instantiate_activity(int include_optional);



activity_t* instantiate_activity(int include_optional) {
  activity_t* activity = NULL;
  if (include_optional) {
    activity = activity_create(
      "5927ac2a-fdd4-4ab5-860f-28eec3511028",
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "0",
      corellium_api_activity_OUTCOME_success,
      {"name":"My iPhone 13 Pro"},
      "7.4.0-28212",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    activity = activity_create(
      "5927ac2a-fdd4-4ab5-860f-28eec3511028",
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "0",
      corellium_api_activity_OUTCOME_success,
      {"name":"My iPhone 13 Pro"},
      "7.4.0-28212",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return activity;
}


#ifdef activity_MAIN

void test_activity(int include_optional) {
    activity_t* activity_1 = instantiate_activity(include_optional);

	cJSON* jsonactivity_1 = activity_convertToJSON(activity_1);
	printf("activity :\n%s\n", cJSON_Print(jsonactivity_1));
	activity_t* activity_2 = activity_parseFromJSON(jsonactivity_1);
	cJSON* jsonactivity_2 = activity_convertToJSON(activity_2);
	printf("repeating activity:\n%s\n", cJSON_Print(jsonactivity_2));
}

int main() {
  test_activity(1);
  test_activity(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_MAIN
#endif // activity_TEST
