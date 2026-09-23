#ifndef domain_auth_provider_response_TEST
#define domain_auth_provider_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_auth_provider_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_auth_provider_response.h"
domain_auth_provider_response_t* instantiate_domain_auth_provider_response(int include_optional);

#include "test_create_domain_auth_provider_response_config.c"


domain_auth_provider_response_t* instantiate_domain_auth_provider_response(int include_optional) {
  domain_auth_provider_response_t* domain_auth_provider_response = NULL;
  if (include_optional) {
    domain_auth_provider_response = domain_auth_provider_response_create(
      "8036ef76-8194-4a7c-95b2-42606a5d0171",
      null,
      "open-id-connect",
      "Log in with Okta",
      true,
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      false,
      "/api/v3/auth/providers/sso.example.com/authorization_url",
      "Okta",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    domain_auth_provider_response = domain_auth_provider_response_create(
      "8036ef76-8194-4a7c-95b2-42606a5d0171",
      null,
      "open-id-connect",
      "Log in with Okta",
      true,
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      false,
      "/api/v3/auth/providers/sso.example.com/authorization_url",
      "Okta",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return domain_auth_provider_response;
}


#ifdef domain_auth_provider_response_MAIN

void test_domain_auth_provider_response(int include_optional) {
    domain_auth_provider_response_t* domain_auth_provider_response_1 = instantiate_domain_auth_provider_response(include_optional);

	cJSON* jsondomain_auth_provider_response_1 = domain_auth_provider_response_convertToJSON(domain_auth_provider_response_1);
	printf("domain_auth_provider_response :\n%s\n", cJSON_Print(jsondomain_auth_provider_response_1));
	domain_auth_provider_response_t* domain_auth_provider_response_2 = domain_auth_provider_response_parseFromJSON(jsondomain_auth_provider_response_1);
	cJSON* jsondomain_auth_provider_response_2 = domain_auth_provider_response_convertToJSON(domain_auth_provider_response_2);
	printf("repeating domain_auth_provider_response:\n%s\n", cJSON_Print(jsondomain_auth_provider_response_2));
}

int main() {
  test_domain_auth_provider_response(1);
  test_domain_auth_provider_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_auth_provider_response_MAIN
#endif // domain_auth_provider_response_TEST
