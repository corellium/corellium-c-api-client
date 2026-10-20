#ifndef gpio_state_definition_banks_inner_inner_TEST
#define gpio_state_definition_banks_inner_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gpio_state_definition_banks_inner_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gpio_state_definition_banks_inner_inner.h"
gpio_state_definition_banks_inner_inner_t* instantiate_gpio_state_definition_banks_inner_inner(int include_optional);



gpio_state_definition_banks_inner_inner_t* instantiate_gpio_state_definition_banks_inner_inner(int include_optional) {
  gpio_state_definition_banks_inner_inner_t* gpio_state_definition_banks_inner_inner = NULL;
  if (include_optional) {
    gpio_state_definition_banks_inner_inner = gpio_state_definition_banks_inner_inner_create(
    );
  } else {
    gpio_state_definition_banks_inner_inner = gpio_state_definition_banks_inner_inner_create(
    );
  }

  return gpio_state_definition_banks_inner_inner;
}


#ifdef gpio_state_definition_banks_inner_inner_MAIN

void test_gpio_state_definition_banks_inner_inner(int include_optional) {
    gpio_state_definition_banks_inner_inner_t* gpio_state_definition_banks_inner_inner_1 = instantiate_gpio_state_definition_banks_inner_inner(include_optional);

	cJSON* jsongpio_state_definition_banks_inner_inner_1 = gpio_state_definition_banks_inner_inner_convertToJSON(gpio_state_definition_banks_inner_inner_1);
	printf("gpio_state_definition_banks_inner_inner :\n%s\n", cJSON_Print(jsongpio_state_definition_banks_inner_inner_1));
	gpio_state_definition_banks_inner_inner_t* gpio_state_definition_banks_inner_inner_2 = gpio_state_definition_banks_inner_inner_parseFromJSON(jsongpio_state_definition_banks_inner_inner_1);
	cJSON* jsongpio_state_definition_banks_inner_inner_2 = gpio_state_definition_banks_inner_inner_convertToJSON(gpio_state_definition_banks_inner_inner_2);
	printf("repeating gpio_state_definition_banks_inner_inner:\n%s\n", cJSON_Print(jsongpio_state_definition_banks_inner_inner_2));
}

int main() {
  test_gpio_state_definition_banks_inner_inner(1);
  test_gpio_state_definition_banks_inner_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // gpio_state_definition_banks_inner_inner_MAIN
#endif // gpio_state_definition_banks_inner_inner_TEST
