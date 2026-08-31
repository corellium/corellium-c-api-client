#ifndef instance_upgrade_body_TEST
#define instance_upgrade_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_upgrade_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_upgrade_body.h"
instance_upgrade_body_t* instantiate_instance_upgrade_body(int include_optional);



instance_upgrade_body_t* instantiate_instance_upgrade_body(int include_optional) {
  instance_upgrade_body_t* instance_upgrade_body = NULL;
  if (include_optional) {
    instance_upgrade_body = instance_upgrade_body_create(
      "0",
      "0"
    );
  } else {
    instance_upgrade_body = instance_upgrade_body_create(
      "0",
      "0"
    );
  }

  return instance_upgrade_body;
}


#ifdef instance_upgrade_body_MAIN

void test_instance_upgrade_body(int include_optional) {
    instance_upgrade_body_t* instance_upgrade_body_1 = instantiate_instance_upgrade_body(include_optional);

	cJSON* jsoninstance_upgrade_body_1 = instance_upgrade_body_convertToJSON(instance_upgrade_body_1);
	printf("instance_upgrade_body :\n%s\n", cJSON_Print(jsoninstance_upgrade_body_1));
	instance_upgrade_body_t* instance_upgrade_body_2 = instance_upgrade_body_parseFromJSON(jsoninstance_upgrade_body_1);
	cJSON* jsoninstance_upgrade_body_2 = instance_upgrade_body_convertToJSON(instance_upgrade_body_2);
	printf("repeating instance_upgrade_body:\n%s\n", cJSON_Print(jsoninstance_upgrade_body_2));
}

int main() {
  test_instance_upgrade_body(1);
  test_instance_upgrade_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_upgrade_body_MAIN
#endif // instance_upgrade_body_TEST
