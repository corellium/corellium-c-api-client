#ifndef config_response_TEST
#define config_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_response.h"
config_response_t* instantiate_config_response(int include_optional);

#include "test_config_response_maintenance.c"
#include "test_logging.c"
#include "test_trial.c"
#include "test_config_response_coordinator_config.c"
#include "test_config_response_ai_tools_config.c"


config_response_t* instantiate_config_response(int include_optional) {
  config_response_t* config_response = NULL;
  if (include_optional) {
    config_response = config_response_create(
      false,
      ["bridged","nat","routed"],
      corellium_api_config_response_NETWORKTYPE_bridged,
      false,
      "7.4.0-28212",
      false,
      true,
      true,
      "pk_test_xxxxxxxxxxxxxxxxxxxxxxxx",
      "abc12345",
      "GTM-ABCD123",
      "stripe",
       // false, not to have infinite recursion
      instantiate_config_response_maintenance(0),
       // false, not to have infinite recursion
      instantiate_logging(0),
      "https://admin.corellium.com/login",
      "https://onsite.corellium.com/login",
      "corellium.com",
      "billing.app.corellium.com",
      "app.corellium.com",
      "2000m",
      true,
      list_createList(),
      "Welcome to the Corellium virtual device platform!",
      10,
      104857600,
      524288000,
      true,
       // false, not to have infinite recursion
      instantiate_trial(0),
      "https://sentry.example.com",
      false,
      false,
      "Corellium",
      false,
      "http://downloads.sourceforge.net/project/opengapps/arm64/20220119/open_gapps-arm64-11.0-pico-20220119.zip",
      false,
      null,
       // false, not to have infinite recursion
      instantiate_config_response_ai_tools_config(0)
    );
  } else {
    config_response = config_response_create(
      false,
      ["bridged","nat","routed"],
      corellium_api_config_response_NETWORKTYPE_bridged,
      false,
      "7.4.0-28212",
      false,
      true,
      true,
      "pk_test_xxxxxxxxxxxxxxxxxxxxxxxx",
      "abc12345",
      "GTM-ABCD123",
      "stripe",
      NULL,
      NULL,
      "https://admin.corellium.com/login",
      "https://onsite.corellium.com/login",
      "corellium.com",
      "billing.app.corellium.com",
      "app.corellium.com",
      "2000m",
      true,
      list_createList(),
      "Welcome to the Corellium virtual device platform!",
      10,
      104857600,
      524288000,
      true,
      NULL,
      "https://sentry.example.com",
      false,
      false,
      "Corellium",
      false,
      "http://downloads.sourceforge.net/project/opengapps/arm64/20220119/open_gapps-arm64-11.0-pico-20220119.zip",
      false,
      null,
      NULL
    );
  }

  return config_response;
}


#ifdef config_response_MAIN

void test_config_response(int include_optional) {
    config_response_t* config_response_1 = instantiate_config_response(include_optional);

	cJSON* jsonconfig_response_1 = config_response_convertToJSON(config_response_1);
	printf("config_response :\n%s\n", cJSON_Print(jsonconfig_response_1));
	config_response_t* config_response_2 = config_response_parseFromJSON(jsonconfig_response_1);
	cJSON* jsonconfig_response_2 = config_response_convertToJSON(config_response_2);
	printf("repeating config_response:\n%s\n", cJSON_Print(jsonconfig_response_2));
}

int main() {
  test_config_response(1);
  test_config_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_response_MAIN
#endif // config_response_TEST
