#ifndef instance_hyper_trace_state_v1_TEST
#define instance_hyper_trace_state_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_hyper_trace_state_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_hyper_trace_state_v1.h"
instance_hyper_trace_state_v1_t* instantiate_instance_hyper_trace_state_v1(int include_optional);



instance_hyper_trace_state_v1_t* instantiate_instance_hyper_trace_state_v1(int include_optional) {
  instance_hyper_trace_state_v1_t* instance_hyper_trace_state_v1 = NULL;
  if (include_optional) {
    instance_hyper_trace_state_v1 = instance_hyper_trace_state_v1_create(
      corellium_api_instance_hyper_trace_state_v1_ENABLED_enabling,
      1.337,
      "0"
    );
  } else {
    instance_hyper_trace_state_v1 = instance_hyper_trace_state_v1_create(
      corellium_api_instance_hyper_trace_state_v1_ENABLED_enabling,
      1.337,
      "0"
    );
  }

  return instance_hyper_trace_state_v1;
}


#ifdef instance_hyper_trace_state_v1_MAIN

void test_instance_hyper_trace_state_v1(int include_optional) {
    instance_hyper_trace_state_v1_t* instance_hyper_trace_state_v1_1 = instantiate_instance_hyper_trace_state_v1(include_optional);

	cJSON* jsoninstance_hyper_trace_state_v1_1 = instance_hyper_trace_state_v1_convertToJSON(instance_hyper_trace_state_v1_1);
	printf("instance_hyper_trace_state_v1 :\n%s\n", cJSON_Print(jsoninstance_hyper_trace_state_v1_1));
	instance_hyper_trace_state_v1_t* instance_hyper_trace_state_v1_2 = instance_hyper_trace_state_v1_parseFromJSON(jsoninstance_hyper_trace_state_v1_1);
	cJSON* jsoninstance_hyper_trace_state_v1_2 = instance_hyper_trace_state_v1_convertToJSON(instance_hyper_trace_state_v1_2);
	printf("repeating instance_hyper_trace_state_v1:\n%s\n", cJSON_Print(jsoninstance_hyper_trace_state_v1_2));
}

int main() {
  test_instance_hyper_trace_state_v1(1);
  test_instance_hyper_trace_state_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_hyper_trace_state_v1_MAIN
#endif // instance_hyper_trace_state_v1_TEST
