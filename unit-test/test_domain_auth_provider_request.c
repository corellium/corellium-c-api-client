#ifndef domain_auth_provider_request_TEST
#define domain_auth_provider_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_auth_provider_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_auth_provider_request.h"
domain_auth_provider_request_t* instantiate_domain_auth_provider_request(int include_optional);

#include "test_open_id_config_v1.c"


domain_auth_provider_request_t* instantiate_domain_auth_provider_request(int include_optional) {
  domain_auth_provider_request_t* domain_auth_provider_request = NULL;
  if (include_optional) {
    domain_auth_provider_request = domain_auth_provider_request_create(
      "0",
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_open_id_config_v1(0)
    );
  } else {
    domain_auth_provider_request = domain_auth_provider_request_create(
      "0",
      1,
      "0",
      NULL
    );
  }

  return domain_auth_provider_request;
}


#ifdef domain_auth_provider_request_MAIN

void test_domain_auth_provider_request(int include_optional) {
    domain_auth_provider_request_t* domain_auth_provider_request_1 = instantiate_domain_auth_provider_request(include_optional);

	cJSON* jsondomain_auth_provider_request_1 = domain_auth_provider_request_convertToJSON(domain_auth_provider_request_1);
	printf("domain_auth_provider_request :\n%s\n", cJSON_Print(jsondomain_auth_provider_request_1));
	domain_auth_provider_request_t* domain_auth_provider_request_2 = domain_auth_provider_request_parseFromJSON(jsondomain_auth_provider_request_1);
	cJSON* jsondomain_auth_provider_request_2 = domain_auth_provider_request_convertToJSON(domain_auth_provider_request_2);
	printf("repeating domain_auth_provider_request:\n%s\n", cJSON_Print(jsondomain_auth_provider_request_2));
}

int main() {
  test_domain_auth_provider_request(1);
  test_domain_auth_provider_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_auth_provider_request_MAIN
#endif // domain_auth_provider_request_TEST
