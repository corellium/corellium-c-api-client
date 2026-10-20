#ifndef instance_interface_TEST
#define instance_interface_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_interface_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_interface.h"
instance_interface_t* instantiate_instance_interface(int include_optional);



instance_interface_t* instantiate_instance_interface(int include_optional) {
  instance_interface_t* instance_interface = NULL;
  if (include_optional) {
    instance_interface = instance_interface_create(
      "0",
      "0"
    );
  } else {
    instance_interface = instance_interface_create(
      "0",
      "0"
    );
  }

  return instance_interface;
}


#ifdef instance_interface_MAIN

void test_instance_interface(int include_optional) {
    instance_interface_t* instance_interface_1 = instantiate_instance_interface(include_optional);

	cJSON* jsoninstance_interface_1 = instance_interface_convertToJSON(instance_interface_1);
	printf("instance_interface :\n%s\n", cJSON_Print(jsoninstance_interface_1));
	instance_interface_t* instance_interface_2 = instance_interface_parseFromJSON(jsoninstance_interface_1);
	cJSON* jsoninstance_interface_2 = instance_interface_convertToJSON(instance_interface_2);
	printf("repeating instance_interface:\n%s\n", cJSON_Print(jsoninstance_interface_2));
}

int main() {
  test_instance_interface(1);
  test_instance_interface(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_interface_MAIN
#endif // instance_interface_TEST
