#ifndef vpn_definition_v1_TEST
#define vpn_definition_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vpn_definition_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vpn_definition_v1.h"
vpn_definition_v1_t* instantiate_vpn_definition_v1(int include_optional);



vpn_definition_v1_t* instantiate_vpn_definition_v1(int include_optional) {
  vpn_definition_v1_t* vpn_definition_v1 = NULL;
  if (include_optional) {
    vpn_definition_v1 = vpn_definition_v1_create(
      list_createList(),
      list_createList()
    );
  } else {
    vpn_definition_v1 = vpn_definition_v1_create(
      list_createList(),
      list_createList()
    );
  }

  return vpn_definition_v1;
}


#ifdef vpn_definition_v1_MAIN

void test_vpn_definition_v1(int include_optional) {
    vpn_definition_v1_t* vpn_definition_v1_1 = instantiate_vpn_definition_v1(include_optional);

	cJSON* jsonvpn_definition_v1_1 = vpn_definition_v1_convertToJSON(vpn_definition_v1_1);
	printf("vpn_definition_v1 :\n%s\n", cJSON_Print(jsonvpn_definition_v1_1));
	vpn_definition_v1_t* vpn_definition_v1_2 = vpn_definition_v1_parseFromJSON(jsonvpn_definition_v1_1);
	cJSON* jsonvpn_definition_v1_2 = vpn_definition_v1_convertToJSON(vpn_definition_v1_2);
	printf("repeating vpn_definition_v1:\n%s\n", cJSON_Print(jsonvpn_definition_v1_2));
}

int main() {
  test_vpn_definition_v1(1);
  test_vpn_definition_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // vpn_definition_v1_MAIN
#endif // vpn_definition_v1_TEST
