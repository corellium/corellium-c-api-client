#ifndef v3_update_network_connection_request_config_TEST
#define v3_update_network_connection_request_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v3_update_network_connection_request_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v3_update_network_connection_request_config.h"
v3_update_network_connection_request_config_t* instantiate_v3_update_network_connection_request_config(int include_optional);



v3_update_network_connection_request_config_t* instantiate_v3_update_network_connection_request_config(int include_optional) {
  v3_update_network_connection_request_config_t* v3_update_network_connection_request_config = NULL;
  if (include_optional) {
    v3_update_network_connection_request_config = v3_update_network_connection_request_config_create(
      "0",
      "0",
      "0",
      "0",
      1,
      corellium_api_v3_update_network_connection_request_config_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  } else {
    v3_update_network_connection_request_config = v3_update_network_connection_request_config_create(
      "0",
      "0",
      "0",
      "0",
      1,
      corellium_api_v3_update_network_connection_request_config_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  }

  return v3_update_network_connection_request_config;
}


#ifdef v3_update_network_connection_request_config_MAIN

void test_v3_update_network_connection_request_config(int include_optional) {
    v3_update_network_connection_request_config_t* v3_update_network_connection_request_config_1 = instantiate_v3_update_network_connection_request_config(include_optional);

	cJSON* jsonv3_update_network_connection_request_config_1 = v3_update_network_connection_request_config_convertToJSON(v3_update_network_connection_request_config_1);
	printf("v3_update_network_connection_request_config :\n%s\n", cJSON_Print(jsonv3_update_network_connection_request_config_1));
	v3_update_network_connection_request_config_t* v3_update_network_connection_request_config_2 = v3_update_network_connection_request_config_parseFromJSON(jsonv3_update_network_connection_request_config_1);
	cJSON* jsonv3_update_network_connection_request_config_2 = v3_update_network_connection_request_config_convertToJSON(v3_update_network_connection_request_config_2);
	printf("repeating v3_update_network_connection_request_config:\n%s\n", cJSON_Print(jsonv3_update_network_connection_request_config_2));
}

int main() {
  test_v3_update_network_connection_request_config(1);
  test_v3_update_network_connection_request_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // v3_update_network_connection_request_config_MAIN
#endif // v3_update_network_connection_request_config_TEST
