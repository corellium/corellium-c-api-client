#ifndef instance_netdump_state_TEST
#define instance_netdump_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_netdump_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_netdump_state.h"
instance_netdump_state_t* instantiate_instance_netdump_state(int include_optional);



instance_netdump_state_t* instantiate_instance_netdump_state(int include_optional) {
  instance_netdump_state_t* instance_netdump_state = NULL;
  if (include_optional) {
    instance_netdump_state = instance_netdump_state_create(
      "0",
      "0",
      1
    );
  } else {
    instance_netdump_state = instance_netdump_state_create(
      "0",
      "0",
      1
    );
  }

  return instance_netdump_state;
}


#ifdef instance_netdump_state_MAIN

void test_instance_netdump_state(int include_optional) {
    instance_netdump_state_t* instance_netdump_state_1 = instantiate_instance_netdump_state(include_optional);

	cJSON* jsoninstance_netdump_state_1 = instance_netdump_state_convertToJSON(instance_netdump_state_1);
	printf("instance_netdump_state :\n%s\n", cJSON_Print(jsoninstance_netdump_state_1));
	instance_netdump_state_t* instance_netdump_state_2 = instance_netdump_state_parseFromJSON(jsoninstance_netdump_state_1);
	cJSON* jsoninstance_netdump_state_2 = instance_netdump_state_convertToJSON(instance_netdump_state_2);
	printf("repeating instance_netdump_state:\n%s\n", cJSON_Print(jsoninstance_netdump_state_2));
}

int main() {
  test_instance_netdump_state(1);
  test_instance_netdump_state(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_netdump_state_MAIN
#endif // instance_netdump_state_TEST
