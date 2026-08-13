#ifndef network_connection_pagination_result_TEST
#define network_connection_pagination_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_connection_pagination_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_connection_pagination_result.h"
network_connection_pagination_result_t* instantiate_network_connection_pagination_result(int include_optional);



network_connection_pagination_result_t* instantiate_network_connection_pagination_result(int include_optional) {
  network_connection_pagination_result_t* network_connection_pagination_result = NULL;
  if (include_optional) {
    network_connection_pagination_result = network_connection_pagination_result_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1,
      list_createList()
    );
  } else {
    network_connection_pagination_result = network_connection_pagination_result_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1,
      list_createList()
    );
  }

  return network_connection_pagination_result;
}


#ifdef network_connection_pagination_result_MAIN

void test_network_connection_pagination_result(int include_optional) {
    network_connection_pagination_result_t* network_connection_pagination_result_1 = instantiate_network_connection_pagination_result(include_optional);

	cJSON* jsonnetwork_connection_pagination_result_1 = network_connection_pagination_result_convertToJSON(network_connection_pagination_result_1);
	printf("network_connection_pagination_result :\n%s\n", cJSON_Print(jsonnetwork_connection_pagination_result_1));
	network_connection_pagination_result_t* network_connection_pagination_result_2 = network_connection_pagination_result_parseFromJSON(jsonnetwork_connection_pagination_result_1);
	cJSON* jsonnetwork_connection_pagination_result_2 = network_connection_pagination_result_convertToJSON(network_connection_pagination_result_2);
	printf("repeating network_connection_pagination_result:\n%s\n", cJSON_Print(jsonnetwork_connection_pagination_result_2));
}

int main() {
  test_network_connection_pagination_result(1);
  test_network_connection_pagination_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_connection_pagination_result_MAIN
#endif // network_connection_pagination_result_TEST
