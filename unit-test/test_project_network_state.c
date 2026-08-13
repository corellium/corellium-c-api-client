#ifndef project_network_state_TEST
#define project_network_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_network_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_network_state.h"
project_network_state_t* instantiate_project_network_state(int include_optional);



project_network_state_t* instantiate_project_network_state(int include_optional) {
  project_network_state_t* project_network_state = NULL;
  if (include_optional) {
    project_network_state = project_network_state_create(
      "0",
      0
    );
  } else {
    project_network_state = project_network_state_create(
      "0",
      0
    );
  }

  return project_network_state;
}


#ifdef project_network_state_MAIN

void test_project_network_state(int include_optional) {
    project_network_state_t* project_network_state_1 = instantiate_project_network_state(include_optional);

	cJSON* jsonproject_network_state_1 = project_network_state_convertToJSON(project_network_state_1);
	printf("project_network_state :\n%s\n", cJSON_Print(jsonproject_network_state_1));
	project_network_state_t* project_network_state_2 = project_network_state_parseFromJSON(jsonproject_network_state_1);
	cJSON* jsonproject_network_state_2 = project_network_state_convertToJSON(project_network_state_2);
	printf("repeating project_network_state:\n%s\n", cJSON_Print(jsonproject_network_state_2));
}

int main() {
  test_project_network_state(1);
  test_project_network_state(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_network_state_MAIN
#endif // project_network_state_TEST
