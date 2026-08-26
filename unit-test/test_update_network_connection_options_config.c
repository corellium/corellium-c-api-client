#ifndef update_network_connection_options_config_TEST
#define update_network_connection_options_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_network_connection_options_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_network_connection_options_config.h"
update_network_connection_options_config_t* instantiate_update_network_connection_options_config(int include_optional);



update_network_connection_options_config_t* instantiate_update_network_connection_options_config(int include_optional) {
  update_network_connection_options_config_t* update_network_connection_options_config = NULL;
  if (include_optional) {
    update_network_connection_options_config = update_network_connection_options_config_create(
      "0",
      "0",
      "0",
      "0",
      1,
      corellium_api_update_network_connection_options_config_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  } else {
    update_network_connection_options_config = update_network_connection_options_config_create(
      "0",
      "0",
      "0",
      "0",
      1,
      corellium_api_update_network_connection_options_config_DHCPMODE_internal,
      "0",
      "0",
      list_createList()
    );
  }

  return update_network_connection_options_config;
}


#ifdef update_network_connection_options_config_MAIN

void test_update_network_connection_options_config(int include_optional) {
    update_network_connection_options_config_t* update_network_connection_options_config_1 = instantiate_update_network_connection_options_config(include_optional);

	cJSON* jsonupdate_network_connection_options_config_1 = update_network_connection_options_config_convertToJSON(update_network_connection_options_config_1);
	printf("update_network_connection_options_config :\n%s\n", cJSON_Print(jsonupdate_network_connection_options_config_1));
	update_network_connection_options_config_t* update_network_connection_options_config_2 = update_network_connection_options_config_parseFromJSON(jsonupdate_network_connection_options_config_1);
	cJSON* jsonupdate_network_connection_options_config_2 = update_network_connection_options_config_convertToJSON(update_network_connection_options_config_2);
	printf("repeating update_network_connection_options_config:\n%s\n", cJSON_Print(jsonupdate_network_connection_options_config_2));
}

int main() {
  test_update_network_connection_options_config(1);
  test_update_network_connection_options_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_network_connection_options_config_MAIN
#endif // update_network_connection_options_config_TEST
