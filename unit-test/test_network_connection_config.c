#ifndef network_connection_config_TEST
#define network_connection_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_connection_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_connection_config.h"
network_connection_config_t* instantiate_network_connection_config(int include_optional);



network_connection_config_t* instantiate_network_connection_config(int include_optional) {
  network_connection_config_t* network_connection_config = NULL;
  if (include_optional) {
    network_connection_config = network_connection_config_create(
      "0",
      "0",
      "0",
      "0",
      1,
      corellium_api_network_connection_config_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  } else {
    network_connection_config = network_connection_config_create(
      "0",
      "0",
      "0",
      "0",
      1,
      corellium_api_network_connection_config_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  }

  return network_connection_config;
}


#ifdef network_connection_config_MAIN

void test_network_connection_config(int include_optional) {
    network_connection_config_t* network_connection_config_1 = instantiate_network_connection_config(include_optional);

	cJSON* jsonnetwork_connection_config_1 = network_connection_config_convertToJSON(network_connection_config_1);
	printf("network_connection_config :\n%s\n", cJSON_Print(jsonnetwork_connection_config_1));
	network_connection_config_t* network_connection_config_2 = network_connection_config_parseFromJSON(jsonnetwork_connection_config_1);
	cJSON* jsonnetwork_connection_config_2 = network_connection_config_convertToJSON(network_connection_config_2);
	printf("repeating network_connection_config:\n%s\n", cJSON_Print(jsonnetwork_connection_config_2));
}

int main() {
  test_network_connection_config(1);
  test_network_connection_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_connection_config_MAIN
#endif // network_connection_config_TEST
