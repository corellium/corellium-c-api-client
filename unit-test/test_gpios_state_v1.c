#ifndef gpios_state_v1_TEST
#define gpios_state_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gpios_state_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gpios_state_v1.h"
gpios_state_v1_t* instantiate_gpios_state_v1(int include_optional);

#include "test_gpio_state_definition_v1.c"
#include "test_gpio_state_definition_v1.c"
#include "test_gpio_state_definition_v1.c"


gpios_state_v1_t* instantiate_gpios_state_v1(int include_optional) {
  gpios_state_v1_t* gpios_state_v1 = NULL;
  if (include_optional) {
    gpios_state_v1 = gpios_state_v1_create(
       // false, not to have infinite recursion
      instantiate_gpio_state_definition_v1(0),
       // false, not to have infinite recursion
      instantiate_gpio_state_definition_v1(0),
       // false, not to have infinite recursion
      instantiate_gpio_state_definition_v1(0)
    );
  } else {
    gpios_state_v1 = gpios_state_v1_create(
      NULL,
      NULL,
      NULL
    );
  }

  return gpios_state_v1;
}


#ifdef gpios_state_v1_MAIN

void test_gpios_state_v1(int include_optional) {
    gpios_state_v1_t* gpios_state_v1_1 = instantiate_gpios_state_v1(include_optional);

	cJSON* jsongpios_state_v1_1 = gpios_state_v1_convertToJSON(gpios_state_v1_1);
	printf("gpios_state_v1 :\n%s\n", cJSON_Print(jsongpios_state_v1_1));
	gpios_state_v1_t* gpios_state_v1_2 = gpios_state_v1_parseFromJSON(jsongpios_state_v1_1);
	cJSON* jsongpios_state_v1_2 = gpios_state_v1_convertToJSON(gpios_state_v1_2);
	printf("repeating gpios_state_v1:\n%s\n", cJSON_Print(jsongpios_state_v1_2));
}

int main() {
  test_gpios_state_v1(1);
  test_gpios_state_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // gpios_state_v1_MAIN
#endif // gpios_state_v1_TEST
