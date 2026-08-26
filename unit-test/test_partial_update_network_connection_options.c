#ifndef partial_update_network_connection_options_TEST
#define partial_update_network_connection_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partial_update_network_connection_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partial_update_network_connection_options.h"
partial_update_network_connection_options_t* instantiate_partial_update_network_connection_options(int include_optional);

#include "test_update_network_connection_options_config.c"


partial_update_network_connection_options_t* instantiate_partial_update_network_connection_options(int include_optional) {
  partial_update_network_connection_options_t* partial_update_network_connection_options = NULL;
  if (include_optional) {
    partial_update_network_connection_options = partial_update_network_connection_options_create(
      "0",
       // false, not to have infinite recursion
      instantiate_update_network_connection_options_config(0),
      1
    );
  } else {
    partial_update_network_connection_options = partial_update_network_connection_options_create(
      "0",
      NULL,
      1
    );
  }

  return partial_update_network_connection_options;
}


#ifdef partial_update_network_connection_options_MAIN

void test_partial_update_network_connection_options(int include_optional) {
    partial_update_network_connection_options_t* partial_update_network_connection_options_1 = instantiate_partial_update_network_connection_options(include_optional);

	cJSON* jsonpartial_update_network_connection_options_1 = partial_update_network_connection_options_convertToJSON(partial_update_network_connection_options_1);
	printf("partial_update_network_connection_options :\n%s\n", cJSON_Print(jsonpartial_update_network_connection_options_1));
	partial_update_network_connection_options_t* partial_update_network_connection_options_2 = partial_update_network_connection_options_parseFromJSON(jsonpartial_update_network_connection_options_1);
	cJSON* jsonpartial_update_network_connection_options_2 = partial_update_network_connection_options_convertToJSON(partial_update_network_connection_options_2);
	printf("repeating partial_update_network_connection_options:\n%s\n", cJSON_Print(jsonpartial_update_network_connection_options_2));
}

int main() {
  test_partial_update_network_connection_options(1);
  test_partial_update_network_connection_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // partial_update_network_connection_options_MAIN
#endif // partial_update_network_connection_options_TEST
