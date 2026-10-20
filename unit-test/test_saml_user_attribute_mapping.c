#ifndef saml_user_attribute_mapping_TEST
#define saml_user_attribute_mapping_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define saml_user_attribute_mapping_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/saml_user_attribute_mapping.h"
saml_user_attribute_mapping_t* instantiate_saml_user_attribute_mapping(int include_optional);



saml_user_attribute_mapping_t* instantiate_saml_user_attribute_mapping(int include_optional) {
  saml_user_attribute_mapping_t* saml_user_attribute_mapping = NULL;
  if (include_optional) {
    saml_user_attribute_mapping = saml_user_attribute_mapping_create(
      "username",
      "email",
      "firstName",
      "lastName",
      "groups"
    );
  } else {
    saml_user_attribute_mapping = saml_user_attribute_mapping_create(
      "username",
      "email",
      "firstName",
      "lastName",
      "groups"
    );
  }

  return saml_user_attribute_mapping;
}


#ifdef saml_user_attribute_mapping_MAIN

void test_saml_user_attribute_mapping(int include_optional) {
    saml_user_attribute_mapping_t* saml_user_attribute_mapping_1 = instantiate_saml_user_attribute_mapping(include_optional);

	cJSON* jsonsaml_user_attribute_mapping_1 = saml_user_attribute_mapping_convertToJSON(saml_user_attribute_mapping_1);
	printf("saml_user_attribute_mapping :\n%s\n", cJSON_Print(jsonsaml_user_attribute_mapping_1));
	saml_user_attribute_mapping_t* saml_user_attribute_mapping_2 = saml_user_attribute_mapping_parseFromJSON(jsonsaml_user_attribute_mapping_1);
	cJSON* jsonsaml_user_attribute_mapping_2 = saml_user_attribute_mapping_convertToJSON(saml_user_attribute_mapping_2);
	printf("repeating saml_user_attribute_mapping:\n%s\n", cJSON_Print(jsonsaml_user_attribute_mapping_2));
}

int main() {
  test_saml_user_attribute_mapping(1);
  test_saml_user_attribute_mapping(0);

  printf("Hello world \n");
  return 0;
}

#endif // saml_user_attribute_mapping_MAIN
#endif // saml_user_attribute_mapping_TEST
