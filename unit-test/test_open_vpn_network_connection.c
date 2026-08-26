#ifndef open_vpn_network_connection_TEST
#define open_vpn_network_connection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define open_vpn_network_connection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/open_vpn_network_connection.h"
open_vpn_network_connection_t* instantiate_open_vpn_network_connection(int include_optional);

#include "test_open_vpn_config.c"


open_vpn_network_connection_t* instantiate_open_vpn_network_connection(int include_optional) {
  open_vpn_network_connection_t* open_vpn_network_connection = NULL;
  if (include_optional) {
    open_vpn_network_connection = open_vpn_network_connection_create(
      "0",
      corellium_api_open_vpn_network_connection_PROVIDER_openvpn,
       // false, not to have infinite recursion
      instantiate_open_vpn_config(0),
      "0",
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  } else {
    open_vpn_network_connection = open_vpn_network_connection_create(
      "0",
      corellium_api_open_vpn_network_connection_PROVIDER_openvpn,
      NULL,
      "0",
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  }

  return open_vpn_network_connection;
}


#ifdef open_vpn_network_connection_MAIN

void test_open_vpn_network_connection(int include_optional) {
    open_vpn_network_connection_t* open_vpn_network_connection_1 = instantiate_open_vpn_network_connection(include_optional);

	cJSON* jsonopen_vpn_network_connection_1 = open_vpn_network_connection_convertToJSON(open_vpn_network_connection_1);
	printf("open_vpn_network_connection :\n%s\n", cJSON_Print(jsonopen_vpn_network_connection_1));
	open_vpn_network_connection_t* open_vpn_network_connection_2 = open_vpn_network_connection_parseFromJSON(jsonopen_vpn_network_connection_1);
	cJSON* jsonopen_vpn_network_connection_2 = open_vpn_network_connection_convertToJSON(open_vpn_network_connection_2);
	printf("repeating open_vpn_network_connection:\n%s\n", cJSON_Print(jsonopen_vpn_network_connection_2));
}

int main() {
  test_open_vpn_network_connection(1);
  test_open_vpn_network_connection(0);

  printf("Hello world \n");
  return 0;
}

#endif // open_vpn_network_connection_MAIN
#endif // open_vpn_network_connection_TEST
