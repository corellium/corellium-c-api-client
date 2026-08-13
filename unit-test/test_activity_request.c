#ifndef activity_request_TEST
#define activity_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_request.h"
activity_request_t* instantiate_activity_request(int include_optional);



activity_request_t* instantiate_activity_request(int include_optional) {
  activity_request_t* activity_request = NULL;
  if (include_optional) {
    activity_request = activity_request_create(
      "0",
      1.337,
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    activity_request = activity_request_create(
      "0",
      1.337,
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return activity_request;
}


#ifdef activity_request_MAIN

void test_activity_request(int include_optional) {
    activity_request_t* activity_request_1 = instantiate_activity_request(include_optional);

	cJSON* jsonactivity_request_1 = activity_request_convertToJSON(activity_request_1);
	printf("activity_request :\n%s\n", cJSON_Print(jsonactivity_request_1));
	activity_request_t* activity_request_2 = activity_request_parseFromJSON(jsonactivity_request_1);
	cJSON* jsonactivity_request_2 = activity_request_convertToJSON(activity_request_2);
	printf("repeating activity_request:\n%s\n", cJSON_Print(jsonactivity_request_2));
}

int main() {
  test_activity_request(1);
  test_activity_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_request_MAIN
#endif // activity_request_TEST
