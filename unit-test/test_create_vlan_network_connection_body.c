#ifndef create_vlan_network_connection_body_TEST
#define create_vlan_network_connection_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_vlan_network_connection_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_vlan_network_connection_body.h"
create_vlan_network_connection_body_t* instantiate_create_vlan_network_connection_body(int include_optional);

#include "test_vlan_config.c"


create_vlan_network_connection_body_t* instantiate_create_vlan_network_connection_body(int include_optional) {
  create_vlan_network_connection_body_t* create_vlan_network_connection_body = NULL;
  if (include_optional) {
    create_vlan_network_connection_body = create_vlan_network_connection_body_create(
      "lab-vlan",
      corellium_api_create_vlan_network_connection_body_PROVIDER_vlan,
       // false, not to have infinite recursion
      instantiate_vlan_config(0)
    );
  } else {
    create_vlan_network_connection_body = create_vlan_network_connection_body_create(
      "lab-vlan",
      corellium_api_create_vlan_network_connection_body_PROVIDER_vlan,
      NULL
    );
  }

  return create_vlan_network_connection_body;
}


#ifdef create_vlan_network_connection_body_MAIN

void test_create_vlan_network_connection_body(int include_optional) {
    create_vlan_network_connection_body_t* create_vlan_network_connection_body_1 = instantiate_create_vlan_network_connection_body(include_optional);

	cJSON* jsoncreate_vlan_network_connection_body_1 = create_vlan_network_connection_body_convertToJSON(create_vlan_network_connection_body_1);
	printf("create_vlan_network_connection_body :\n%s\n", cJSON_Print(jsoncreate_vlan_network_connection_body_1));
	create_vlan_network_connection_body_t* create_vlan_network_connection_body_2 = create_vlan_network_connection_body_parseFromJSON(jsoncreate_vlan_network_connection_body_1);
	cJSON* jsoncreate_vlan_network_connection_body_2 = create_vlan_network_connection_body_convertToJSON(create_vlan_network_connection_body_2);
	printf("repeating create_vlan_network_connection_body:\n%s\n", cJSON_Print(jsoncreate_vlan_network_connection_body_2));
}

int main() {
  test_create_vlan_network_connection_body(1);
  test_create_vlan_network_connection_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_vlan_network_connection_body_MAIN
#endif // create_vlan_network_connection_body_TEST
