#ifndef auth_provider_v1_TEST
#define auth_provider_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define auth_provider_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/auth_provider_v1.h"
auth_provider_v1_t* instantiate_auth_provider_v1(int include_optional);



auth_provider_v1_t* instantiate_auth_provider_v1(int include_optional) {
  auth_provider_v1_t* auth_provider_v1 = NULL;
  if (include_optional) {
    auth_provider_v1 = auth_provider_v1_create(
      "0",
      "0",
      "0",
      1,
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    auth_provider_v1 = auth_provider_v1_create(
      "0",
      "0",
      "0",
      1,
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return auth_provider_v1;
}


#ifdef auth_provider_v1_MAIN

void test_auth_provider_v1(int include_optional) {
    auth_provider_v1_t* auth_provider_v1_1 = instantiate_auth_provider_v1(include_optional);

	cJSON* jsonauth_provider_v1_1 = auth_provider_v1_convertToJSON(auth_provider_v1_1);
	printf("auth_provider_v1 :\n%s\n", cJSON_Print(jsonauth_provider_v1_1));
	auth_provider_v1_t* auth_provider_v1_2 = auth_provider_v1_parseFromJSON(jsonauth_provider_v1_1);
	cJSON* jsonauth_provider_v1_2 = auth_provider_v1_convertToJSON(auth_provider_v1_2);
	printf("repeating auth_provider_v1:\n%s\n", cJSON_Print(jsonauth_provider_v1_2));
}

int main() {
  test_auth_provider_v1(1);
  test_auth_provider_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // auth_provider_v1_MAIN
#endif // auth_provider_v1_TEST
