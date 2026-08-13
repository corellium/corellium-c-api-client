#ifndef project_with_keys_v1_TEST
#define project_with_keys_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_with_keys_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_with_keys_v1.h"
project_with_keys_v1_t* instantiate_project_with_keys_v1(int include_optional);

#include "test_project_settings_v1.c"
#include "test_project_quota_v1.c"
#include "test_project_usage_v1.c"
#include "test_network_status_v1.c"


project_with_keys_v1_t* instantiate_project_with_keys_v1(int include_optional) {
  project_with_keys_v1_t* project_with_keys_v1 = NULL;
  if (include_optional) {
    project_with_keys_v1 = project_with_keys_v1_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_project_settings_v1(0),
       // false, not to have infinite recursion
      instantiate_project_quota_v1(0),
       // false, not to have infinite recursion
      instantiate_project_usage_v1(0),
       // false, not to have infinite recursion
      instantiate_network_status_v1(0),
      list_createList()
    );
  } else {
    project_with_keys_v1 = project_with_keys_v1_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL,
      NULL,
      list_createList()
    );
  }

  return project_with_keys_v1;
}


#ifdef project_with_keys_v1_MAIN

void test_project_with_keys_v1(int include_optional) {
    project_with_keys_v1_t* project_with_keys_v1_1 = instantiate_project_with_keys_v1(include_optional);

	cJSON* jsonproject_with_keys_v1_1 = project_with_keys_v1_convertToJSON(project_with_keys_v1_1);
	printf("project_with_keys_v1 :\n%s\n", cJSON_Print(jsonproject_with_keys_v1_1));
	project_with_keys_v1_t* project_with_keys_v1_2 = project_with_keys_v1_parseFromJSON(jsonproject_with_keys_v1_1);
	cJSON* jsonproject_with_keys_v1_2 = project_with_keys_v1_convertToJSON(project_with_keys_v1_2);
	printf("repeating project_with_keys_v1:\n%s\n", cJSON_Print(jsonproject_with_keys_v1_2));
}

int main() {
  test_project_with_keys_v1(1);
  test_project_with_keys_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_with_keys_v1_MAIN
#endif // project_with_keys_v1_TEST
