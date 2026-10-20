#ifndef config_response_ai_tools_config_TEST
#define config_response_ai_tools_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_response_ai_tools_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_response_ai_tools_config.h"
config_response_ai_tools_config_t* instantiate_config_response_ai_tools_config(int include_optional);



config_response_ai_tools_config_t* instantiate_config_response_ai_tools_config(int include_optional) {
  config_response_ai_tools_config_t* config_response_ai_tools_config = NULL;
  if (include_optional) {
    config_response_ai_tools_config = config_response_ai_tools_config_create(
      true
    );
  } else {
    config_response_ai_tools_config = config_response_ai_tools_config_create(
      true
    );
  }

  return config_response_ai_tools_config;
}


#ifdef config_response_ai_tools_config_MAIN

void test_config_response_ai_tools_config(int include_optional) {
    config_response_ai_tools_config_t* config_response_ai_tools_config_1 = instantiate_config_response_ai_tools_config(include_optional);

	cJSON* jsonconfig_response_ai_tools_config_1 = config_response_ai_tools_config_convertToJSON(config_response_ai_tools_config_1);
	printf("config_response_ai_tools_config :\n%s\n", cJSON_Print(jsonconfig_response_ai_tools_config_1));
	config_response_ai_tools_config_t* config_response_ai_tools_config_2 = config_response_ai_tools_config_parseFromJSON(jsonconfig_response_ai_tools_config_1);
	cJSON* jsonconfig_response_ai_tools_config_2 = config_response_ai_tools_config_convertToJSON(config_response_ai_tools_config_2);
	printf("repeating config_response_ai_tools_config:\n%s\n", cJSON_Print(jsonconfig_response_ai_tools_config_2));
}

int main() {
  test_config_response_ai_tools_config(1);
  test_config_response_ai_tools_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_response_ai_tools_config_MAIN
#endif // config_response_ai_tools_config_TEST
