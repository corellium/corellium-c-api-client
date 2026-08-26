#ifndef create_vlan_network_connection_body_v1_TEST
#define create_vlan_network_connection_body_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_vlan_network_connection_body_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_vlan_network_connection_body_v1.h"
create_vlan_network_connection_body_v1_t* instantiate_create_vlan_network_connection_body_v1(int include_optional);

#include "test_vlan_config_v1.c"


create_vlan_network_connection_body_v1_t* instantiate_create_vlan_network_connection_body_v1(int include_optional) {
  create_vlan_network_connection_body_v1_t* create_vlan_network_connection_body_v1 = NULL;
  if (include_optional) {
    create_vlan_network_connection_body_v1 = create_vlan_network_connection_body_v1_create(
      "0",
      corellium_api_create_vlan_network_connection_body_v1_PROVIDER_vlan,
       // false, not to have infinite recursion
      instantiate_vlan_config_v1(0)
    );
  } else {
    create_vlan_network_connection_body_v1 = create_vlan_network_connection_body_v1_create(
      "0",
      corellium_api_create_vlan_network_connection_body_v1_PROVIDER_vlan,
      NULL
    );
  }

  return create_vlan_network_connection_body_v1;
}


#ifdef create_vlan_network_connection_body_v1_MAIN

void test_create_vlan_network_connection_body_v1(int include_optional) {
    create_vlan_network_connection_body_v1_t* create_vlan_network_connection_body_v1_1 = instantiate_create_vlan_network_connection_body_v1(include_optional);

	cJSON* jsoncreate_vlan_network_connection_body_v1_1 = create_vlan_network_connection_body_v1_convertToJSON(create_vlan_network_connection_body_v1_1);
	printf("create_vlan_network_connection_body_v1 :\n%s\n", cJSON_Print(jsoncreate_vlan_network_connection_body_v1_1));
	create_vlan_network_connection_body_v1_t* create_vlan_network_connection_body_v1_2 = create_vlan_network_connection_body_v1_parseFromJSON(jsoncreate_vlan_network_connection_body_v1_1);
	cJSON* jsoncreate_vlan_network_connection_body_v1_2 = create_vlan_network_connection_body_v1_convertToJSON(create_vlan_network_connection_body_v1_2);
	printf("repeating create_vlan_network_connection_body_v1:\n%s\n", cJSON_Print(jsoncreate_vlan_network_connection_body_v1_2));
}

int main() {
  test_create_vlan_network_connection_body_v1(1);
  test_create_vlan_network_connection_body_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_vlan_network_connection_body_v1_MAIN
#endif // create_vlan_network_connection_body_v1_TEST
