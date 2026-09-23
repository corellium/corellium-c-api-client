#ifndef vlan_network_connection_TEST
#define vlan_network_connection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vlan_network_connection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vlan_network_connection.h"
vlan_network_connection_t* instantiate_vlan_network_connection(int include_optional);

#include "test_vlan_config.c"


vlan_network_connection_t* instantiate_vlan_network_connection(int include_optional) {
  vlan_network_connection_t* vlan_network_connection = NULL;
  if (include_optional) {
    vlan_network_connection = vlan_network_connection_create(
      "lab-vlan",
      corellium_api_vlan_network_connection_PROVIDER_vlan,
       // false, not to have infinite recursion
      instantiate_vlan_config(0),
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7",
      {"1c41b1bc-4f53-48a8-b690-ad30611e1960":{"state":"connected"}},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320"
    );
  } else {
    vlan_network_connection = vlan_network_connection_create(
      "lab-vlan",
      corellium_api_vlan_network_connection_PROVIDER_vlan,
      NULL,
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7",
      {"1c41b1bc-4f53-48a8-b690-ad30611e1960":{"state":"connected"}},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320"
    );
  }

  return vlan_network_connection;
}


#ifdef vlan_network_connection_MAIN

void test_vlan_network_connection(int include_optional) {
    vlan_network_connection_t* vlan_network_connection_1 = instantiate_vlan_network_connection(include_optional);

	cJSON* jsonvlan_network_connection_1 = vlan_network_connection_convertToJSON(vlan_network_connection_1);
	printf("vlan_network_connection :\n%s\n", cJSON_Print(jsonvlan_network_connection_1));
	vlan_network_connection_t* vlan_network_connection_2 = vlan_network_connection_parseFromJSON(jsonvlan_network_connection_1);
	cJSON* jsonvlan_network_connection_2 = vlan_network_connection_convertToJSON(vlan_network_connection_2);
	printf("repeating vlan_network_connection:\n%s\n", cJSON_Print(jsonvlan_network_connection_2));
}

int main() {
  test_vlan_network_connection(1);
  test_vlan_network_connection(0);

  printf("Hello world \n");
  return 0;
}

#endif // vlan_network_connection_MAIN
#endif // vlan_network_connection_TEST
