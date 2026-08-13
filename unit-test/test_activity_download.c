#ifndef activity_download_TEST
#define activity_download_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_download_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_download.h"
activity_download_t* instantiate_activity_download(int include_optional);

#include "test_activity_query_options.c"


activity_download_t* instantiate_activity_download(int include_optional) {
  activity_download_t* activity_download = NULL;
  if (include_optional) {
    activity_download = activity_download_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_activity_query_options(0)
    );
  } else {
    activity_download = activity_download_create(
      list_createList(),
      NULL
    );
  }

  return activity_download;
}


#ifdef activity_download_MAIN

void test_activity_download(int include_optional) {
    activity_download_t* activity_download_1 = instantiate_activity_download(include_optional);

	cJSON* jsonactivity_download_1 = activity_download_convertToJSON(activity_download_1);
	printf("activity_download :\n%s\n", cJSON_Print(jsonactivity_download_1));
	activity_download_t* activity_download_2 = activity_download_parseFromJSON(jsonactivity_download_1);
	cJSON* jsonactivity_download_2 = activity_download_convertToJSON(activity_download_2);
	printf("repeating activity_download:\n%s\n", cJSON_Print(jsonactivity_download_2));
}

int main() {
  test_activity_download(1);
  test_activity_download(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_download_MAIN
#endif // activity_download_TEST
