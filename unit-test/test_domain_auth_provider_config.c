#ifndef domain_auth_provider_config_TEST
#define domain_auth_provider_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_auth_provider_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_auth_provider_config.h"
domain_auth_provider_config_t* instantiate_domain_auth_provider_config(int include_optional);

#include "test_saml_identity_provider_config.c"
#include "test_saml_service_provider_config.c"
#include "test_ldap_user_attribute_mapping.c"
#include "test_ldap_server_connection_details.c"
#include "test_ldap_authentication_credentials.c"
#include "test_ldap_user_search_configuration.c"


domain_auth_provider_config_t* instantiate_domain_auth_provider_config(int include_optional) {
  domain_auth_provider_config_t* domain_auth_provider_config = NULL;
  if (include_optional) {
    domain_auth_provider_config = domain_auth_provider_config_create(
       // false, not to have infinite recursion
      instantiate_saml_identity_provider_config(0),
       // false, not to have infinite recursion
      instantiate_saml_service_provider_config(0),
       // false, not to have infinite recursion
      instantiate_ldap_user_attribute_mapping(0),
      list_createList(),
      "0",
      "0",
      "0",
      1,
       // false, not to have infinite recursion
      instantiate_ldap_server_connection_details(0),
       // false, not to have infinite recursion
      instantiate_ldap_authentication_credentials(0),
       // false, not to have infinite recursion
      instantiate_ldap_user_search_configuration(0),
      list_createList()
    );
  } else {
    domain_auth_provider_config = domain_auth_provider_config_create(
      NULL,
      NULL,
      NULL,
      list_createList(),
      "0",
      "0",
      "0",
      1,
      NULL,
      NULL,
      NULL,
      list_createList()
    );
  }

  return domain_auth_provider_config;
}


#ifdef domain_auth_provider_config_MAIN

void test_domain_auth_provider_config(int include_optional) {
    domain_auth_provider_config_t* domain_auth_provider_config_1 = instantiate_domain_auth_provider_config(include_optional);

	cJSON* jsondomain_auth_provider_config_1 = domain_auth_provider_config_convertToJSON(domain_auth_provider_config_1);
	printf("domain_auth_provider_config :\n%s\n", cJSON_Print(jsondomain_auth_provider_config_1));
	domain_auth_provider_config_t* domain_auth_provider_config_2 = domain_auth_provider_config_parseFromJSON(jsondomain_auth_provider_config_1);
	cJSON* jsondomain_auth_provider_config_2 = domain_auth_provider_config_convertToJSON(domain_auth_provider_config_2);
	printf("repeating domain_auth_provider_config:\n%s\n", cJSON_Print(jsondomain_auth_provider_config_2));
}

int main() {
  test_domain_auth_provider_config(1);
  test_domain_auth_provider_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_auth_provider_config_MAIN
#endif // domain_auth_provider_config_TEST
