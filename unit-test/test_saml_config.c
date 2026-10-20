#ifndef saml_config_TEST
#define saml_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define saml_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/saml_config.h"
saml_config_t* instantiate_saml_config(int include_optional);

#include "test_saml_identity_provider_config.c"
#include "test_saml_service_provider_config.c"
#include "test_saml_user_attribute_mapping.c"


saml_config_t* instantiate_saml_config(int include_optional) {
  saml_config_t* saml_config = NULL;
  if (include_optional) {
    saml_config = saml_config_create(
       // false, not to have infinite recursion
      instantiate_saml_identity_provider_config(0),
       // false, not to have infinite recursion
      instantiate_saml_service_provider_config(0),
       // false, not to have infinite recursion
      instantiate_saml_user_attribute_mapping(0),
      list_createList()
    );
  } else {
    saml_config = saml_config_create(
      NULL,
      NULL,
      NULL,
      list_createList()
    );
  }

  return saml_config;
}


#ifdef saml_config_MAIN

void test_saml_config(int include_optional) {
    saml_config_t* saml_config_1 = instantiate_saml_config(include_optional);

	cJSON* jsonsaml_config_1 = saml_config_convertToJSON(saml_config_1);
	printf("saml_config :\n%s\n", cJSON_Print(jsonsaml_config_1));
	saml_config_t* saml_config_2 = saml_config_parseFromJSON(jsonsaml_config_1);
	cJSON* jsonsaml_config_2 = saml_config_convertToJSON(saml_config_2);
	printf("repeating saml_config:\n%s\n", cJSON_Print(jsonsaml_config_2));
}

int main() {
  test_saml_config(1);
  test_saml_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // saml_config_MAIN
#endif // saml_config_TEST
