#ifndef create_domain_auth_provider_response_config_TEST
#define create_domain_auth_provider_response_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_domain_auth_provider_response_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_domain_auth_provider_response_config.h"
create_domain_auth_provider_response_config_t* instantiate_create_domain_auth_provider_response_config(int include_optional);

#include "test_saml_identity_provider_config.c"
#include "test_saml_service_provider_config.c"
#include "test_ldap_user_attribute_mapping.c"
#include "test_ldap_server_connection_details.c"
#include "test_ldap_authentication_credentials.c"
#include "test_ldap_user_search_configuration.c"


create_domain_auth_provider_response_config_t* instantiate_create_domain_auth_provider_response_config(int include_optional) {
  create_domain_auth_provider_response_config_t* create_domain_auth_provider_response_config = NULL;
  if (include_optional) {
    create_domain_auth_provider_response_config = create_domain_auth_provider_response_config_create(
       // false, not to have infinite recursion
      instantiate_saml_identity_provider_config(0),
       // false, not to have infinite recursion
      instantiate_saml_service_provider_config(0),
       // false, not to have infinite recursion
      instantiate_ldap_user_attribute_mapping(0),
      list_createList(),
      "https://accounts.example.com/.well-known/openid-configuration",
      "corellium-domain-client",
      "<client-secret>",
      false,
       // false, not to have infinite recursion
      instantiate_ldap_server_connection_details(0),
       // false, not to have infinite recursion
      instantiate_ldap_authentication_credentials(0),
       // false, not to have infinite recursion
      instantiate_ldap_user_search_configuration(0),
      list_createList()
    );
  } else {
    create_domain_auth_provider_response_config = create_domain_auth_provider_response_config_create(
      NULL,
      NULL,
      NULL,
      list_createList(),
      "https://accounts.example.com/.well-known/openid-configuration",
      "corellium-domain-client",
      "<client-secret>",
      false,
      NULL,
      NULL,
      NULL,
      list_createList()
    );
  }

  return create_domain_auth_provider_response_config;
}


#ifdef create_domain_auth_provider_response_config_MAIN

void test_create_domain_auth_provider_response_config(int include_optional) {
    create_domain_auth_provider_response_config_t* create_domain_auth_provider_response_config_1 = instantiate_create_domain_auth_provider_response_config(include_optional);

	cJSON* jsoncreate_domain_auth_provider_response_config_1 = create_domain_auth_provider_response_config_convertToJSON(create_domain_auth_provider_response_config_1);
	printf("create_domain_auth_provider_response_config :\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_response_config_1));
	create_domain_auth_provider_response_config_t* create_domain_auth_provider_response_config_2 = create_domain_auth_provider_response_config_parseFromJSON(jsoncreate_domain_auth_provider_response_config_1);
	cJSON* jsoncreate_domain_auth_provider_response_config_2 = create_domain_auth_provider_response_config_convertToJSON(create_domain_auth_provider_response_config_2);
	printf("repeating create_domain_auth_provider_response_config:\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_response_config_2));
}

int main() {
  test_create_domain_auth_provider_response_config(1);
  test_create_domain_auth_provider_response_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_domain_auth_provider_response_config_MAIN
#endif // create_domain_auth_provider_response_config_TEST
