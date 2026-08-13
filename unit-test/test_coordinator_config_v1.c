#ifndef coordinator_config_v1_TEST
#define coordinator_config_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define coordinator_config_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/coordinator_config_v1.h"
coordinator_config_v1_t* instantiate_coordinator_config_v1(int include_optional);



coordinator_config_v1_t* instantiate_coordinator_config_v1(int include_optional) {
  coordinator_config_v1_t* coordinator_config_v1 = NULL;
  if (include_optional) {
    coordinator_config_v1 = coordinator_config_v1_create(
      1
    );
  } else {
    coordinator_config_v1 = coordinator_config_v1_create(
      1
    );
  }

  return coordinator_config_v1;
}


#ifdef coordinator_config_v1_MAIN

void test_coordinator_config_v1(int include_optional) {
    coordinator_config_v1_t* coordinator_config_v1_1 = instantiate_coordinator_config_v1(include_optional);

	cJSON* jsoncoordinator_config_v1_1 = coordinator_config_v1_convertToJSON(coordinator_config_v1_1);
	printf("coordinator_config_v1 :\n%s\n", cJSON_Print(jsoncoordinator_config_v1_1));
	coordinator_config_v1_t* coordinator_config_v1_2 = coordinator_config_v1_parseFromJSON(jsoncoordinator_config_v1_1);
	cJSON* jsoncoordinator_config_v1_2 = coordinator_config_v1_convertToJSON(coordinator_config_v1_2);
	printf("repeating coordinator_config_v1:\n%s\n", cJSON_Print(jsoncoordinator_config_v1_2));
}

int main() {
  test_coordinator_config_v1(1);
  test_coordinator_config_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // coordinator_config_v1_MAIN
#endif // coordinator_config_v1_TEST
