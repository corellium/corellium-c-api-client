#ifndef ldap_config_TEST
#define ldap_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ldap_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ldap_config.h"
ldap_config_t* instantiate_ldap_config(int include_optional);

#include "test_ldap_server_connection_details.c"
#include "test_ldap_authentication_credentials.c"
#include "test_ldap_user_search_configuration.c"
#include "test_ldap_user_attribute_mapping.c"


ldap_config_t* instantiate_ldap_config(int include_optional) {
  ldap_config_t* ldap_config = NULL;
  if (include_optional) {
    ldap_config = ldap_config_create(
       // false, not to have infinite recursion
      instantiate_ldap_server_connection_details(0),
       // false, not to have infinite recursion
      instantiate_ldap_authentication_credentials(0),
       // false, not to have infinite recursion
      instantiate_ldap_user_search_configuration(0),
       // false, not to have infinite recursion
      instantiate_ldap_user_attribute_mapping(0),
      list_createList()
    );
  } else {
    ldap_config = ldap_config_create(
      NULL,
      NULL,
      NULL,
      NULL,
      list_createList()
    );
  }

  return ldap_config;
}


#ifdef ldap_config_MAIN

void test_ldap_config(int include_optional) {
    ldap_config_t* ldap_config_1 = instantiate_ldap_config(include_optional);

	cJSON* jsonldap_config_1 = ldap_config_convertToJSON(ldap_config_1);
	printf("ldap_config :\n%s\n", cJSON_Print(jsonldap_config_1));
	ldap_config_t* ldap_config_2 = ldap_config_parseFromJSON(jsonldap_config_1);
	cJSON* jsonldap_config_2 = ldap_config_convertToJSON(ldap_config_2);
	printf("repeating ldap_config:\n%s\n", cJSON_Print(jsonldap_config_2));
}

int main() {
  test_ldap_config(1);
  test_ldap_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // ldap_config_MAIN
#endif // ldap_config_TEST
