#ifndef config_response_maintenance_TEST
#define config_response_maintenance_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_response_maintenance_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_response_maintenance.h"
config_response_maintenance_t* instantiate_config_response_maintenance(int include_optional);



config_response_maintenance_t* instantiate_config_response_maintenance(int include_optional) {
  config_response_maintenance_t* config_response_maintenance = NULL;
  if (include_optional) {
    config_response_maintenance = config_response_maintenance_create(
      "The system is currently undergoing scheduled maintenance. Please check back soon.",
      "Scheduled Maintenance"
    );
  } else {
    config_response_maintenance = config_response_maintenance_create(
      "The system is currently undergoing scheduled maintenance. Please check back soon.",
      "Scheduled Maintenance"
    );
  }

  return config_response_maintenance;
}


#ifdef config_response_maintenance_MAIN

void test_config_response_maintenance(int include_optional) {
    config_response_maintenance_t* config_response_maintenance_1 = instantiate_config_response_maintenance(include_optional);

	cJSON* jsonconfig_response_maintenance_1 = config_response_maintenance_convertToJSON(config_response_maintenance_1);
	printf("config_response_maintenance :\n%s\n", cJSON_Print(jsonconfig_response_maintenance_1));
	config_response_maintenance_t* config_response_maintenance_2 = config_response_maintenance_parseFromJSON(jsonconfig_response_maintenance_1);
	cJSON* jsonconfig_response_maintenance_2 = config_response_maintenance_convertToJSON(config_response_maintenance_2);
	printf("repeating config_response_maintenance:\n%s\n", cJSON_Print(jsonconfig_response_maintenance_2));
}

int main() {
  test_config_response_maintenance(1);
  test_config_response_maintenance(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_response_maintenance_MAIN
#endif // config_response_maintenance_TEST
