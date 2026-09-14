#ifndef ldap_user_attribute_mapping_TEST
#define ldap_user_attribute_mapping_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ldap_user_attribute_mapping_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ldap_user_attribute_mapping.h"
ldap_user_attribute_mapping_t* instantiate_ldap_user_attribute_mapping(int include_optional);



ldap_user_attribute_mapping_t* instantiate_ldap_user_attribute_mapping(int include_optional) {
  ldap_user_attribute_mapping_t* ldap_user_attribute_mapping = NULL;
  if (include_optional) {
    ldap_user_attribute_mapping = ldap_user_attribute_mapping_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    ldap_user_attribute_mapping = ldap_user_attribute_mapping_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return ldap_user_attribute_mapping;
}


#ifdef ldap_user_attribute_mapping_MAIN

void test_ldap_user_attribute_mapping(int include_optional) {
    ldap_user_attribute_mapping_t* ldap_user_attribute_mapping_1 = instantiate_ldap_user_attribute_mapping(include_optional);

	cJSON* jsonldap_user_attribute_mapping_1 = ldap_user_attribute_mapping_convertToJSON(ldap_user_attribute_mapping_1);
	printf("ldap_user_attribute_mapping :\n%s\n", cJSON_Print(jsonldap_user_attribute_mapping_1));
	ldap_user_attribute_mapping_t* ldap_user_attribute_mapping_2 = ldap_user_attribute_mapping_parseFromJSON(jsonldap_user_attribute_mapping_1);
	cJSON* jsonldap_user_attribute_mapping_2 = ldap_user_attribute_mapping_convertToJSON(ldap_user_attribute_mapping_2);
	printf("repeating ldap_user_attribute_mapping:\n%s\n", cJSON_Print(jsonldap_user_attribute_mapping_2));
}

int main() {
  test_ldap_user_attribute_mapping(1);
  test_ldap_user_attribute_mapping(0);

  printf("Hello world \n");
  return 0;
}

#endif // ldap_user_attribute_mapping_MAIN
#endif // ldap_user_attribute_mapping_TEST
