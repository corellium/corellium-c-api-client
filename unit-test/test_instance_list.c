#ifndef instance_list_TEST
#define instance_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_list.h"
instance_list_t* instantiate_instance_list(int include_optional);



instance_list_t* instantiate_instance_list(int include_optional) {
  instance_list_t* instance_list = NULL;
  if (include_optional) {
    instance_list = instance_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    instance_list = instance_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return instance_list;
}


#ifdef instance_list_MAIN

void test_instance_list(int include_optional) {
    instance_list_t* instance_list_1 = instantiate_instance_list(include_optional);

	cJSON* jsoninstance_list_1 = instance_list_convertToJSON(instance_list_1);
	printf("instance_list :\n%s\n", cJSON_Print(jsoninstance_list_1));
	instance_list_t* instance_list_2 = instance_list_parseFromJSON(jsoninstance_list_1);
	cJSON* jsoninstance_list_2 = instance_list_convertToJSON(instance_list_2);
	printf("repeating instance_list:\n%s\n", cJSON_Print(jsoninstance_list_2));
}

int main() {
  test_instance_list(1);
  test_instance_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_list_MAIN
#endif // instance_list_TEST
