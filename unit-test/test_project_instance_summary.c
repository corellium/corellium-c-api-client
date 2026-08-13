#ifndef project_instance_summary_TEST
#define project_instance_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_instance_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_instance_summary.h"
project_instance_summary_t* instantiate_project_instance_summary(int include_optional);



project_instance_summary_t* instantiate_project_instance_summary(int include_optional) {
  project_instance_summary_t* project_instance_summary = NULL;
  if (include_optional) {
    project_instance_summary = project_instance_summary_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    project_instance_summary = project_instance_summary_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return project_instance_summary;
}


#ifdef project_instance_summary_MAIN

void test_project_instance_summary(int include_optional) {
    project_instance_summary_t* project_instance_summary_1 = instantiate_project_instance_summary(include_optional);

	cJSON* jsonproject_instance_summary_1 = project_instance_summary_convertToJSON(project_instance_summary_1);
	printf("project_instance_summary :\n%s\n", cJSON_Print(jsonproject_instance_summary_1));
	project_instance_summary_t* project_instance_summary_2 = project_instance_summary_parseFromJSON(jsonproject_instance_summary_1);
	cJSON* jsonproject_instance_summary_2 = project_instance_summary_convertToJSON(project_instance_summary_2);
	printf("repeating project_instance_summary:\n%s\n", cJSON_Print(jsonproject_instance_summary_2));
}

int main() {
  test_project_instance_summary(1);
  test_project_instance_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_instance_summary_MAIN
#endif // project_instance_summary_TEST
