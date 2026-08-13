#ifndef instance_upgrade_return_TEST
#define instance_upgrade_return_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_upgrade_return_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_upgrade_return.h"
instance_upgrade_return_t* instantiate_instance_upgrade_return(int include_optional);



instance_upgrade_return_t* instantiate_instance_upgrade_return(int include_optional) {
  instance_upgrade_return_t* instance_upgrade_return = NULL;
  if (include_optional) {
    instance_upgrade_return = instance_upgrade_return_create(
      "0",
      corellium_api_instance_upgrade_return_STATE_updating
    );
  } else {
    instance_upgrade_return = instance_upgrade_return_create(
      "0",
      corellium_api_instance_upgrade_return_STATE_updating
    );
  }

  return instance_upgrade_return;
}


#ifdef instance_upgrade_return_MAIN

void test_instance_upgrade_return(int include_optional) {
    instance_upgrade_return_t* instance_upgrade_return_1 = instantiate_instance_upgrade_return(include_optional);

	cJSON* jsoninstance_upgrade_return_1 = instance_upgrade_return_convertToJSON(instance_upgrade_return_1);
	printf("instance_upgrade_return :\n%s\n", cJSON_Print(jsoninstance_upgrade_return_1));
	instance_upgrade_return_t* instance_upgrade_return_2 = instance_upgrade_return_parseFromJSON(jsoninstance_upgrade_return_1);
	cJSON* jsoninstance_upgrade_return_2 = instance_upgrade_return_convertToJSON(instance_upgrade_return_2);
	printf("repeating instance_upgrade_return:\n%s\n", cJSON_Print(jsoninstance_upgrade_return_2));
}

int main() {
  test_instance_upgrade_return(1);
  test_instance_upgrade_return(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_upgrade_return_MAIN
#endif // instance_upgrade_return_TEST
