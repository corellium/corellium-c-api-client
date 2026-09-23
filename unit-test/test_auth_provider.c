#ifndef auth_provider_TEST
#define auth_provider_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define auth_provider_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/auth_provider.h"
auth_provider_t* instantiate_auth_provider(int include_optional);



auth_provider_t* instantiate_auth_provider(int include_optional) {
  auth_provider_t* auth_provider = NULL;
  if (include_optional) {
    auth_provider = auth_provider_create(
      "sso.example.com",
      "open-id-connect",
      true,
      false,
      "Log in with Okta",
      "Okta",
      "/api/v3/auth/providers/sso.example.com/authorization_url"
    );
  } else {
    auth_provider = auth_provider_create(
      "sso.example.com",
      "open-id-connect",
      true,
      false,
      "Log in with Okta",
      "Okta",
      "/api/v3/auth/providers/sso.example.com/authorization_url"
    );
  }

  return auth_provider;
}


#ifdef auth_provider_MAIN

void test_auth_provider(int include_optional) {
    auth_provider_t* auth_provider_1 = instantiate_auth_provider(include_optional);

	cJSON* jsonauth_provider_1 = auth_provider_convertToJSON(auth_provider_1);
	printf("auth_provider :\n%s\n", cJSON_Print(jsonauth_provider_1));
	auth_provider_t* auth_provider_2 = auth_provider_parseFromJSON(jsonauth_provider_1);
	cJSON* jsonauth_provider_2 = auth_provider_convertToJSON(auth_provider_2);
	printf("repeating auth_provider:\n%s\n", cJSON_Print(jsonauth_provider_2));
}

int main() {
  test_auth_provider(1);
  test_auth_provider(0);

  printf("Hello world \n");
  return 0;
}

#endif // auth_provider_MAIN
#endif // auth_provider_TEST
