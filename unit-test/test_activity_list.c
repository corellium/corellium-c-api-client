#ifndef activity_list_TEST
#define activity_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_list.h"
activity_list_t* instantiate_activity_list(int include_optional);

#include "test_pagination.c"


activity_list_t* instantiate_activity_list(int include_optional) {
  activity_list_t* activity_list = NULL;
  if (include_optional) {
    activity_list = activity_list_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_pagination(0)
    );
  } else {
    activity_list = activity_list_create(
      list_createList(),
      NULL
    );
  }

  return activity_list;
}


#ifdef activity_list_MAIN

void test_activity_list(int include_optional) {
    activity_list_t* activity_list_1 = instantiate_activity_list(include_optional);

	cJSON* jsonactivity_list_1 = activity_list_convertToJSON(activity_list_1);
	printf("activity_list :\n%s\n", cJSON_Print(jsonactivity_list_1));
	activity_list_t* activity_list_2 = activity_list_parseFromJSON(jsonactivity_list_1);
	cJSON* jsonactivity_list_2 = activity_list_convertToJSON(activity_list_2);
	printf("repeating activity_list:\n%s\n", cJSON_Print(jsonactivity_list_2));
}

int main() {
  test_activity_list(1);
  test_activity_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_list_MAIN
#endif // activity_list_TEST
