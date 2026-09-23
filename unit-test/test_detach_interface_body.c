#ifndef detach_interface_body_TEST
#define detach_interface_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define detach_interface_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/detach_interface_body.h"
detach_interface_body_t* instantiate_detach_interface_body(int include_optional);



detach_interface_body_t* instantiate_detach_interface_body(int include_optional) {
  detach_interface_body_t* detach_interface_body = NULL;
  if (include_optional) {
    detach_interface_body = detach_interface_body_create(
      "56494514-33f7-4fc2-9fdc-865e3957e6d3"
    );
  } else {
    detach_interface_body = detach_interface_body_create(
      "56494514-33f7-4fc2-9fdc-865e3957e6d3"
    );
  }

  return detach_interface_body;
}


#ifdef detach_interface_body_MAIN

void test_detach_interface_body(int include_optional) {
    detach_interface_body_t* detach_interface_body_1 = instantiate_detach_interface_body(include_optional);

	cJSON* jsondetach_interface_body_1 = detach_interface_body_convertToJSON(detach_interface_body_1);
	printf("detach_interface_body :\n%s\n", cJSON_Print(jsondetach_interface_body_1));
	detach_interface_body_t* detach_interface_body_2 = detach_interface_body_parseFromJSON(jsondetach_interface_body_1);
	cJSON* jsondetach_interface_body_2 = detach_interface_body_convertToJSON(detach_interface_body_2);
	printf("repeating detach_interface_body:\n%s\n", cJSON_Print(jsondetach_interface_body_2));
}

int main() {
  test_detach_interface_body(1);
  test_detach_interface_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // detach_interface_body_MAIN
#endif // detach_interface_body_TEST
