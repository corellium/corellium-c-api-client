#ifndef ipsw_version_constraint_TEST
#define ipsw_version_constraint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipsw_version_constraint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipsw_version_constraint.h"
ipsw_version_constraint_t* instantiate_ipsw_version_constraint(int include_optional);



ipsw_version_constraint_t* instantiate_ipsw_version_constraint(int include_optional) {
  ipsw_version_constraint_t* ipsw_version_constraint = NULL;
  if (include_optional) {
    ipsw_version_constraint = ipsw_version_constraint_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    ipsw_version_constraint = ipsw_version_constraint_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return ipsw_version_constraint;
}


#ifdef ipsw_version_constraint_MAIN

void test_ipsw_version_constraint(int include_optional) {
    ipsw_version_constraint_t* ipsw_version_constraint_1 = instantiate_ipsw_version_constraint(include_optional);

	cJSON* jsonipsw_version_constraint_1 = ipsw_version_constraint_convertToJSON(ipsw_version_constraint_1);
	printf("ipsw_version_constraint :\n%s\n", cJSON_Print(jsonipsw_version_constraint_1));
	ipsw_version_constraint_t* ipsw_version_constraint_2 = ipsw_version_constraint_parseFromJSON(jsonipsw_version_constraint_1);
	cJSON* jsonipsw_version_constraint_2 = ipsw_version_constraint_convertToJSON(ipsw_version_constraint_2);
	printf("repeating ipsw_version_constraint:\n%s\n", cJSON_Print(jsonipsw_version_constraint_2));
}

int main() {
  test_ipsw_version_constraint(1);
  test_ipsw_version_constraint(0);

  printf("Hello world \n");
  return 0;
}

#endif // ipsw_version_constraint_MAIN
#endif // ipsw_version_constraint_TEST
