#ifndef config_response_v1_TEST
#define config_response_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_response_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_response_v1.h"
config_response_v1_t* instantiate_config_response_v1(int include_optional);

#include "test_logging_v1.c"
#include "test_trial_v1.c"
#include "test_coordinator_config_v1.c"


config_response_v1_t* instantiate_config_response_v1(int include_optional) {
  config_response_v1_t* config_response_v1 = NULL;
  if (include_optional) {
    config_response_v1 = config_response_v1_create(
      1,
      list_createList(),
      "0",
      1,
      "0",
      1,
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      0,
       // false, not to have infinite recursion
      instantiate_logging_v1(0),
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      list_createList(),
      1.337,
      1.337,
      1.337,
      1,
       // false, not to have infinite recursion
      instantiate_trial_v1(0),
      "0",
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_coordinator_config_v1(0)
    );
  } else {
    config_response_v1 = config_response_v1_create(
      1,
      list_createList(),
      "0",
      1,
      "0",
      1,
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      0,
      NULL,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      list_createList(),
      1.337,
      1.337,
      1.337,
      1,
      NULL,
      "0",
      1,
      "0",
      NULL
    );
  }

  return config_response_v1;
}


#ifdef config_response_v1_MAIN

void test_config_response_v1(int include_optional) {
    config_response_v1_t* config_response_v1_1 = instantiate_config_response_v1(include_optional);

	cJSON* jsonconfig_response_v1_1 = config_response_v1_convertToJSON(config_response_v1_1);
	printf("config_response_v1 :\n%s\n", cJSON_Print(jsonconfig_response_v1_1));
	config_response_v1_t* config_response_v1_2 = config_response_v1_parseFromJSON(jsonconfig_response_v1_1);
	cJSON* jsonconfig_response_v1_2 = config_response_v1_convertToJSON(config_response_v1_2);
	printf("repeating config_response_v1:\n%s\n", cJSON_Print(jsonconfig_response_v1_2));
}

int main() {
  test_config_response_v1(1);
  test_config_response_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_response_v1_MAIN
#endif // config_response_v1_TEST
