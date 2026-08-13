#ifndef project_v1_TEST
#define project_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_v1.h"
project_v1_t* instantiate_project_v1(int include_optional);

#include "test_project_settings_v1.c"
#include "test_project_quota_v1.c"
#include "test_project_usage_v1.c"
#include "test_network_status_v1.c"


project_v1_t* instantiate_project_v1(int include_optional) {
  project_v1_t* project_v1 = NULL;
  if (include_optional) {
    project_v1 = project_v1_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_project_settings_v1(0),
       // false, not to have infinite recursion
      instantiate_project_quota_v1(0),
       // false, not to have infinite recursion
      instantiate_project_usage_v1(0),
       // false, not to have infinite recursion
      instantiate_network_status_v1(0)
    );
  } else {
    project_v1 = project_v1_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return project_v1;
}


#ifdef project_v1_MAIN

void test_project_v1(int include_optional) {
    project_v1_t* project_v1_1 = instantiate_project_v1(include_optional);

	cJSON* jsonproject_v1_1 = project_v1_convertToJSON(project_v1_1);
	printf("project_v1 :\n%s\n", cJSON_Print(jsonproject_v1_1));
	project_v1_t* project_v1_2 = project_v1_parseFromJSON(jsonproject_v1_1);
	cJSON* jsonproject_v1_2 = project_v1_convertToJSON(project_v1_2);
	printf("repeating project_v1:\n%s\n", cJSON_Print(jsonproject_v1_2));
}

int main() {
  test_project_v1(1);
  test_project_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_v1_MAIN
#endif // project_v1_TEST
