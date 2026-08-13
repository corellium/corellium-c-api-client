#ifndef network_connection_provider_TEST
#define network_connection_provider_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_connection_provider_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_connection_provider.h"
network_connection_provider_t* instantiate_network_connection_provider(int include_optional);



network_connection_provider_t* instantiate_network_connection_provider(int include_optional) {
  network_connection_provider_t* network_connection_provider = NULL;
  if (include_optional) {
    network_connection_provider = network_connection_provider_create(
      "0",
      "0"
    );
  } else {
    network_connection_provider = network_connection_provider_create(
      "0",
      "0"
    );
  }

  return network_connection_provider;
}


#ifdef network_connection_provider_MAIN

void test_network_connection_provider(int include_optional) {
    network_connection_provider_t* network_connection_provider_1 = instantiate_network_connection_provider(include_optional);

	cJSON* jsonnetwork_connection_provider_1 = network_connection_provider_convertToJSON(network_connection_provider_1);
	printf("network_connection_provider :\n%s\n", cJSON_Print(jsonnetwork_connection_provider_1));
	network_connection_provider_t* network_connection_provider_2 = network_connection_provider_parseFromJSON(jsonnetwork_connection_provider_1);
	cJSON* jsonnetwork_connection_provider_2 = network_connection_provider_convertToJSON(network_connection_provider_2);
	printf("repeating network_connection_provider:\n%s\n", cJSON_Print(jsonnetwork_connection_provider_2));
}

int main() {
  test_network_connection_provider(1);
  test_network_connection_provider(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_connection_provider_MAIN
#endif // network_connection_provider_TEST
