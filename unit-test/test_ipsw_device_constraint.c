#ifndef ipsw_device_constraint_TEST
#define ipsw_device_constraint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipsw_device_constraint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipsw_device_constraint.h"
ipsw_device_constraint_t* instantiate_ipsw_device_constraint(int include_optional);



ipsw_device_constraint_t* instantiate_ipsw_device_constraint(int include_optional) {
  ipsw_device_constraint_t* ipsw_device_constraint = NULL;
  if (include_optional) {
    ipsw_device_constraint = ipsw_device_constraint_create(
      "0"
    );
  } else {
    ipsw_device_constraint = ipsw_device_constraint_create(
      "0"
    );
  }

  return ipsw_device_constraint;
}


#ifdef ipsw_device_constraint_MAIN

void test_ipsw_device_constraint(int include_optional) {
    ipsw_device_constraint_t* ipsw_device_constraint_1 = instantiate_ipsw_device_constraint(include_optional);

	cJSON* jsonipsw_device_constraint_1 = ipsw_device_constraint_convertToJSON(ipsw_device_constraint_1);
	printf("ipsw_device_constraint :\n%s\n", cJSON_Print(jsonipsw_device_constraint_1));
	ipsw_device_constraint_t* ipsw_device_constraint_2 = ipsw_device_constraint_parseFromJSON(jsonipsw_device_constraint_1);
	cJSON* jsonipsw_device_constraint_2 = ipsw_device_constraint_convertToJSON(ipsw_device_constraint_2);
	printf("repeating ipsw_device_constraint:\n%s\n", cJSON_Print(jsonipsw_device_constraint_2));
}

int main() {
  test_ipsw_device_constraint(1);
  test_ipsw_device_constraint(0);

  printf("Hello world \n");
  return 0;
}

#endif // ipsw_device_constraint_MAIN
#endif // ipsw_device_constraint_TEST
