#ifndef instance_trace_state_TEST
#define instance_trace_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_trace_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_trace_state.h"
instance_trace_state_t* instantiate_instance_trace_state(int include_optional);



instance_trace_state_t* instantiate_instance_trace_state(int include_optional) {
  instance_trace_state_t* instance_trace_state = NULL;
  if (include_optional) {
    instance_trace_state = instance_trace_state_create(
      1,
      1.337,
      list_createList()
    );
  } else {
    instance_trace_state = instance_trace_state_create(
      1,
      1.337,
      list_createList()
    );
  }

  return instance_trace_state;
}


#ifdef instance_trace_state_MAIN

void test_instance_trace_state(int include_optional) {
    instance_trace_state_t* instance_trace_state_1 = instantiate_instance_trace_state(include_optional);

	cJSON* jsoninstance_trace_state_1 = instance_trace_state_convertToJSON(instance_trace_state_1);
	printf("instance_trace_state :\n%s\n", cJSON_Print(jsoninstance_trace_state_1));
	instance_trace_state_t* instance_trace_state_2 = instance_trace_state_parseFromJSON(jsoninstance_trace_state_1);
	cJSON* jsoninstance_trace_state_2 = instance_trace_state_convertToJSON(instance_trace_state_2);
	printf("repeating instance_trace_state:\n%s\n", cJSON_Print(jsoninstance_trace_state_2));
}

int main() {
  test_instance_trace_state(1);
  test_instance_trace_state(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_trace_state_MAIN
#endif // instance_trace_state_TEST
