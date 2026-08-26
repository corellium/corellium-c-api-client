#ifndef create_open_vpn_network_connection_body_TEST
#define create_open_vpn_network_connection_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_open_vpn_network_connection_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_open_vpn_network_connection_body.h"
create_open_vpn_network_connection_body_t* instantiate_create_open_vpn_network_connection_body(int include_optional);

#include "test_open_vpn_config.c"


create_open_vpn_network_connection_body_t* instantiate_create_open_vpn_network_connection_body(int include_optional) {
  create_open_vpn_network_connection_body_t* create_open_vpn_network_connection_body = NULL;
  if (include_optional) {
    create_open_vpn_network_connection_body = create_open_vpn_network_connection_body_create(
      "0",
      corellium_api_create_open_vpn_network_connection_body_PROVIDER_openvpn,
       // false, not to have infinite recursion
      instantiate_open_vpn_config(0)
    );
  } else {
    create_open_vpn_network_connection_body = create_open_vpn_network_connection_body_create(
      "0",
      corellium_api_create_open_vpn_network_connection_body_PROVIDER_openvpn,
      NULL
    );
  }

  return create_open_vpn_network_connection_body;
}


#ifdef create_open_vpn_network_connection_body_MAIN

void test_create_open_vpn_network_connection_body(int include_optional) {
    create_open_vpn_network_connection_body_t* create_open_vpn_network_connection_body_1 = instantiate_create_open_vpn_network_connection_body(include_optional);

	cJSON* jsoncreate_open_vpn_network_connection_body_1 = create_open_vpn_network_connection_body_convertToJSON(create_open_vpn_network_connection_body_1);
	printf("create_open_vpn_network_connection_body :\n%s\n", cJSON_Print(jsoncreate_open_vpn_network_connection_body_1));
	create_open_vpn_network_connection_body_t* create_open_vpn_network_connection_body_2 = create_open_vpn_network_connection_body_parseFromJSON(jsoncreate_open_vpn_network_connection_body_1);
	cJSON* jsoncreate_open_vpn_network_connection_body_2 = create_open_vpn_network_connection_body_convertToJSON(create_open_vpn_network_connection_body_2);
	printf("repeating create_open_vpn_network_connection_body:\n%s\n", cJSON_Print(jsoncreate_open_vpn_network_connection_body_2));
}

int main() {
  test_create_open_vpn_network_connection_body(1);
  test_create_open_vpn_network_connection_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_open_vpn_network_connection_body_MAIN
#endif // create_open_vpn_network_connection_body_TEST
