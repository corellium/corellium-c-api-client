#ifndef network_connection_TEST
#define network_connection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_connection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_connection.h"
network_connection_t* instantiate_network_connection(int include_optional);



network_connection_t* instantiate_network_connection(int include_optional) {
  network_connection_t* network_connection = NULL;
  if (include_optional) {
    network_connection = network_connection_create(
      "0",
      "0",
      "0",
      0,
      0,
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    network_connection = network_connection_create(
      "0",
      "0",
      "0",
      0,
      0,
      "0",
      "0",
      "0",
      "0"
    );
  }

  return network_connection;
}


#ifdef network_connection_MAIN

void test_network_connection(int include_optional) {
    network_connection_t* network_connection_1 = instantiate_network_connection(include_optional);

	cJSON* jsonnetwork_connection_1 = network_connection_convertToJSON(network_connection_1);
	printf("network_connection :\n%s\n", cJSON_Print(jsonnetwork_connection_1));
	network_connection_t* network_connection_2 = network_connection_parseFromJSON(jsonnetwork_connection_1);
	cJSON* jsonnetwork_connection_2 = network_connection_convertToJSON(network_connection_2);
	printf("repeating network_connection:\n%s\n", cJSON_Print(jsonnetwork_connection_2));
}

int main() {
  test_network_connection(1);
  test_network_connection(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_connection_MAIN
#endif // network_connection_TEST
