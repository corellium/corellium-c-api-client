#ifndef role_name_TEST
#define role_name_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define role_name_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/role_name.h"
role_name_t* instantiate_role_name(int include_optional);



role_name_t* instantiate_role_name(int include_optional) {
  role_name_t* role_name = NULL;
  if (include_optional) {
    role_name = role_name_create(
    );
  } else {
    role_name = role_name_create(
    );
  }

  return role_name;
}


#ifdef role_name_MAIN

void test_role_name(int include_optional) {
    role_name_t* role_name_1 = instantiate_role_name(include_optional);

	cJSON* jsonrole_name_1 = role_name_convertToJSON(role_name_1);
	printf("role_name :\n%s\n", cJSON_Print(jsonrole_name_1));
	role_name_t* role_name_2 = role_name_parseFromJSON(jsonrole_name_1);
	cJSON* jsonrole_name_2 = role_name_convertToJSON(role_name_2);
	printf("repeating role_name:\n%s\n", cJSON_Print(jsonrole_name_2));
}

int main() {
  test_role_name(1);
  test_role_name(0);

  printf("Hello world \n");
  return 0;
}

#endif // role_name_MAIN
#endif // role_name_TEST
