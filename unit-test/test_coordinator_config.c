#ifndef coordinator_config_TEST
#define coordinator_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define coordinator_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/coordinator_config.h"
coordinator_config_t* instantiate_coordinator_config(int include_optional);



coordinator_config_t* instantiate_coordinator_config(int include_optional) {
  coordinator_config_t* coordinator_config = NULL;
  if (include_optional) {
    coordinator_config = coordinator_config_create(
      true
    );
  } else {
    coordinator_config = coordinator_config_create(
      true
    );
  }

  return coordinator_config;
}


#ifdef coordinator_config_MAIN

void test_coordinator_config(int include_optional) {
    coordinator_config_t* coordinator_config_1 = instantiate_coordinator_config(include_optional);

	cJSON* jsoncoordinator_config_1 = coordinator_config_convertToJSON(coordinator_config_1);
	printf("coordinator_config :\n%s\n", cJSON_Print(jsoncoordinator_config_1));
	coordinator_config_t* coordinator_config_2 = coordinator_config_parseFromJSON(jsoncoordinator_config_1);
	cJSON* jsoncoordinator_config_2 = coordinator_config_convertToJSON(coordinator_config_2);
	printf("repeating coordinator_config:\n%s\n", cJSON_Print(jsoncoordinator_config_2));
}

int main() {
  test_coordinator_config(1);
  test_coordinator_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // coordinator_config_MAIN
#endif // coordinator_config_TEST
