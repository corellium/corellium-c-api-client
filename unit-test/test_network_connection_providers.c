#ifndef network_connection_providers_TEST
#define network_connection_providers_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_connection_providers_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_connection_providers.h"
network_connection_providers_t* instantiate_network_connection_providers(int include_optional);



network_connection_providers_t* instantiate_network_connection_providers(int include_optional) {
  network_connection_providers_t* network_connection_providers = NULL;
  if (include_optional) {
    network_connection_providers = network_connection_providers_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    network_connection_providers = network_connection_providers_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return network_connection_providers;
}


#ifdef network_connection_providers_MAIN

void test_network_connection_providers(int include_optional) {
    network_connection_providers_t* network_connection_providers_1 = instantiate_network_connection_providers(include_optional);

	cJSON* jsonnetwork_connection_providers_1 = network_connection_providers_convertToJSON(network_connection_providers_1);
	printf("network_connection_providers :\n%s\n", cJSON_Print(jsonnetwork_connection_providers_1));
	network_connection_providers_t* network_connection_providers_2 = network_connection_providers_parseFromJSON(jsonnetwork_connection_providers_1);
	cJSON* jsonnetwork_connection_providers_2 = network_connection_providers_convertToJSON(network_connection_providers_2);
	printf("repeating network_connection_providers:\n%s\n", cJSON_Print(jsonnetwork_connection_providers_2));
}

int main() {
  test_network_connection_providers(1);
  test_network_connection_providers(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_connection_providers_MAIN
#endif // network_connection_providers_TEST
