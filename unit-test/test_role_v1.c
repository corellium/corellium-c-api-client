#ifndef role_v1_TEST
#define role_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define role_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/role_v1.h"
role_v1_t* instantiate_role_v1(int include_optional);



role_v1_t* instantiate_role_v1(int include_optional) {
  role_v1_t* role_v1 = NULL;
  if (include_optional) {
    role_v1 = role_v1_create(
      corellium_api_role_v1_ROLE_admin,
      "0",
      "0",
      "0"
    );
  } else {
    role_v1 = role_v1_create(
      corellium_api_role_v1_ROLE_admin,
      "0",
      "0",
      "0"
    );
  }

  return role_v1;
}


#ifdef role_v1_MAIN

void test_role_v1(int include_optional) {
    role_v1_t* role_v1_1 = instantiate_role_v1(include_optional);

	cJSON* jsonrole_v1_1 = role_v1_convertToJSON(role_v1_1);
	printf("role_v1 :\n%s\n", cJSON_Print(jsonrole_v1_1));
	role_v1_t* role_v1_2 = role_v1_parseFromJSON(jsonrole_v1_1);
	cJSON* jsonrole_v1_2 = role_v1_convertToJSON(role_v1_2);
	printf("repeating role_v1:\n%s\n", cJSON_Print(jsonrole_v1_2));
}

int main() {
  test_role_v1(1);
  test_role_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // role_v1_MAIN
#endif // role_v1_TEST
