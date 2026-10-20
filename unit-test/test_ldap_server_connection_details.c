#ifndef ldap_server_connection_details_TEST
#define ldap_server_connection_details_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ldap_server_connection_details_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ldap_server_connection_details.h"
ldap_server_connection_details_t* instantiate_ldap_server_connection_details(int include_optional);



ldap_server_connection_details_t* instantiate_ldap_server_connection_details(int include_optional) {
  ldap_server_connection_details_t* ldap_server_connection_details = NULL;
  if (include_optional) {
    ldap_server_connection_details = ldap_server_connection_details_create(
      "ldap.example.com",
      "389",
      "5000",
      false,
      "-----BEGIN CERTIFICATE-----
<base64-encoded-ca-certificate>
-----END CERTIFICATE-----",
      true
    );
  } else {
    ldap_server_connection_details = ldap_server_connection_details_create(
      "ldap.example.com",
      "389",
      "5000",
      false,
      "-----BEGIN CERTIFICATE-----
<base64-encoded-ca-certificate>
-----END CERTIFICATE-----",
      true
    );
  }

  return ldap_server_connection_details;
}


#ifdef ldap_server_connection_details_MAIN

void test_ldap_server_connection_details(int include_optional) {
    ldap_server_connection_details_t* ldap_server_connection_details_1 = instantiate_ldap_server_connection_details(include_optional);

	cJSON* jsonldap_server_connection_details_1 = ldap_server_connection_details_convertToJSON(ldap_server_connection_details_1);
	printf("ldap_server_connection_details :\n%s\n", cJSON_Print(jsonldap_server_connection_details_1));
	ldap_server_connection_details_t* ldap_server_connection_details_2 = ldap_server_connection_details_parseFromJSON(jsonldap_server_connection_details_1);
	cJSON* jsonldap_server_connection_details_2 = ldap_server_connection_details_convertToJSON(ldap_server_connection_details_2);
	printf("repeating ldap_server_connection_details:\n%s\n", cJSON_Print(jsonldap_server_connection_details_2));
}

int main() {
  test_ldap_server_connection_details(1);
  test_ldap_server_connection_details(0);

  printf("Hello world \n");
  return 0;
}

#endif // ldap_server_connection_details_MAIN
#endif // ldap_server_connection_details_TEST
