#ifndef network_interfaces_TEST
#define network_interfaces_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_interfaces_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_interfaces.h"
network_interfaces_t* instantiate_network_interfaces(int include_optional);



network_interfaces_t* instantiate_network_interfaces(int include_optional) {
  network_interfaces_t* network_interfaces = NULL;
  if (include_optional) {
    network_interfaces = network_interfaces_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    network_interfaces = network_interfaces_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return network_interfaces;
}


#ifdef network_interfaces_MAIN

void test_network_interfaces(int include_optional) {
    network_interfaces_t* network_interfaces_1 = instantiate_network_interfaces(include_optional);

	cJSON* jsonnetwork_interfaces_1 = network_interfaces_convertToJSON(network_interfaces_1);
	printf("network_interfaces :\n%s\n", cJSON_Print(jsonnetwork_interfaces_1));
	network_interfaces_t* network_interfaces_2 = network_interfaces_parseFromJSON(jsonnetwork_interfaces_1);
	cJSON* jsonnetwork_interfaces_2 = network_interfaces_convertToJSON(network_interfaces_2);
	printf("repeating network_interfaces:\n%s\n", cJSON_Print(jsonnetwork_interfaces_2));
}

int main() {
  test_network_interfaces(1);
  test_network_interfaces(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_interfaces_MAIN
#endif // network_interfaces_TEST
