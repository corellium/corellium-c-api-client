#ifndef ldap_group_search_configuration_TEST
#define ldap_group_search_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ldap_group_search_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ldap_group_search_configuration.h"
ldap_group_search_configuration_t* instantiate_ldap_group_search_configuration(int include_optional);



ldap_group_search_configuration_t* instantiate_ldap_group_search_configuration(int include_optional) {
  ldap_group_search_configuration_t* ldap_group_search_configuration = NULL;
  if (include_optional) {
    ldap_group_search_configuration = ldap_group_search_configuration_create(
      "ou=groups,dc=example,dc=com",
      "objectClass=groupOfNames",
      "089c8ffd-ca4d-4d35-80ab-0847d18b7213",
      "admin"
    );
  } else {
    ldap_group_search_configuration = ldap_group_search_configuration_create(
      "ou=groups,dc=example,dc=com",
      "objectClass=groupOfNames",
      "089c8ffd-ca4d-4d35-80ab-0847d18b7213",
      "admin"
    );
  }

  return ldap_group_search_configuration;
}


#ifdef ldap_group_search_configuration_MAIN

void test_ldap_group_search_configuration(int include_optional) {
    ldap_group_search_configuration_t* ldap_group_search_configuration_1 = instantiate_ldap_group_search_configuration(include_optional);

	cJSON* jsonldap_group_search_configuration_1 = ldap_group_search_configuration_convertToJSON(ldap_group_search_configuration_1);
	printf("ldap_group_search_configuration :\n%s\n", cJSON_Print(jsonldap_group_search_configuration_1));
	ldap_group_search_configuration_t* ldap_group_search_configuration_2 = ldap_group_search_configuration_parseFromJSON(jsonldap_group_search_configuration_1);
	cJSON* jsonldap_group_search_configuration_2 = ldap_group_search_configuration_convertToJSON(ldap_group_search_configuration_2);
	printf("repeating ldap_group_search_configuration:\n%s\n", cJSON_Print(jsonldap_group_search_configuration_2));
}

int main() {
  test_ldap_group_search_configuration(1);
  test_ldap_group_search_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // ldap_group_search_configuration_MAIN
#endif // ldap_group_search_configuration_TEST
