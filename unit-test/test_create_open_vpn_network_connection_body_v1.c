#ifndef create_open_vpn_network_connection_body_v1_TEST
#define create_open_vpn_network_connection_body_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_open_vpn_network_connection_body_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_open_vpn_network_connection_body_v1.h"
create_open_vpn_network_connection_body_v1_t* instantiate_create_open_vpn_network_connection_body_v1(int include_optional);

#include "test_open_vpn_config_v1.c"


create_open_vpn_network_connection_body_v1_t* instantiate_create_open_vpn_network_connection_body_v1(int include_optional) {
  create_open_vpn_network_connection_body_v1_t* create_open_vpn_network_connection_body_v1 = NULL;
  if (include_optional) {
    create_open_vpn_network_connection_body_v1 = create_open_vpn_network_connection_body_v1_create(
      "0",
      corellium_api_create_open_vpn_network_connection_body_v1_PROVIDER_openvpn,
       // false, not to have infinite recursion
      instantiate_open_vpn_config_v1(0)
    );
  } else {
    create_open_vpn_network_connection_body_v1 = create_open_vpn_network_connection_body_v1_create(
      "0",
      corellium_api_create_open_vpn_network_connection_body_v1_PROVIDER_openvpn,
      NULL
    );
  }

  return create_open_vpn_network_connection_body_v1;
}


#ifdef create_open_vpn_network_connection_body_v1_MAIN

void test_create_open_vpn_network_connection_body_v1(int include_optional) {
    create_open_vpn_network_connection_body_v1_t* create_open_vpn_network_connection_body_v1_1 = instantiate_create_open_vpn_network_connection_body_v1(include_optional);

	cJSON* jsoncreate_open_vpn_network_connection_body_v1_1 = create_open_vpn_network_connection_body_v1_convertToJSON(create_open_vpn_network_connection_body_v1_1);
	printf("create_open_vpn_network_connection_body_v1 :\n%s\n", cJSON_Print(jsoncreate_open_vpn_network_connection_body_v1_1));
	create_open_vpn_network_connection_body_v1_t* create_open_vpn_network_connection_body_v1_2 = create_open_vpn_network_connection_body_v1_parseFromJSON(jsoncreate_open_vpn_network_connection_body_v1_1);
	cJSON* jsoncreate_open_vpn_network_connection_body_v1_2 = create_open_vpn_network_connection_body_v1_convertToJSON(create_open_vpn_network_connection_body_v1_2);
	printf("repeating create_open_vpn_network_connection_body_v1:\n%s\n", cJSON_Print(jsoncreate_open_vpn_network_connection_body_v1_2));
}

int main() {
  test_create_open_vpn_network_connection_body_v1(1);
  test_create_open_vpn_network_connection_body_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_open_vpn_network_connection_body_v1_MAIN
#endif // create_open_vpn_network_connection_body_v1_TEST
