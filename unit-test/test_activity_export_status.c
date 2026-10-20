#ifndef activity_export_status_TEST
#define activity_export_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_export_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_export_status.h"
activity_export_status_t* instantiate_activity_export_status(int include_optional);



activity_export_status_t* instantiate_activity_export_status(int include_optional) {
  activity_export_status_t* activity_export_status = NULL;
  if (include_optional) {
    activity_export_status = activity_export_status_create(
      corellium_api_activity_export_status_STATUS_in-progress
    );
  } else {
    activity_export_status = activity_export_status_create(
      corellium_api_activity_export_status_STATUS_in-progress
    );
  }

  return activity_export_status;
}


#ifdef activity_export_status_MAIN

void test_activity_export_status(int include_optional) {
    activity_export_status_t* activity_export_status_1 = instantiate_activity_export_status(include_optional);

	cJSON* jsonactivity_export_status_1 = activity_export_status_convertToJSON(activity_export_status_1);
	printf("activity_export_status :\n%s\n", cJSON_Print(jsonactivity_export_status_1));
	activity_export_status_t* activity_export_status_2 = activity_export_status_parseFromJSON(jsonactivity_export_status_1);
	cJSON* jsonactivity_export_status_2 = activity_export_status_convertToJSON(activity_export_status_2);
	printf("repeating activity_export_status:\n%s\n", cJSON_Print(jsonactivity_export_status_2));
}

int main() {
  test_activity_export_status(1);
  test_activity_export_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_export_status_MAIN
#endif // activity_export_status_TEST
