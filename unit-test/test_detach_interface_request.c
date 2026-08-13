#ifndef detach_interface_request_TEST
#define detach_interface_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define detach_interface_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/detach_interface_request.h"
detach_interface_request_t* instantiate_detach_interface_request(int include_optional);



detach_interface_request_t* instantiate_detach_interface_request(int include_optional) {
  detach_interface_request_t* detach_interface_request = NULL;
  if (include_optional) {
    detach_interface_request = detach_interface_request_create(
      "0"
    );
  } else {
    detach_interface_request = detach_interface_request_create(
      "0"
    );
  }

  return detach_interface_request;
}


#ifdef detach_interface_request_MAIN

void test_detach_interface_request(int include_optional) {
    detach_interface_request_t* detach_interface_request_1 = instantiate_detach_interface_request(include_optional);

	cJSON* jsondetach_interface_request_1 = detach_interface_request_convertToJSON(detach_interface_request_1);
	printf("detach_interface_request :\n%s\n", cJSON_Print(jsondetach_interface_request_1));
	detach_interface_request_t* detach_interface_request_2 = detach_interface_request_parseFromJSON(jsondetach_interface_request_1);
	cJSON* jsondetach_interface_request_2 = detach_interface_request_convertToJSON(detach_interface_request_2);
	printf("repeating detach_interface_request:\n%s\n", cJSON_Print(jsondetach_interface_request_2));
}

int main() {
  test_detach_interface_request(1);
  test_detach_interface_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // detach_interface_request_MAIN
#endif // detach_interface_request_TEST
