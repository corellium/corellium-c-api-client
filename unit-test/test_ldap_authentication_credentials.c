#ifndef ldap_authentication_credentials_TEST
#define ldap_authentication_credentials_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ldap_authentication_credentials_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ldap_authentication_credentials.h"
ldap_authentication_credentials_t* instantiate_ldap_authentication_credentials(int include_optional);



ldap_authentication_credentials_t* instantiate_ldap_authentication_credentials(int include_optional) {
  ldap_authentication_credentials_t* ldap_authentication_credentials = NULL;
  if (include_optional) {
    ldap_authentication_credentials = ldap_authentication_credentials_create(
      "0",
      "0"
    );
  } else {
    ldap_authentication_credentials = ldap_authentication_credentials_create(
      "0",
      "0"
    );
  }

  return ldap_authentication_credentials;
}


#ifdef ldap_authentication_credentials_MAIN

void test_ldap_authentication_credentials(int include_optional) {
    ldap_authentication_credentials_t* ldap_authentication_credentials_1 = instantiate_ldap_authentication_credentials(include_optional);

	cJSON* jsonldap_authentication_credentials_1 = ldap_authentication_credentials_convertToJSON(ldap_authentication_credentials_1);
	printf("ldap_authentication_credentials :\n%s\n", cJSON_Print(jsonldap_authentication_credentials_1));
	ldap_authentication_credentials_t* ldap_authentication_credentials_2 = ldap_authentication_credentials_parseFromJSON(jsonldap_authentication_credentials_1);
	cJSON* jsonldap_authentication_credentials_2 = ldap_authentication_credentials_convertToJSON(ldap_authentication_credentials_2);
	printf("repeating ldap_authentication_credentials:\n%s\n", cJSON_Print(jsonldap_authentication_credentials_2));
}

int main() {
  test_ldap_authentication_credentials(1);
  test_ldap_authentication_credentials(0);

  printf("Hello world \n");
  return 0;
}

#endif // ldap_authentication_credentials_MAIN
#endif // ldap_authentication_credentials_TEST
