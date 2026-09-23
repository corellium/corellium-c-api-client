#ifndef instance_hyper_trace_state_TEST
#define instance_hyper_trace_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_hyper_trace_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_hyper_trace_state.h"
instance_hyper_trace_state_t* instantiate_instance_hyper_trace_state(int include_optional);



instance_hyper_trace_state_t* instantiate_instance_hyper_trace_state(int include_optional) {
  instance_hyper_trace_state_t* instance_hyper_trace_state = NULL;
  if (include_optional) {
    instance_hyper_trace_state = instance_hyper_trace_state_create(
      corellium_api_instance_hyper_trace_state_ENABLED_enabling,
      1048576,
      list_createList()
    );
  } else {
    instance_hyper_trace_state = instance_hyper_trace_state_create(
      corellium_api_instance_hyper_trace_state_ENABLED_enabling,
      1048576,
      list_createList()
    );
  }

  return instance_hyper_trace_state;
}


#ifdef instance_hyper_trace_state_MAIN

void test_instance_hyper_trace_state(int include_optional) {
    instance_hyper_trace_state_t* instance_hyper_trace_state_1 = instantiate_instance_hyper_trace_state(include_optional);

	cJSON* jsoninstance_hyper_trace_state_1 = instance_hyper_trace_state_convertToJSON(instance_hyper_trace_state_1);
	printf("instance_hyper_trace_state :\n%s\n", cJSON_Print(jsoninstance_hyper_trace_state_1));
	instance_hyper_trace_state_t* instance_hyper_trace_state_2 = instance_hyper_trace_state_parseFromJSON(jsoninstance_hyper_trace_state_1);
	cJSON* jsoninstance_hyper_trace_state_2 = instance_hyper_trace_state_convertToJSON(instance_hyper_trace_state_2);
	printf("repeating instance_hyper_trace_state:\n%s\n", cJSON_Print(jsoninstance_hyper_trace_state_2));
}

int main() {
  test_instance_hyper_trace_state(1);
  test_instance_hyper_trace_state(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_hyper_trace_state_MAIN
#endif // instance_hyper_trace_state_TEST
