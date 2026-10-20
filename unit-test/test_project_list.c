#ifndef project_list_TEST
#define project_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_list.h"
project_list_t* instantiate_project_list(int include_optional);



project_list_t* instantiate_project_list(int include_optional) {
  project_list_t* project_list = NULL;
  if (include_optional) {
    project_list = project_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    project_list = project_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return project_list;
}


#ifdef project_list_MAIN

void test_project_list(int include_optional) {
    project_list_t* project_list_1 = instantiate_project_list(include_optional);

	cJSON* jsonproject_list_1 = project_list_convertToJSON(project_list_1);
	printf("project_list :\n%s\n", cJSON_Print(jsonproject_list_1));
	project_list_t* project_list_2 = project_list_parseFromJSON(jsonproject_list_1);
	cJSON* jsonproject_list_2 = project_list_convertToJSON(project_list_2);
	printf("repeating project_list:\n%s\n", cJSON_Print(jsonproject_list_2));
}

int main() {
  test_project_list(1);
  test_project_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_list_MAIN
#endif // project_list_TEST
