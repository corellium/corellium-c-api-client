#ifndef instance_trace_filter_TEST
#define instance_trace_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_trace_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_trace_filter.h"
instance_trace_filter_t* instantiate_instance_trace_filter(int include_optional);



instance_trace_filter_t* instantiate_instance_trace_filter(int include_optional) {
  instance_trace_filter_t* instance_trace_filter = NULL;
  if (include_optional) {
    instance_trace_filter = instance_trace_filter_create(
      "pid",
      "1234"
    );
  } else {
    instance_trace_filter = instance_trace_filter_create(
      "pid",
      "1234"
    );
  }

  return instance_trace_filter;
}


#ifdef instance_trace_filter_MAIN

void test_instance_trace_filter(int include_optional) {
    instance_trace_filter_t* instance_trace_filter_1 = instantiate_instance_trace_filter(include_optional);

	cJSON* jsoninstance_trace_filter_1 = instance_trace_filter_convertToJSON(instance_trace_filter_1);
	printf("instance_trace_filter :\n%s\n", cJSON_Print(jsoninstance_trace_filter_1));
	instance_trace_filter_t* instance_trace_filter_2 = instance_trace_filter_parseFromJSON(jsoninstance_trace_filter_1);
	cJSON* jsoninstance_trace_filter_2 = instance_trace_filter_convertToJSON(instance_trace_filter_2);
	printf("repeating instance_trace_filter:\n%s\n", cJSON_Print(jsoninstance_trace_filter_2));
}

int main() {
  test_instance_trace_filter(1);
  test_instance_trace_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_trace_filter_MAIN
#endif // instance_trace_filter_TEST
