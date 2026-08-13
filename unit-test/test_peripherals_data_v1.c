#ifndef peripherals_data_v1_TEST
#define peripherals_data_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define peripherals_data_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/peripherals_data_v1.h"
peripherals_data_v1_t* instantiate_peripherals_data_v1(int include_optional);



peripherals_data_v1_t* instantiate_peripherals_data_v1(int include_optional) {
  peripherals_data_v1_t* peripherals_data_v1 = NULL;
  if (include_optional) {
    peripherals_data_v1 = peripherals_data_v1_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      "0",
      "0",
      1.337
    );
  } else {
    peripherals_data_v1 = peripherals_data_v1_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      "0",
      "0",
      1.337
    );
  }

  return peripherals_data_v1;
}


#ifdef peripherals_data_v1_MAIN

void test_peripherals_data_v1(int include_optional) {
    peripherals_data_v1_t* peripherals_data_v1_1 = instantiate_peripherals_data_v1(include_optional);

	cJSON* jsonperipherals_data_v1_1 = peripherals_data_v1_convertToJSON(peripherals_data_v1_1);
	printf("peripherals_data_v1 :\n%s\n", cJSON_Print(jsonperipherals_data_v1_1));
	peripherals_data_v1_t* peripherals_data_v1_2 = peripherals_data_v1_parseFromJSON(jsonperipherals_data_v1_1);
	cJSON* jsonperipherals_data_v1_2 = peripherals_data_v1_convertToJSON(peripherals_data_v1_2);
	printf("repeating peripherals_data_v1:\n%s\n", cJSON_Print(jsonperipherals_data_v1_2));
}

int main() {
  test_peripherals_data_v1(1);
  test_peripherals_data_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // peripherals_data_v1_MAIN
#endif // peripherals_data_v1_TEST
