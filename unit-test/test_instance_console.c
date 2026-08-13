#ifndef instance_console_TEST
#define instance_console_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_console_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance_console.h"
instance_console_t* instantiate_instance_console(int include_optional);



instance_console_t* instantiate_instance_console(int include_optional) {
  instance_console_t* instance_console = NULL;
  if (include_optional) {
    instance_console = instance_console_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    instance_console = instance_console_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return instance_console;
}


#ifdef instance_console_MAIN

void test_instance_console(int include_optional) {
    instance_console_t* instance_console_1 = instantiate_instance_console(include_optional);

	cJSON* jsoninstance_console_1 = instance_console_convertToJSON(instance_console_1);
	printf("instance_console :\n%s\n", cJSON_Print(jsoninstance_console_1));
	instance_console_t* instance_console_2 = instance_console_parseFromJSON(jsoninstance_console_1);
	cJSON* jsoninstance_console_2 = instance_console_convertToJSON(instance_console_2);
	printf("repeating instance_console:\n%s\n", cJSON_Print(jsoninstance_console_2));
}

int main() {
  test_instance_console(1);
  test_instance_console(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_console_MAIN
#endif // instance_console_TEST
