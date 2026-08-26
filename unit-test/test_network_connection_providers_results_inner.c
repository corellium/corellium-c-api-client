#ifndef network_connection_providers_results_inner_TEST
#define network_connection_providers_results_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_connection_providers_results_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_connection_providers_results_inner.h"
network_connection_providers_results_inner_t* instantiate_network_connection_providers_results_inner(int include_optional);



network_connection_providers_results_inner_t* instantiate_network_connection_providers_results_inner(int include_optional) {
  network_connection_providers_results_inner_t* network_connection_providers_results_inner = NULL;
  if (include_optional) {
    network_connection_providers_results_inner = network_connection_providers_results_inner_create(
      "0",
      "0"
    );
  } else {
    network_connection_providers_results_inner = network_connection_providers_results_inner_create(
      "0",
      "0"
    );
  }

  return network_connection_providers_results_inner;
}


#ifdef network_connection_providers_results_inner_MAIN

void test_network_connection_providers_results_inner(int include_optional) {
    network_connection_providers_results_inner_t* network_connection_providers_results_inner_1 = instantiate_network_connection_providers_results_inner(include_optional);

	cJSON* jsonnetwork_connection_providers_results_inner_1 = network_connection_providers_results_inner_convertToJSON(network_connection_providers_results_inner_1);
	printf("network_connection_providers_results_inner :\n%s\n", cJSON_Print(jsonnetwork_connection_providers_results_inner_1));
	network_connection_providers_results_inner_t* network_connection_providers_results_inner_2 = network_connection_providers_results_inner_parseFromJSON(jsonnetwork_connection_providers_results_inner_1);
	cJSON* jsonnetwork_connection_providers_results_inner_2 = network_connection_providers_results_inner_convertToJSON(network_connection_providers_results_inner_2);
	printf("repeating network_connection_providers_results_inner:\n%s\n", cJSON_Print(jsonnetwork_connection_providers_results_inner_2));
}

int main() {
  test_network_connection_providers_results_inner(1);
  test_network_connection_providers_results_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_connection_providers_results_inner_MAIN
#endif // network_connection_providers_results_inner_TEST
