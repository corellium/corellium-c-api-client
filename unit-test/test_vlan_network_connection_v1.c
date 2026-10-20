#ifndef vlan_network_connection_v1_TEST
#define vlan_network_connection_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vlan_network_connection_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vlan_network_connection_v1.h"
vlan_network_connection_v1_t* instantiate_vlan_network_connection_v1(int include_optional);

#include "test_vlan_config_v1.c"


vlan_network_connection_v1_t* instantiate_vlan_network_connection_v1(int include_optional) {
  vlan_network_connection_v1_t* vlan_network_connection_v1 = NULL;
  if (include_optional) {
    vlan_network_connection_v1 = vlan_network_connection_v1_create(
      "0",
      corellium_api_vlan_network_connection_v1_PROVIDER_vlan,
      "0",
       // false, not to have infinite recursion
      instantiate_vlan_config_v1(0),
      0,
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    vlan_network_connection_v1 = vlan_network_connection_v1_create(
      "0",
      corellium_api_vlan_network_connection_v1_PROVIDER_vlan,
      "0",
      NULL,
      0,
      "0",
      "0",
      "0",
      "0"
    );
  }

  return vlan_network_connection_v1;
}


#ifdef vlan_network_connection_v1_MAIN

void test_vlan_network_connection_v1(int include_optional) {
    vlan_network_connection_v1_t* vlan_network_connection_v1_1 = instantiate_vlan_network_connection_v1(include_optional);

	cJSON* jsonvlan_network_connection_v1_1 = vlan_network_connection_v1_convertToJSON(vlan_network_connection_v1_1);
	printf("vlan_network_connection_v1 :\n%s\n", cJSON_Print(jsonvlan_network_connection_v1_1));
	vlan_network_connection_v1_t* vlan_network_connection_v1_2 = vlan_network_connection_v1_parseFromJSON(jsonvlan_network_connection_v1_1);
	cJSON* jsonvlan_network_connection_v1_2 = vlan_network_connection_v1_convertToJSON(vlan_network_connection_v1_2);
	printf("repeating vlan_network_connection_v1:\n%s\n", cJSON_Print(jsonvlan_network_connection_v1_2));
}

int main() {
  test_vlan_network_connection_v1(1);
  test_vlan_network_connection_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // vlan_network_connection_v1_MAIN
#endif // vlan_network_connection_v1_TEST
