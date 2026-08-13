#ifndef instance_restore_status_TEST
#define instance_restore_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_restore_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_restore_status.h"
instance_restore_status_t* instantiate_instance_restore_status(int include_optional);



instance_restore_status_t* instantiate_instance_restore_status(int include_optional) {
  instance_restore_status_t* instance_restore_status = NULL;
  if (include_optional) {
    instance_restore_status = instance_restore_status_create(
      "0",
      "0",
      0,
      0,
      "0",
      "0"
    );
  } else {
    instance_restore_status = instance_restore_status_create(
      "0",
      "0",
      0,
      0,
      "0",
      "0"
    );
  }

  return instance_restore_status;
}


#ifdef instance_restore_status_MAIN

void test_instance_restore_status(int include_optional) {
    instance_restore_status_t* instance_restore_status_1 = instantiate_instance_restore_status(include_optional);

	cJSON* jsoninstance_restore_status_1 = instance_restore_status_convertToJSON(instance_restore_status_1);
	printf("instance_restore_status :\n%s\n", cJSON_Print(jsoninstance_restore_status_1));
	instance_restore_status_t* instance_restore_status_2 = instance_restore_status_parseFromJSON(jsoninstance_restore_status_1);
	cJSON* jsoninstance_restore_status_2 = instance_restore_status_convertToJSON(instance_restore_status_2);
	printf("repeating instance_restore_status:\n%s\n", cJSON_Print(jsoninstance_restore_status_2));
}

int main() {
  test_instance_restore_status(1);
  test_instance_restore_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_restore_status_MAIN
#endif // instance_restore_status_TEST
