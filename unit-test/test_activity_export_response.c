#ifndef activity_export_response_TEST
#define activity_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_export_response.h"
activity_export_response_t* instantiate_activity_export_response(int include_optional);



activity_export_response_t* instantiate_activity_export_response(int include_optional) {
  activity_export_response_t* activity_export_response = NULL;
  if (include_optional) {
    activity_export_response = activity_export_response_create(
      "0"
    );
  } else {
    activity_export_response = activity_export_response_create(
      "0"
    );
  }

  return activity_export_response;
}


#ifdef activity_export_response_MAIN

void test_activity_export_response(int include_optional) {
    activity_export_response_t* activity_export_response_1 = instantiate_activity_export_response(include_optional);

	cJSON* jsonactivity_export_response_1 = activity_export_response_convertToJSON(activity_export_response_1);
	printf("activity_export_response :\n%s\n", cJSON_Print(jsonactivity_export_response_1));
	activity_export_response_t* activity_export_response_2 = activity_export_response_parseFromJSON(jsonactivity_export_response_1);
	cJSON* jsonactivity_export_response_2 = activity_export_response_convertToJSON(activity_export_response_2);
	printf("repeating activity_export_response:\n%s\n", cJSON_Print(jsonactivity_export_response_2));
}

int main() {
  test_activity_export_response(1);
  test_activity_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_export_response_MAIN
#endif // activity_export_response_TEST
