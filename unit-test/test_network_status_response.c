#ifndef network_status_response_TEST
#define network_status_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_status_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_status_response.h"
network_status_response_t* instantiate_network_status_response(int include_optional);



network_status_response_t* instantiate_network_status_response(int include_optional) {
  network_status_response_t* network_status_response = NULL;
  if (include_optional) {
    network_status_response = network_status_response_create(
      "0",
      "0",
      corellium_api_network_status_response_STATE_inactive,
      0
    );
  } else {
    network_status_response = network_status_response_create(
      "0",
      "0",
      corellium_api_network_status_response_STATE_inactive,
      0
    );
  }

  return network_status_response;
}


#ifdef network_status_response_MAIN

void test_network_status_response(int include_optional) {
    network_status_response_t* network_status_response_1 = instantiate_network_status_response(include_optional);

	cJSON* jsonnetwork_status_response_1 = network_status_response_convertToJSON(network_status_response_1);
	printf("network_status_response :\n%s\n", cJSON_Print(jsonnetwork_status_response_1));
	network_status_response_t* network_status_response_2 = network_status_response_parseFromJSON(jsonnetwork_status_response_1);
	cJSON* jsonnetwork_status_response_2 = network_status_response_convertToJSON(network_status_response_2);
	printf("repeating network_status_response:\n%s\n", cJSON_Print(jsonnetwork_status_response_2));
}

int main() {
  test_network_status_response(1);
  test_network_status_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_status_response_MAIN
#endif // network_status_response_TEST
