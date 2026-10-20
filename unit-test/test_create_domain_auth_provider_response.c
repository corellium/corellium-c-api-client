#ifndef create_domain_auth_provider_response_TEST
#define create_domain_auth_provider_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_domain_auth_provider_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_domain_auth_provider_response.h"
create_domain_auth_provider_response_t* instantiate_create_domain_auth_provider_response(int include_optional);

#include "test_create_domain_auth_provider_response_config.c"


create_domain_auth_provider_response_t* instantiate_create_domain_auth_provider_response(int include_optional) {
  create_domain_auth_provider_response_t* create_domain_auth_provider_response = NULL;
  if (include_optional) {
    create_domain_auth_provider_response = create_domain_auth_provider_response_create(
      "8036ef76-8194-4a7c-95b2-42606a5d0171",
      null,
      "open-id-connect",
      "Log in with Okta",
      true,
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      false,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    create_domain_auth_provider_response = create_domain_auth_provider_response_create(
      "8036ef76-8194-4a7c-95b2-42606a5d0171",
      null,
      "open-id-connect",
      "Log in with Okta",
      true,
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      false,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return create_domain_auth_provider_response;
}


#ifdef create_domain_auth_provider_response_MAIN

void test_create_domain_auth_provider_response(int include_optional) {
    create_domain_auth_provider_response_t* create_domain_auth_provider_response_1 = instantiate_create_domain_auth_provider_response(include_optional);

	cJSON* jsoncreate_domain_auth_provider_response_1 = create_domain_auth_provider_response_convertToJSON(create_domain_auth_provider_response_1);
	printf("create_domain_auth_provider_response :\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_response_1));
	create_domain_auth_provider_response_t* create_domain_auth_provider_response_2 = create_domain_auth_provider_response_parseFromJSON(jsoncreate_domain_auth_provider_response_1);
	cJSON* jsoncreate_domain_auth_provider_response_2 = create_domain_auth_provider_response_convertToJSON(create_domain_auth_provider_response_2);
	printf("repeating create_domain_auth_provider_response:\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_response_2));
}

int main() {
  test_create_domain_auth_provider_response(1);
  test_create_domain_auth_provider_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_domain_auth_provider_response_MAIN
#endif // create_domain_auth_provider_response_TEST
