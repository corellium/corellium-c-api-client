#ifndef instance_read_only_status_TEST
#define instance_read_only_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_read_only_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_read_only_status.h"
instance_read_only_status_t* instantiate_instance_read_only_status(int include_optional);



instance_read_only_status_t* instantiate_instance_read_only_status(int include_optional) {
  instance_read_only_status_t* instance_read_only_status = NULL;
  if (include_optional) {
    instance_read_only_status = instance_read_only_status_create(
      "0"
    );
  } else {
    instance_read_only_status = instance_read_only_status_create(
      "0"
    );
  }

  return instance_read_only_status;
}


#ifdef instance_read_only_status_MAIN

void test_instance_read_only_status(int include_optional) {
    instance_read_only_status_t* instance_read_only_status_1 = instantiate_instance_read_only_status(include_optional);

	cJSON* jsoninstance_read_only_status_1 = instance_read_only_status_convertToJSON(instance_read_only_status_1);
	printf("instance_read_only_status :\n%s\n", cJSON_Print(jsoninstance_read_only_status_1));
	instance_read_only_status_t* instance_read_only_status_2 = instance_read_only_status_parseFromJSON(jsoninstance_read_only_status_1);
	cJSON* jsoninstance_read_only_status_2 = instance_read_only_status_convertToJSON(instance_read_only_status_2);
	printf("repeating instance_read_only_status:\n%s\n", cJSON_Print(jsoninstance_read_only_status_2));
}

int main() {
  test_instance_read_only_status(1);
  test_instance_read_only_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_read_only_status_MAIN
#endif // instance_read_only_status_TEST
