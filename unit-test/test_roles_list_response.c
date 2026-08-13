#ifndef roles_list_response_TEST
#define roles_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define roles_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/roles_list_response.h"
roles_list_response_t* instantiate_roles_list_response(int include_optional);



roles_list_response_t* instantiate_roles_list_response(int include_optional) {
  roles_list_response_t* roles_list_response = NULL;
  if (include_optional) {
    roles_list_response = roles_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    roles_list_response = roles_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return roles_list_response;
}


#ifdef roles_list_response_MAIN

void test_roles_list_response(int include_optional) {
    roles_list_response_t* roles_list_response_1 = instantiate_roles_list_response(include_optional);

	cJSON* jsonroles_list_response_1 = roles_list_response_convertToJSON(roles_list_response_1);
	printf("roles_list_response :\n%s\n", cJSON_Print(jsonroles_list_response_1));
	roles_list_response_t* roles_list_response_2 = roles_list_response_parseFromJSON(jsonroles_list_response_1);
	cJSON* jsonroles_list_response_2 = roles_list_response_convertToJSON(roles_list_response_2);
	printf("repeating roles_list_response:\n%s\n", cJSON_Print(jsonroles_list_response_2));
}

int main() {
  test_roles_list_response(1);
  test_roles_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // roles_list_response_MAIN
#endif // roles_list_response_TEST
