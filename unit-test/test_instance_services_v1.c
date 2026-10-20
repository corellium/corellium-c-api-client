#ifndef instance_services_v1_TEST
#define instance_services_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_services_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_services_v1.h"
instance_services_v1_t* instantiate_instance_services_v1(int include_optional);

#include "test_vpn_definition_v1.c"


instance_services_v1_t* instantiate_instance_services_v1(int include_optional) {
  instance_services_v1_t* instance_services_v1 = NULL;
  if (include_optional) {
    instance_services_v1 = instance_services_v1_create(
       // false, not to have infinite recursion
      instantiate_vpn_definition_v1(0)
    );
  } else {
    instance_services_v1 = instance_services_v1_create(
      NULL
    );
  }

  return instance_services_v1;
}


#ifdef instance_services_v1_MAIN

void test_instance_services_v1(int include_optional) {
    instance_services_v1_t* instance_services_v1_1 = instantiate_instance_services_v1(include_optional);

	cJSON* jsoninstance_services_v1_1 = instance_services_v1_convertToJSON(instance_services_v1_1);
	printf("instance_services_v1 :\n%s\n", cJSON_Print(jsoninstance_services_v1_1));
	instance_services_v1_t* instance_services_v1_2 = instance_services_v1_parseFromJSON(jsoninstance_services_v1_1);
	cJSON* jsoninstance_services_v1_2 = instance_services_v1_convertToJSON(instance_services_v1_2);
	printf("repeating instance_services_v1:\n%s\n", cJSON_Print(jsoninstance_services_v1_2));
}

int main() {
  test_instance_services_v1(1);
  test_instance_services_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_services_v1_MAIN
#endif // instance_services_v1_TEST
