#ifndef instance_snapshots_list_TEST
#define instance_snapshots_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_snapshots_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_snapshots_list.h"
instance_snapshots_list_t* instantiate_instance_snapshots_list(int include_optional);



instance_snapshots_list_t* instantiate_instance_snapshots_list(int include_optional) {
  instance_snapshots_list_t* instance_snapshots_list = NULL;
  if (include_optional) {
    instance_snapshots_list = instance_snapshots_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    instance_snapshots_list = instance_snapshots_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return instance_snapshots_list;
}


#ifdef instance_snapshots_list_MAIN

void test_instance_snapshots_list(int include_optional) {
    instance_snapshots_list_t* instance_snapshots_list_1 = instantiate_instance_snapshots_list(include_optional);

	cJSON* jsoninstance_snapshots_list_1 = instance_snapshots_list_convertToJSON(instance_snapshots_list_1);
	printf("instance_snapshots_list :\n%s\n", cJSON_Print(jsoninstance_snapshots_list_1));
	instance_snapshots_list_t* instance_snapshots_list_2 = instance_snapshots_list_parseFromJSON(jsoninstance_snapshots_list_1);
	cJSON* jsoninstance_snapshots_list_2 = instance_snapshots_list_convertToJSON(instance_snapshots_list_2);
	printf("repeating instance_snapshots_list:\n%s\n", cJSON_Print(jsoninstance_snapshots_list_2));
}

int main() {
  test_instance_snapshots_list(1);
  test_instance_snapshots_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_snapshots_list_MAIN
#endif // instance_snapshots_list_TEST
