#ifndef vlan_config_v1_TEST
#define vlan_config_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vlan_config_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vlan_config_v1.h"
vlan_config_v1_t* instantiate_vlan_config_v1(int include_optional);



vlan_config_v1_t* instantiate_vlan_config_v1(int include_optional) {
  vlan_config_v1_t* vlan_config_v1 = NULL;
  if (include_optional) {
    vlan_config_v1 = vlan_config_v1_create(
      "0",
      1,
      corellium_api_vlan_config_v1_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  } else {
    vlan_config_v1 = vlan_config_v1_create(
      "0",
      1,
      corellium_api_vlan_config_v1_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  }

  return vlan_config_v1;
}


#ifdef vlan_config_v1_MAIN

void test_vlan_config_v1(int include_optional) {
    vlan_config_v1_t* vlan_config_v1_1 = instantiate_vlan_config_v1(include_optional);

	cJSON* jsonvlan_config_v1_1 = vlan_config_v1_convertToJSON(vlan_config_v1_1);
	printf("vlan_config_v1 :\n%s\n", cJSON_Print(jsonvlan_config_v1_1));
	vlan_config_v1_t* vlan_config_v1_2 = vlan_config_v1_parseFromJSON(jsonvlan_config_v1_1);
	cJSON* jsonvlan_config_v1_2 = vlan_config_v1_convertToJSON(vlan_config_v1_2);
	printf("repeating vlan_config_v1:\n%s\n", cJSON_Print(jsonvlan_config_v1_2));
}

int main() {
  test_vlan_config_v1(1);
  test_vlan_config_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // vlan_config_v1_MAIN
#endif // vlan_config_v1_TEST
