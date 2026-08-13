#ifndef project_instance_list_TEST
#define project_instance_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_instance_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_instance_list.h"
project_instance_list_t* instantiate_project_instance_list(int include_optional);



project_instance_list_t* instantiate_project_instance_list(int include_optional) {
  project_instance_list_t* project_instance_list = NULL;
  if (include_optional) {
    project_instance_list = project_instance_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    project_instance_list = project_instance_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return project_instance_list;
}


#ifdef project_instance_list_MAIN

void test_project_instance_list(int include_optional) {
    project_instance_list_t* project_instance_list_1 = instantiate_project_instance_list(include_optional);

	cJSON* jsonproject_instance_list_1 = project_instance_list_convertToJSON(project_instance_list_1);
	printf("project_instance_list :\n%s\n", cJSON_Print(jsonproject_instance_list_1));
	project_instance_list_t* project_instance_list_2 = project_instance_list_parseFromJSON(jsonproject_instance_list_1);
	cJSON* jsonproject_instance_list_2 = project_instance_list_convertToJSON(project_instance_list_2);
	printf("repeating project_instance_list:\n%s\n", cJSON_Print(jsonproject_instance_list_2));
}

int main() {
  test_project_instance_list(1);
  test_project_instance_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_instance_list_MAIN
#endif // project_instance_list_TEST
