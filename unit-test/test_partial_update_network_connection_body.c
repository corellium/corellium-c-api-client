#ifndef partial_update_network_connection_body_TEST
#define partial_update_network_connection_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partial_update_network_connection_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partial_update_network_connection_body.h"
partial_update_network_connection_body_t* instantiate_partial_update_network_connection_body(int include_optional);

#include "test_network_connection_config.c"


partial_update_network_connection_body_t* instantiate_partial_update_network_connection_body(int include_optional) {
  partial_update_network_connection_body_t* partial_update_network_connection_body = NULL;
  if (include_optional) {
    partial_update_network_connection_body = partial_update_network_connection_body_create(
      "office-vpn",
      null,
      1
    );
  } else {
    partial_update_network_connection_body = partial_update_network_connection_body_create(
      "office-vpn",
      null,
      1
    );
  }

  return partial_update_network_connection_body;
}


#ifdef partial_update_network_connection_body_MAIN

void test_partial_update_network_connection_body(int include_optional) {
    partial_update_network_connection_body_t* partial_update_network_connection_body_1 = instantiate_partial_update_network_connection_body(include_optional);

	cJSON* jsonpartial_update_network_connection_body_1 = partial_update_network_connection_body_convertToJSON(partial_update_network_connection_body_1);
	printf("partial_update_network_connection_body :\n%s\n", cJSON_Print(jsonpartial_update_network_connection_body_1));
	partial_update_network_connection_body_t* partial_update_network_connection_body_2 = partial_update_network_connection_body_parseFromJSON(jsonpartial_update_network_connection_body_1);
	cJSON* jsonpartial_update_network_connection_body_2 = partial_update_network_connection_body_convertToJSON(partial_update_network_connection_body_2);
	printf("repeating partial_update_network_connection_body:\n%s\n", cJSON_Print(jsonpartial_update_network_connection_body_2));
}

int main() {
  test_partial_update_network_connection_body(1);
  test_partial_update_network_connection_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // partial_update_network_connection_body_MAIN
#endif // partial_update_network_connection_body_TEST
