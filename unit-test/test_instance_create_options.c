#ifndef instance_create_options_TEST
#define instance_create_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_create_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_create_options.h"
instance_create_options_t* instantiate_instance_create_options(int include_optional);



instance_create_options_t* instantiate_instance_create_options(int include_optional) {
  instance_create_options_t* instance_create_options = NULL;
  if (include_optional) {
    instance_create_options = instance_create_options_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      1,
      "0",
      1
    );
  } else {
    instance_create_options = instance_create_options_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      1,
      "0",
      1
    );
  }

  return instance_create_options;
}


#ifdef instance_create_options_MAIN

void test_instance_create_options(int include_optional) {
    instance_create_options_t* instance_create_options_1 = instantiate_instance_create_options(include_optional);

	cJSON* jsoninstance_create_options_1 = instance_create_options_convertToJSON(instance_create_options_1);
	printf("instance_create_options :\n%s\n", cJSON_Print(jsoninstance_create_options_1));
	instance_create_options_t* instance_create_options_2 = instance_create_options_parseFromJSON(jsoninstance_create_options_1);
	cJSON* jsoninstance_create_options_2 = instance_create_options_convertToJSON(instance_create_options_2);
	printf("repeating instance_create_options:\n%s\n", cJSON_Print(jsoninstance_create_options_2));
}

int main() {
  test_instance_create_options(1);
  test_instance_create_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_create_options_MAIN
#endif // instance_create_options_TEST
