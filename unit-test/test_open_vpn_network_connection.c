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
      "office-vpn",
      corellium_api_open_vpn_network_connection_PROVIDER_openvpn,
       // false, not to have infinite recursion
      instantiate_open_vpn_config(0),
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7",
      {"1c41b1bc-4f53-48a8-b690-ad30611e1960":{"state":"connected"}},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320"
    );
  } else {
    open_vpn_network_connection = open_vpn_network_connection_create(
      "office-vpn",
      corellium_api_open_vpn_network_connection_PROVIDER_openvpn,
      NULL,
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7",
      {"1c41b1bc-4f53-48a8-b690-ad30611e1960":{"state":"connected"}},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320"
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
