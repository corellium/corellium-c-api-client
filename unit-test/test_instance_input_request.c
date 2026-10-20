#ifndef instance_input_request_TEST
#define instance_input_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_input_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_input_request.h"
instance_input_request_t* instantiate_instance_input_request(int include_optional);



instance_input_request_t* instantiate_instance_input_request(int include_optional) {
  instance_input_request_t* instance_input_request = NULL;
  if (include_optional) {
    instance_input_request = instance_input_request_create(
      0,
      list_createList(),
      1,
      56,
      0,
      0,
      list_createList(),
      list_createList(),
      list_createList(),
      56,
      "0",
      56
    );
  } else {
    instance_input_request = instance_input_request_create(
      0,
      list_createList(),
      1,
      56,
      0,
      0,
      list_createList(),
      list_createList(),
      list_createList(),
      56,
      "0",
      56
    );
  }

  return instance_input_request;
}


#ifdef instance_input_request_MAIN

void test_instance_input_request(int include_optional) {
    instance_input_request_t* instance_input_request_1 = instantiate_instance_input_request(include_optional);

	cJSON* jsoninstance_input_request_1 = instance_input_request_convertToJSON(instance_input_request_1);
	printf("instance_input_request :\n%s\n", cJSON_Print(jsoninstance_input_request_1));
	instance_input_request_t* instance_input_request_2 = instance_input_request_parseFromJSON(jsoninstance_input_request_1);
	cJSON* jsoninstance_input_request_2 = instance_input_request_convertToJSON(instance_input_request_2);
	printf("repeating instance_input_request:\n%s\n", cJSON_Print(jsoninstance_input_request_2));
}

int main() {
  test_instance_input_request(1);
  test_instance_input_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_input_request_MAIN
#endif // instance_input_request_TEST
