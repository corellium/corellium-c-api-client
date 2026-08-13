#ifndef attach_interface_body_TEST
#define attach_interface_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define attach_interface_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/attach_interface_body.h"
attach_interface_body_t* instantiate_attach_interface_body(int include_optional);



attach_interface_body_t* instantiate_attach_interface_body(int include_optional) {
  attach_interface_body_t* attach_interface_body = NULL;
  if (include_optional) {
    attach_interface_body = attach_interface_body_create(
      "0",
      "0"
    );
  } else {
    attach_interface_body = attach_interface_body_create(
      "0",
      "0"
    );
  }

  return attach_interface_body;
}


#ifdef attach_interface_body_MAIN

void test_attach_interface_body(int include_optional) {
    attach_interface_body_t* attach_interface_body_1 = instantiate_attach_interface_body(include_optional);

	cJSON* jsonattach_interface_body_1 = attach_interface_body_convertToJSON(attach_interface_body_1);
	printf("attach_interface_body :\n%s\n", cJSON_Print(jsonattach_interface_body_1));
	attach_interface_body_t* attach_interface_body_2 = attach_interface_body_parseFromJSON(jsonattach_interface_body_1);
	cJSON* jsonattach_interface_body_2 = attach_interface_body_convertToJSON(attach_interface_body_2);
	printf("repeating attach_interface_body:\n%s\n", cJSON_Print(jsonattach_interface_body_2));
}

int main() {
  test_attach_interface_body(1);
  test_attach_interface_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // attach_interface_body_MAIN
#endif // attach_interface_body_TEST
