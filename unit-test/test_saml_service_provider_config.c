#ifndef saml_service_provider_config_TEST
#define saml_service_provider_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define saml_service_provider_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/saml_service_provider_config.h"
saml_service_provider_config_t* instantiate_saml_service_provider_config(int include_optional);



saml_service_provider_config_t* instantiate_saml_service_provider_config(int include_optional) {
  saml_service_provider_config_t* saml_service_provider_config = NULL;
  if (include_optional) {
    saml_service_provider_config = saml_service_provider_config_create(
      "0",
      "0",
      "0"
    );
  } else {
    saml_service_provider_config = saml_service_provider_config_create(
      "0",
      "0",
      "0"
    );
  }

  return saml_service_provider_config;
}


#ifdef saml_service_provider_config_MAIN

void test_saml_service_provider_config(int include_optional) {
    saml_service_provider_config_t* saml_service_provider_config_1 = instantiate_saml_service_provider_config(include_optional);

	cJSON* jsonsaml_service_provider_config_1 = saml_service_provider_config_convertToJSON(saml_service_provider_config_1);
	printf("saml_service_provider_config :\n%s\n", cJSON_Print(jsonsaml_service_provider_config_1));
	saml_service_provider_config_t* saml_service_provider_config_2 = saml_service_provider_config_parseFromJSON(jsonsaml_service_provider_config_1);
	cJSON* jsonsaml_service_provider_config_2 = saml_service_provider_config_convertToJSON(saml_service_provider_config_2);
	printf("repeating saml_service_provider_config:\n%s\n", cJSON_Print(jsonsaml_service_provider_config_2));
}

int main() {
  test_saml_service_provider_config(1);
  test_saml_service_provider_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // saml_service_provider_config_MAIN
#endif // saml_service_provider_config_TEST
