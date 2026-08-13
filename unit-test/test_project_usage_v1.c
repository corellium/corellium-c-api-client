#ifndef project_usage_v1_TEST
#define project_usage_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_usage_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_usage_v1.h"
project_usage_v1_t* instantiate_project_usage_v1(int include_optional);



project_usage_v1_t* instantiate_project_usage_v1(int include_optional) {
  project_usage_v1_t* project_usage_v1 = NULL;
  if (include_optional) {
    project_usage_v1 = project_usage_v1_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    project_usage_v1 = project_usage_v1_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return project_usage_v1;
}


#ifdef project_usage_v1_MAIN

void test_project_usage_v1(int include_optional) {
    project_usage_v1_t* project_usage_v1_1 = instantiate_project_usage_v1(include_optional);

	cJSON* jsonproject_usage_v1_1 = project_usage_v1_convertToJSON(project_usage_v1_1);
	printf("project_usage_v1 :\n%s\n", cJSON_Print(jsonproject_usage_v1_1));
	project_usage_v1_t* project_usage_v1_2 = project_usage_v1_parseFromJSON(jsonproject_usage_v1_1);
	cJSON* jsonproject_usage_v1_2 = project_usage_v1_convertToJSON(project_usage_v1_2);
	printf("repeating project_usage_v1:\n%s\n", cJSON_Print(jsonproject_usage_v1_2));
}

int main() {
  test_project_usage_v1(1);
  test_project_usage_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_usage_v1_MAIN
#endif // project_usage_v1_TEST
