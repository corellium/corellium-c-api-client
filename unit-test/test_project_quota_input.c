#ifndef project_quota_input_TEST
#define project_quota_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_quota_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_quota_input.h"
project_quota_input_t* instantiate_project_quota_input(int include_optional);



project_quota_input_t* instantiate_project_quota_input(int include_optional) {
  project_quota_input_t* project_quota_input = NULL;
  if (include_optional) {
    project_quota_input = project_quota_input_create(
      0,
      0,
      0
    );
  } else {
    project_quota_input = project_quota_input_create(
      0,
      0,
      0
    );
  }

  return project_quota_input;
}


#ifdef project_quota_input_MAIN

void test_project_quota_input(int include_optional) {
    project_quota_input_t* project_quota_input_1 = instantiate_project_quota_input(include_optional);

	cJSON* jsonproject_quota_input_1 = project_quota_input_convertToJSON(project_quota_input_1);
	printf("project_quota_input :\n%s\n", cJSON_Print(jsonproject_quota_input_1));
	project_quota_input_t* project_quota_input_2 = project_quota_input_parseFromJSON(jsonproject_quota_input_1);
	cJSON* jsonproject_quota_input_2 = project_quota_input_convertToJSON(project_quota_input_2);
	printf("repeating project_quota_input:\n%s\n", cJSON_Print(jsonproject_quota_input_2));
}

int main() {
  test_project_quota_input(1);
  test_project_quota_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_quota_input_MAIN
#endif // project_quota_input_TEST
