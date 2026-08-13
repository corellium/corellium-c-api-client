#ifndef project_key_list_TEST
#define project_key_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_key_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_key_list.h"
project_key_list_t* instantiate_project_key_list(int include_optional);



project_key_list_t* instantiate_project_key_list(int include_optional) {
  project_key_list_t* project_key_list = NULL;
  if (include_optional) {
    project_key_list = project_key_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    project_key_list = project_key_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return project_key_list;
}


#ifdef project_key_list_MAIN

void test_project_key_list(int include_optional) {
    project_key_list_t* project_key_list_1 = instantiate_project_key_list(include_optional);

	cJSON* jsonproject_key_list_1 = project_key_list_convertToJSON(project_key_list_1);
	printf("project_key_list :\n%s\n", cJSON_Print(jsonproject_key_list_1));
	project_key_list_t* project_key_list_2 = project_key_list_parseFromJSON(jsonproject_key_list_1);
	cJSON* jsonproject_key_list_2 = project_key_list_convertToJSON(project_key_list_2);
	printf("repeating project_key_list:\n%s\n", cJSON_Print(jsonproject_key_list_2));
}

int main() {
  test_project_key_list(1);
  test_project_key_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_key_list_MAIN
#endif // project_key_list_TEST
