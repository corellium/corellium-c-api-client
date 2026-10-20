#ifndef instance_restore_status_v1_TEST
#define instance_restore_status_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_restore_status_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_restore_status_v1.h"
instance_restore_status_v1_t* instantiate_instance_restore_status_v1(int include_optional);



instance_restore_status_v1_t* instantiate_instance_restore_status_v1(int include_optional) {
  instance_restore_status_v1_t* instance_restore_status_v1 = NULL;
  if (include_optional) {
    instance_restore_status_v1 = instance_restore_status_v1_create(
      "0",
      "0",
      1.337,
      1.337,
      "0",
      "0"
    );
  } else {
    instance_restore_status_v1 = instance_restore_status_v1_create(
      "0",
      "0",
      1.337,
      1.337,
      "0",
      "0"
    );
  }

  return instance_restore_status_v1;
}


#ifdef instance_restore_status_v1_MAIN

void test_instance_restore_status_v1(int include_optional) {
    instance_restore_status_v1_t* instance_restore_status_v1_1 = instantiate_instance_restore_status_v1(include_optional);

	cJSON* jsoninstance_restore_status_v1_1 = instance_restore_status_v1_convertToJSON(instance_restore_status_v1_1);
	printf("instance_restore_status_v1 :\n%s\n", cJSON_Print(jsoninstance_restore_status_v1_1));
	instance_restore_status_v1_t* instance_restore_status_v1_2 = instance_restore_status_v1_parseFromJSON(jsoninstance_restore_status_v1_1);
	cJSON* jsoninstance_restore_status_v1_2 = instance_restore_status_v1_convertToJSON(instance_restore_status_v1_2);
	printf("repeating instance_restore_status_v1:\n%s\n", cJSON_Print(jsoninstance_restore_status_v1_2));
}

int main() {
  test_instance_restore_status_v1(1);
  test_instance_restore_status_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_restore_status_v1_MAIN
#endif // instance_restore_status_v1_TEST
