#ifndef instance_interface_status_TEST
#define instance_interface_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_interface_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_interface_status.h"
instance_interface_status_t* instantiate_instance_interface_status(int include_optional);



instance_interface_status_t* instantiate_instance_interface_status(int include_optional) {
  instance_interface_status_t* instance_interface_status = NULL;
  if (include_optional) {
    instance_interface_status = instance_interface_status_create(
      "gpio/0",
      "56494514-33f7-4fc2-9fdc-865e3957e6d3",
      corellium_api_instance_interface_status_STATUS_attached
    );
  } else {
    instance_interface_status = instance_interface_status_create(
      "gpio/0",
      "56494514-33f7-4fc2-9fdc-865e3957e6d3",
      corellium_api_instance_interface_status_STATUS_attached
    );
  }

  return instance_interface_status;
}


#ifdef instance_interface_status_MAIN

void test_instance_interface_status(int include_optional) {
    instance_interface_status_t* instance_interface_status_1 = instantiate_instance_interface_status(include_optional);

	cJSON* jsoninstance_interface_status_1 = instance_interface_status_convertToJSON(instance_interface_status_1);
	printf("instance_interface_status :\n%s\n", cJSON_Print(jsoninstance_interface_status_1));
	instance_interface_status_t* instance_interface_status_2 = instance_interface_status_parseFromJSON(jsoninstance_interface_status_1);
	cJSON* jsoninstance_interface_status_2 = instance_interface_status_convertToJSON(instance_interface_status_2);
	printf("repeating instance_interface_status:\n%s\n", cJSON_Print(jsoninstance_interface_status_2));
}

int main() {
  test_instance_interface_status(1);
  test_instance_interface_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_interface_status_MAIN
#endif // instance_interface_status_TEST
