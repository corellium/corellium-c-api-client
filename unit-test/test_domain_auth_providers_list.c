#ifndef domain_auth_providers_list_TEST
#define domain_auth_providers_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_auth_providers_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_auth_providers_list.h"
domain_auth_providers_list_t* instantiate_domain_auth_providers_list(int include_optional);



domain_auth_providers_list_t* instantiate_domain_auth_providers_list(int include_optional) {
  domain_auth_providers_list_t* domain_auth_providers_list = NULL;
  if (include_optional) {
    domain_auth_providers_list = domain_auth_providers_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    domain_auth_providers_list = domain_auth_providers_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return domain_auth_providers_list;
}


#ifdef domain_auth_providers_list_MAIN

void test_domain_auth_providers_list(int include_optional) {
    domain_auth_providers_list_t* domain_auth_providers_list_1 = instantiate_domain_auth_providers_list(include_optional);

	cJSON* jsondomain_auth_providers_list_1 = domain_auth_providers_list_convertToJSON(domain_auth_providers_list_1);
	printf("domain_auth_providers_list :\n%s\n", cJSON_Print(jsondomain_auth_providers_list_1));
	domain_auth_providers_list_t* domain_auth_providers_list_2 = domain_auth_providers_list_parseFromJSON(jsondomain_auth_providers_list_1);
	cJSON* jsondomain_auth_providers_list_2 = domain_auth_providers_list_convertToJSON(domain_auth_providers_list_2);
	printf("repeating domain_auth_providers_list:\n%s\n", cJSON_Print(jsondomain_auth_providers_list_2));
}

int main() {
  test_domain_auth_providers_list(1);
  test_domain_auth_providers_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_auth_providers_list_MAIN
#endif // domain_auth_providers_list_TEST
