#ifndef auth_providers_list_response_TEST
#define auth_providers_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define auth_providers_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/auth_providers_list_response.h"
auth_providers_list_response_t* instantiate_auth_providers_list_response(int include_optional);



auth_providers_list_response_t* instantiate_auth_providers_list_response(int include_optional) {
  auth_providers_list_response_t* auth_providers_list_response = NULL;
  if (include_optional) {
    auth_providers_list_response = auth_providers_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    auth_providers_list_response = auth_providers_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return auth_providers_list_response;
}


#ifdef auth_providers_list_response_MAIN

void test_auth_providers_list_response(int include_optional) {
    auth_providers_list_response_t* auth_providers_list_response_1 = instantiate_auth_providers_list_response(include_optional);

	cJSON* jsonauth_providers_list_response_1 = auth_providers_list_response_convertToJSON(auth_providers_list_response_1);
	printf("auth_providers_list_response :\n%s\n", cJSON_Print(jsonauth_providers_list_response_1));
	auth_providers_list_response_t* auth_providers_list_response_2 = auth_providers_list_response_parseFromJSON(jsonauth_providers_list_response_1);
	cJSON* jsonauth_providers_list_response_2 = auth_providers_list_response_convertToJSON(auth_providers_list_response_2);
	printf("repeating auth_providers_list_response:\n%s\n", cJSON_Print(jsonauth_providers_list_response_2));
}

int main() {
  test_auth_providers_list_response(1);
  test_auth_providers_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // auth_providers_list_response_MAIN
#endif // auth_providers_list_response_TEST
