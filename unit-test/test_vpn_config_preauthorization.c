#ifndef vpn_config_preauthorization_TEST
#define vpn_config_preauthorization_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vpn_config_preauthorization_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vpn_config_preauthorization.h"
vpn_config_preauthorization_t* instantiate_vpn_config_preauthorization(int include_optional);



vpn_config_preauthorization_t* instantiate_vpn_config_preauthorization(int include_optional) {
  vpn_config_preauthorization_t* vpn_config_preauthorization = NULL;
  if (include_optional) {
    vpn_config_preauthorization = vpn_config_preauthorization_create(
      "<token>"
    );
  } else {
    vpn_config_preauthorization = vpn_config_preauthorization_create(
      "<token>"
    );
  }

  return vpn_config_preauthorization;
}


#ifdef vpn_config_preauthorization_MAIN

void test_vpn_config_preauthorization(int include_optional) {
    vpn_config_preauthorization_t* vpn_config_preauthorization_1 = instantiate_vpn_config_preauthorization(include_optional);

	cJSON* jsonvpn_config_preauthorization_1 = vpn_config_preauthorization_convertToJSON(vpn_config_preauthorization_1);
	printf("vpn_config_preauthorization :\n%s\n", cJSON_Print(jsonvpn_config_preauthorization_1));
	vpn_config_preauthorization_t* vpn_config_preauthorization_2 = vpn_config_preauthorization_parseFromJSON(jsonvpn_config_preauthorization_1);
	cJSON* jsonvpn_config_preauthorization_2 = vpn_config_preauthorization_convertToJSON(vpn_config_preauthorization_2);
	printf("repeating vpn_config_preauthorization:\n%s\n", cJSON_Print(jsonvpn_config_preauthorization_2));
}

int main() {
  test_vpn_config_preauthorization(1);
  test_vpn_config_preauthorization(0);

  printf("Hello world \n");
  return 0;
}

#endif // vpn_config_preauthorization_MAIN
#endif // vpn_config_preauthorization_TEST
