#ifndef attach_interface_request_TEST
#define attach_interface_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define attach_interface_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/attach_interface_request.h"
attach_interface_request_t* instantiate_attach_interface_request(int include_optional);



attach_interface_request_t* instantiate_attach_interface_request(int include_optional) {
  attach_interface_request_t* attach_interface_request = NULL;
  if (include_optional) {
    attach_interface_request = attach_interface_request_create(
      "0",
      "0"
    );
  } else {
    attach_interface_request = attach_interface_request_create(
      "0",
      "0"
    );
  }

  return attach_interface_request;
}


#ifdef attach_interface_request_MAIN

void test_attach_interface_request(int include_optional) {
    attach_interface_request_t* attach_interface_request_1 = instantiate_attach_interface_request(include_optional);

	cJSON* jsonattach_interface_request_1 = attach_interface_request_convertToJSON(attach_interface_request_1);
	printf("attach_interface_request :\n%s\n", cJSON_Print(jsonattach_interface_request_1));
	attach_interface_request_t* attach_interface_request_2 = attach_interface_request_parseFromJSON(jsonattach_interface_request_1);
	cJSON* jsonattach_interface_request_2 = attach_interface_request_convertToJSON(attach_interface_request_2);
	printf("repeating attach_interface_request:\n%s\n", cJSON_Print(jsonattach_interface_request_2));
}

int main() {
  test_attach_interface_request(1);
  test_attach_interface_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // attach_interface_request_MAIN
#endif // attach_interface_request_TEST
