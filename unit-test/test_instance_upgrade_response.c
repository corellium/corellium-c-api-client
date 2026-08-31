#ifndef instance_upgrade_response_TEST
#define instance_upgrade_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_upgrade_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_upgrade_response.h"
instance_upgrade_response_t* instantiate_instance_upgrade_response(int include_optional);



instance_upgrade_response_t* instantiate_instance_upgrade_response(int include_optional) {
  instance_upgrade_response_t* instance_upgrade_response = NULL;
  if (include_optional) {
    instance_upgrade_response = instance_upgrade_response_create(
      "0",
      corellium_api_instance_upgrade_response_STATE_updating
    );
  } else {
    instance_upgrade_response = instance_upgrade_response_create(
      "0",
      corellium_api_instance_upgrade_response_STATE_updating
    );
  }

  return instance_upgrade_response;
}


#ifdef instance_upgrade_response_MAIN

void test_instance_upgrade_response(int include_optional) {
    instance_upgrade_response_t* instance_upgrade_response_1 = instantiate_instance_upgrade_response(include_optional);

	cJSON* jsoninstance_upgrade_response_1 = instance_upgrade_response_convertToJSON(instance_upgrade_response_1);
	printf("instance_upgrade_response :\n%s\n", cJSON_Print(jsoninstance_upgrade_response_1));
	instance_upgrade_response_t* instance_upgrade_response_2 = instance_upgrade_response_parseFromJSON(jsoninstance_upgrade_response_1);
	cJSON* jsoninstance_upgrade_response_2 = instance_upgrade_response_convertToJSON(instance_upgrade_response_2);
	printf("repeating instance_upgrade_response:\n%s\n", cJSON_Print(jsoninstance_upgrade_response_2));
}

int main() {
  test_instance_upgrade_response(1);
  test_instance_upgrade_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_upgrade_response_MAIN
#endif // instance_upgrade_response_TEST
