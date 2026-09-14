#ifndef saml_group_mapping_TEST
#define saml_group_mapping_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define saml_group_mapping_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/saml_group_mapping.h"
saml_group_mapping_t* instantiate_saml_group_mapping(int include_optional);



saml_group_mapping_t* instantiate_saml_group_mapping(int include_optional) {
  saml_group_mapping_t* saml_group_mapping = NULL;
  if (include_optional) {
    saml_group_mapping = saml_group_mapping_create(
      "0",
      "0",
      "0"
    );
  } else {
    saml_group_mapping = saml_group_mapping_create(
      "0",
      "0",
      "0"
    );
  }

  return saml_group_mapping;
}


#ifdef saml_group_mapping_MAIN

void test_saml_group_mapping(int include_optional) {
    saml_group_mapping_t* saml_group_mapping_1 = instantiate_saml_group_mapping(include_optional);

	cJSON* jsonsaml_group_mapping_1 = saml_group_mapping_convertToJSON(saml_group_mapping_1);
	printf("saml_group_mapping :\n%s\n", cJSON_Print(jsonsaml_group_mapping_1));
	saml_group_mapping_t* saml_group_mapping_2 = saml_group_mapping_parseFromJSON(jsonsaml_group_mapping_1);
	cJSON* jsonsaml_group_mapping_2 = saml_group_mapping_convertToJSON(saml_group_mapping_2);
	printf("repeating saml_group_mapping:\n%s\n", cJSON_Print(jsonsaml_group_mapping_2));
}

int main() {
  test_saml_group_mapping(1);
  test_saml_group_mapping(0);

  printf("Hello world \n");
  return 0;
}

#endif // saml_group_mapping_MAIN
#endif // saml_group_mapping_TEST
