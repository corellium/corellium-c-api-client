#ifndef project_key_v1_TEST
#define project_key_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_key_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_key_v1.h"
project_key_v1_t* instantiate_project_key_v1(int include_optional);



project_key_v1_t* instantiate_project_key_v1(int include_optional) {
  project_key_v1_t* project_key_v1 = NULL;
  if (include_optional) {
    project_key_v1 = project_key_v1_create(
      "0",
      corellium_api_project_key_v1_KIND_ssh,
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    project_key_v1 = project_key_v1_create(
      "0",
      corellium_api_project_key_v1_KIND_ssh,
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return project_key_v1;
}


#ifdef project_key_v1_MAIN

void test_project_key_v1(int include_optional) {
    project_key_v1_t* project_key_v1_1 = instantiate_project_key_v1(include_optional);

	cJSON* jsonproject_key_v1_1 = project_key_v1_convertToJSON(project_key_v1_1);
	printf("project_key_v1 :\n%s\n", cJSON_Print(jsonproject_key_v1_1));
	project_key_v1_t* project_key_v1_2 = project_key_v1_parseFromJSON(jsonproject_key_v1_1);
	cJSON* jsonproject_key_v1_2 = project_key_v1_convertToJSON(project_key_v1_2);
	printf("repeating project_key_v1:\n%s\n", cJSON_Print(jsonproject_key_v1_2));
}

int main() {
  test_project_key_v1(1);
  test_project_key_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_key_v1_MAIN
#endif // project_key_v1_TEST
