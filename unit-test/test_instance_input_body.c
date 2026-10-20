#ifndef instance_input_body_TEST
#define instance_input_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_input_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_input_body.h"
instance_input_body_t* instantiate_instance_input_body(int include_optional);



instance_input_body_t* instantiate_instance_input_body(int include_optional) {
  instance_input_body_t* instance_input_body = NULL;
  if (include_optional) {
    instance_input_body = instance_input_body_create(
      [[100,200]],
      [finger],
      true,
      100,
      [[100,200]],
      [[100,200]],
      [[[150, 250]]],
      [finger],
      [finger],
      250,
      "Hello, world!",
      150
    );
  } else {
    instance_input_body = instance_input_body_create(
      [[100,200]],
      [finger],
      true,
      100,
      [[100,200]],
      [[100,200]],
      [[[150, 250]]],
      [finger],
      [finger],
      250,
      "Hello, world!",
      150
    );
  }

  return instance_input_body;
}


#ifdef instance_input_body_MAIN

void test_instance_input_body(int include_optional) {
    instance_input_body_t* instance_input_body_1 = instantiate_instance_input_body(include_optional);

	cJSON* jsoninstance_input_body_1 = instance_input_body_convertToJSON(instance_input_body_1);
	printf("instance_input_body :\n%s\n", cJSON_Print(jsoninstance_input_body_1));
	instance_input_body_t* instance_input_body_2 = instance_input_body_parseFromJSON(jsoninstance_input_body_1);
	cJSON* jsoninstance_input_body_2 = instance_input_body_convertToJSON(instance_input_body_2);
	printf("repeating instance_input_body:\n%s\n", cJSON_Print(jsoninstance_input_body_2));
}

int main() {
  test_instance_input_body(1);
  test_instance_input_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_input_body_MAIN
#endif // instance_input_body_TEST
