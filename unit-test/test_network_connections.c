#ifndef network_connections_TEST
#define network_connections_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_connections_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_connections.h"
network_connections_t* instantiate_network_connections(int include_optional);



network_connections_t* instantiate_network_connections(int include_optional) {
  network_connections_t* network_connections = NULL;
  if (include_optional) {
    network_connections = network_connections_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    network_connections = network_connections_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return network_connections;
}


#ifdef network_connections_MAIN

void test_network_connections(int include_optional) {
    network_connections_t* network_connections_1 = instantiate_network_connections(include_optional);

	cJSON* jsonnetwork_connections_1 = network_connections_convertToJSON(network_connections_1);
	printf("network_connections :\n%s\n", cJSON_Print(jsonnetwork_connections_1));
	network_connections_t* network_connections_2 = network_connections_parseFromJSON(jsonnetwork_connections_1);
	cJSON* jsonnetwork_connections_2 = network_connections_convertToJSON(network_connections_2);
	printf("repeating network_connections:\n%s\n", cJSON_Print(jsonnetwork_connections_2));
}

int main() {
  test_network_connections(1);
  test_network_connections(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_connections_MAIN
#endif // network_connections_TEST
