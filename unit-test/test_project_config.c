#ifndef project_config_TEST
#define project_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_config.h"
project_config_t* instantiate_project_config(int include_optional);



project_config_t* instantiate_project_config(int include_optional) {
  project_config_t* project_config = NULL;
  if (include_optional) {
    project_config = project_config_create(
      56
    );
  } else {
    project_config = project_config_create(
      56
    );
  }

  return project_config;
}


#ifdef project_config_MAIN

void test_project_config(int include_optional) {
    project_config_t* project_config_1 = instantiate_project_config(include_optional);

	cJSON* jsonproject_config_1 = project_config_convertToJSON(project_config_1);
	printf("project_config :\n%s\n", cJSON_Print(jsonproject_config_1));
	project_config_t* project_config_2 = project_config_parseFromJSON(jsonproject_config_1);
	cJSON* jsonproject_config_2 = project_config_convertToJSON(project_config_2);
	printf("repeating project_config:\n%s\n", cJSON_Print(jsonproject_config_2));
}

int main() {
  test_project_config(1);
  test_project_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_config_MAIN
#endif // project_config_TEST
