#ifndef auth_provider_type_TEST
#define auth_provider_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define auth_provider_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/auth_provider_type.h"
auth_provider_type_t* instantiate_auth_provider_type(int include_optional);



auth_provider_type_t* instantiate_auth_provider_type(int include_optional) {
  auth_provider_type_t* auth_provider_type = NULL;
  if (include_optional) {
    auth_provider_type = auth_provider_type_create(
      "0",
      0
    );
  } else {
    auth_provider_type = auth_provider_type_create(
      "0",
      0
    );
  }

  return auth_provider_type;
}


#ifdef auth_provider_type_MAIN

void test_auth_provider_type(int include_optional) {
    auth_provider_type_t* auth_provider_type_1 = instantiate_auth_provider_type(include_optional);

	cJSON* jsonauth_provider_type_1 = auth_provider_type_convertToJSON(auth_provider_type_1);
	printf("auth_provider_type :\n%s\n", cJSON_Print(jsonauth_provider_type_1));
	auth_provider_type_t* auth_provider_type_2 = auth_provider_type_parseFromJSON(jsonauth_provider_type_1);
	cJSON* jsonauth_provider_type_2 = auth_provider_type_convertToJSON(auth_provider_type_2);
	printf("repeating auth_provider_type:\n%s\n", cJSON_Print(jsonauth_provider_type_2));
}

int main() {
  test_auth_provider_type(1);
  test_auth_provider_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // auth_provider_type_MAIN
#endif // auth_provider_type_TEST
