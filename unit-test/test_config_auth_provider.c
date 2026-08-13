#ifndef config_auth_provider_TEST
#define config_auth_provider_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_auth_provider_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_auth_provider.h"
config_auth_provider_t* instantiate_config_auth_provider(int include_optional);



config_auth_provider_t* instantiate_config_auth_provider(int include_optional) {
  config_auth_provider_t* config_auth_provider = NULL;
  if (include_optional) {
    config_auth_provider = config_auth_provider_create(
      "0",
      "0",
      1,
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    config_auth_provider = config_auth_provider_create(
      "0",
      "0",
      1,
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return config_auth_provider;
}


#ifdef config_auth_provider_MAIN

void test_config_auth_provider(int include_optional) {
    config_auth_provider_t* config_auth_provider_1 = instantiate_config_auth_provider(include_optional);

	cJSON* jsonconfig_auth_provider_1 = config_auth_provider_convertToJSON(config_auth_provider_1);
	printf("config_auth_provider :\n%s\n", cJSON_Print(jsonconfig_auth_provider_1));
	config_auth_provider_t* config_auth_provider_2 = config_auth_provider_parseFromJSON(jsonconfig_auth_provider_1);
	cJSON* jsonconfig_auth_provider_2 = config_auth_provider_convertToJSON(config_auth_provider_2);
	printf("repeating config_auth_provider:\n%s\n", cJSON_Print(jsonconfig_auth_provider_2));
}

int main() {
  test_config_auth_provider(1);
  test_config_auth_provider(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_auth_provider_MAIN
#endif // config_auth_provider_TEST
