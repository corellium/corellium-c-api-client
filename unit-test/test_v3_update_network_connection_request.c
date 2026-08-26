#ifndef v3_update_network_connection_request_TEST
#define v3_update_network_connection_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v3_update_network_connection_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v3_update_network_connection_request.h"
v3_update_network_connection_request_t* instantiate_v3_update_network_connection_request(int include_optional);

#include "test_v3_update_network_connection_request_config.c"


v3_update_network_connection_request_t* instantiate_v3_update_network_connection_request(int include_optional) {
  v3_update_network_connection_request_t* v3_update_network_connection_request = NULL;
  if (include_optional) {
    v3_update_network_connection_request = v3_update_network_connection_request_create(
      "0",
      null,
      1
    );
  } else {
    v3_update_network_connection_request = v3_update_network_connection_request_create(
      "0",
      null,
      1
    );
  }

  return v3_update_network_connection_request;
}


#ifdef v3_update_network_connection_request_MAIN

void test_v3_update_network_connection_request(int include_optional) {
    v3_update_network_connection_request_t* v3_update_network_connection_request_1 = instantiate_v3_update_network_connection_request(include_optional);

	cJSON* jsonv3_update_network_connection_request_1 = v3_update_network_connection_request_convertToJSON(v3_update_network_connection_request_1);
	printf("v3_update_network_connection_request :\n%s\n", cJSON_Print(jsonv3_update_network_connection_request_1));
	v3_update_network_connection_request_t* v3_update_network_connection_request_2 = v3_update_network_connection_request_parseFromJSON(jsonv3_update_network_connection_request_1);
	cJSON* jsonv3_update_network_connection_request_2 = v3_update_network_connection_request_convertToJSON(v3_update_network_connection_request_2);
	printf("repeating v3_update_network_connection_request:\n%s\n", cJSON_Print(jsonv3_update_network_connection_request_2));
}

int main() {
  test_v3_update_network_connection_request(1);
  test_v3_update_network_connection_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // v3_update_network_connection_request_MAIN
#endif // v3_update_network_connection_request_TEST
