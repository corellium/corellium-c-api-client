#ifndef network_status_v1_TEST
#define network_status_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_status_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_status_v1.h"
network_status_v1_t* instantiate_network_status_v1(int include_optional);



network_status_v1_t* instantiate_network_status_v1(int include_optional) {
  network_status_v1_t* network_status_v1 = NULL;
  if (include_optional) {
    network_status_v1 = network_status_v1_create(
      "0",
      "0",
      corellium_api_network_status_v1_STATE_disconnected
    );
  } else {
    network_status_v1 = network_status_v1_create(
      "0",
      "0",
      corellium_api_network_status_v1_STATE_disconnected
    );
  }

  return network_status_v1;
}


#ifdef network_status_v1_MAIN

void test_network_status_v1(int include_optional) {
    network_status_v1_t* network_status_v1_1 = instantiate_network_status_v1(include_optional);

	cJSON* jsonnetwork_status_v1_1 = network_status_v1_convertToJSON(network_status_v1_1);
	printf("network_status_v1 :\n%s\n", cJSON_Print(jsonnetwork_status_v1_1));
	network_status_v1_t* network_status_v1_2 = network_status_v1_parseFromJSON(jsonnetwork_status_v1_1);
	cJSON* jsonnetwork_status_v1_2 = network_status_v1_convertToJSON(network_status_v1_2);
	printf("repeating network_status_v1:\n%s\n", cJSON_Print(jsonnetwork_status_v1_2));
}

int main() {
  test_network_status_v1(1);
  test_network_status_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_status_v1_MAIN
#endif // network_status_v1_TEST
