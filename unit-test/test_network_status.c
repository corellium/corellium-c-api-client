#ifndef network_status_TEST
#define network_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_status.h"
network_status_t* instantiate_network_status(int include_optional);



network_status_t* instantiate_network_status(int include_optional) {
  network_status_t* network_status = NULL;
  if (include_optional) {
    network_status = network_status_create(
      "0",
      "0",
      corellium_api_network_status_STATE_disconnected,
      0
    );
  } else {
    network_status = network_status_create(
      "0",
      "0",
      corellium_api_network_status_STATE_disconnected,
      0
    );
  }

  return network_status;
}


#ifdef network_status_MAIN

void test_network_status(int include_optional) {
    network_status_t* network_status_1 = instantiate_network_status(include_optional);

	cJSON* jsonnetwork_status_1 = network_status_convertToJSON(network_status_1);
	printf("network_status :\n%s\n", cJSON_Print(jsonnetwork_status_1));
	network_status_t* network_status_2 = network_status_parseFromJSON(jsonnetwork_status_1);
	cJSON* jsonnetwork_status_2 = network_status_convertToJSON(network_status_2);
	printf("repeating network_status:\n%s\n", cJSON_Print(jsonnetwork_status_2));
}

int main() {
  test_network_status(1);
  test_network_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_status_MAIN
#endif // network_status_TEST
