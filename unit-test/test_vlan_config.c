#ifndef vlan_config_TEST
#define vlan_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vlan_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vlan_config.h"
vlan_config_t* instantiate_vlan_config(int include_optional);



vlan_config_t* instantiate_vlan_config(int include_optional) {
  vlan_config_t* vlan_config = NULL;
  if (include_optional) {
    vlan_config = vlan_config_create(
      "eth0",
      42,
      corellium_api_vlan_config_DHCPMODE_internal,
      "10.0.0.1",
      "10.0.0.0/24",
      ["1.1.1.1","8.8.8.8"]
    );
  } else {
    vlan_config = vlan_config_create(
      "eth0",
      42,
      corellium_api_vlan_config_DHCPMODE_internal,
      "10.0.0.1",
      "10.0.0.0/24",
      ["1.1.1.1","8.8.8.8"]
    );
  }

  return vlan_config;
}


#ifdef vlan_config_MAIN

void test_vlan_config(int include_optional) {
    vlan_config_t* vlan_config_1 = instantiate_vlan_config(include_optional);

	cJSON* jsonvlan_config_1 = vlan_config_convertToJSON(vlan_config_1);
	printf("vlan_config :\n%s\n", cJSON_Print(jsonvlan_config_1));
	vlan_config_t* vlan_config_2 = vlan_config_parseFromJSON(jsonvlan_config_1);
	cJSON* jsonvlan_config_2 = vlan_config_convertToJSON(vlan_config_2);
	printf("repeating vlan_config:\n%s\n", cJSON_Print(jsonvlan_config_2));
}

int main() {
  test_vlan_config(1);
  test_vlan_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // vlan_config_MAIN
#endif // vlan_config_TEST
