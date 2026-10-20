#ifndef gpio_state_definition_v1_TEST
#define gpio_state_definition_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gpio_state_definition_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gpio_state_definition_v1.h"
gpio_state_definition_v1_t* instantiate_gpio_state_definition_v1(int include_optional);



gpio_state_definition_v1_t* instantiate_gpio_state_definition_v1(int include_optional) {
  gpio_state_definition_v1_t* gpio_state_definition_v1 = NULL;
  if (include_optional) {
    gpio_state_definition_v1 = gpio_state_definition_v1_create(
      1.337,
      list_createList()
    );
  } else {
    gpio_state_definition_v1 = gpio_state_definition_v1_create(
      1.337,
      list_createList()
    );
  }

  return gpio_state_definition_v1;
}


#ifdef gpio_state_definition_v1_MAIN

void test_gpio_state_definition_v1(int include_optional) {
    gpio_state_definition_v1_t* gpio_state_definition_v1_1 = instantiate_gpio_state_definition_v1(include_optional);

	cJSON* jsongpio_state_definition_v1_1 = gpio_state_definition_v1_convertToJSON(gpio_state_definition_v1_1);
	printf("gpio_state_definition_v1 :\n%s\n", cJSON_Print(jsongpio_state_definition_v1_1));
	gpio_state_definition_v1_t* gpio_state_definition_v1_2 = gpio_state_definition_v1_parseFromJSON(jsongpio_state_definition_v1_1);
	cJSON* jsongpio_state_definition_v1_2 = gpio_state_definition_v1_convertToJSON(gpio_state_definition_v1_2);
	printf("repeating gpio_state_definition_v1:\n%s\n", cJSON_Print(jsongpio_state_definition_v1_2));
}

int main() {
  test_gpio_state_definition_v1(1);
  test_gpio_state_definition_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // gpio_state_definition_v1_MAIN
#endif // gpio_state_definition_v1_TEST
