#ifndef instance_v1_TEST
#define instance_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_v1.h"
instance_v1_t* instantiate_instance_v1(int include_optional);

#include "test_instance_restore_status_v1.c"
#include "test_instance_read_only_status_v1.c"
#include "test_instance_boot_options_v1.c"
#include "test_instance_services_v1.c"
#include "test_instance_agent_state_v1.c"
#include "test_instance_netmon_state_v1.c"
#include "test_instance_netdump_state_v1.c"
#include "test_instance_trace_state_v1.c"
#include "test_instance_hyper_trace_state_v1.c"
#include "test_created_by.c"


instance_v1_t* instantiate_instance_v1(int include_optional) {
  instance_v1_t* instance_v1 = NULL;
  if (include_optional) {
    instance_v1 = instance_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      corellium_api_instance_v1__on,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_instance_restore_status_v1(0),
       // false, not to have infinite recursion
      instantiate_instance_read_only_status_v1(0),
       // false, not to have infinite recursion
      instantiate_instance_boot_options_v1(0),
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_instance_services_v1(0),
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_instance_agent_state_v1(0),
       // false, not to have infinite recursion
      instantiate_instance_netmon_state_v1(0),
       // false, not to have infinite recursion
      instantiate_instance_netdump_state_v1(0),
       // false, not to have infinite recursion
      instantiate_instance_trace_state_v1(0),
       // false, not to have infinite recursion
      instantiate_instance_hyper_trace_state_v1(0),
      "0",
      1,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_created_by(0),
      1,
      1.337,
      1,
      1
    );
  } else {
    instance_v1 = instance_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      corellium_api_instance_v1__on,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      NULL,
      NULL,
      NULL,
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      list_createList(),
      NULL,
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "0",
      1,
      list_createList(),
      NULL,
      1,
      1.337,
      1,
      1
    );
  }

  return instance_v1;
}


#ifdef instance_v1_MAIN

void test_instance_v1(int include_optional) {
    instance_v1_t* instance_v1_1 = instantiate_instance_v1(include_optional);

	cJSON* jsoninstance_v1_1 = instance_v1_convertToJSON(instance_v1_1);
	printf("instance_v1 :\n%s\n", cJSON_Print(jsoninstance_v1_1));
	instance_v1_t* instance_v1_2 = instance_v1_parseFromJSON(jsoninstance_v1_1);
	cJSON* jsoninstance_v1_2 = instance_v1_convertToJSON(instance_v1_2);
	printf("repeating instance_v1:\n%s\n", cJSON_Print(jsoninstance_v1_2));
}

int main() {
  test_instance_v1(1);
  test_instance_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_v1_MAIN
#endif // instance_v1_TEST
