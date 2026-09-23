#ifndef project_list_item_TEST
#define project_list_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_list_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_list_item.h"
project_list_item_t* instantiate_project_list_item(int include_optional);

#include "test_project_settings.c"
#include "test_project_quota.c"
#include "test_project_usage.c"
#include "test_network_status.c"
#include "test_project_config.c"


project_list_item_t* instantiate_project_list_item(int include_optional) {
  project_list_item_t* project_list_item = NULL;
  if (include_optional) {
    project_list_item = project_list_item_create(
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "Default Project",
       // false, not to have infinite recursion
      instantiate_project_settings(0),
       // false, not to have infinite recursion
      instantiate_project_quota(0),
       // false, not to have infinite recursion
      instantiate_project_usage(0),
       // false, not to have infinite recursion
      instantiate_network_status(0),
       // false, not to have infinite recursion
      instantiate_project_config(0),
      2
    );
  } else {
    project_list_item = project_list_item_create(
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "Default Project",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      2
    );
  }

  return project_list_item;
}


#ifdef project_list_item_MAIN

void test_project_list_item(int include_optional) {
    project_list_item_t* project_list_item_1 = instantiate_project_list_item(include_optional);

	cJSON* jsonproject_list_item_1 = project_list_item_convertToJSON(project_list_item_1);
	printf("project_list_item :\n%s\n", cJSON_Print(jsonproject_list_item_1));
	project_list_item_t* project_list_item_2 = project_list_item_parseFromJSON(jsonproject_list_item_1);
	cJSON* jsonproject_list_item_2 = project_list_item_convertToJSON(project_list_item_2);
	printf("repeating project_list_item:\n%s\n", cJSON_Print(jsonproject_list_item_2));
}

int main() {
  test_project_list_item(1);
  test_project_list_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_list_item_MAIN
#endif // project_list_item_TEST
