#ifndef peripherals_data_TEST
#define peripherals_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define peripherals_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/peripherals_data.h"
peripherals_data_t* instantiate_peripherals_data(int include_optional);



peripherals_data_t* instantiate_peripherals_data(int include_optional) {
  peripherals_data_t* peripherals_data = NULL;
  if (include_optional) {
    peripherals_data = peripherals_data_create(
      [0,9.81,0],
      [0,0,0],
      [0,45,0],
      [0,0,0],
      25,
      50,
      20,
      1013.25,
      55,
      37.4143,
      -122.0774,
      45,
      0,
      corellium_api_peripherals_data_ACONLINE_0,
      corellium_api_peripherals_data_BATTERYPRESENT_0,
      corellium_api_peripherals_data_BATTERYSTATUS_"charging",
      corellium_api_peripherals_data_BATTERYHEALTH_"good",
      82,
      corellium_api_peripherals_data_BIOMETRICPASS_0
    );
  } else {
    peripherals_data = peripherals_data_create(
      [0,9.81,0],
      [0,0,0],
      [0,45,0],
      [0,0,0],
      25,
      50,
      20,
      1013.25,
      55,
      37.4143,
      -122.0774,
      45,
      0,
      corellium_api_peripherals_data_ACONLINE_0,
      corellium_api_peripherals_data_BATTERYPRESENT_0,
      corellium_api_peripherals_data_BATTERYSTATUS_"charging",
      corellium_api_peripherals_data_BATTERYHEALTH_"good",
      82,
      corellium_api_peripherals_data_BIOMETRICPASS_0
    );
  }

  return peripherals_data;
}


#ifdef peripherals_data_MAIN

void test_peripherals_data(int include_optional) {
    peripherals_data_t* peripherals_data_1 = instantiate_peripherals_data(include_optional);

	cJSON* jsonperipherals_data_1 = peripherals_data_convertToJSON(peripherals_data_1);
	printf("peripherals_data :\n%s\n", cJSON_Print(jsonperipherals_data_1));
	peripherals_data_t* peripherals_data_2 = peripherals_data_parseFromJSON(jsonperipherals_data_1);
	cJSON* jsonperipherals_data_2 = peripherals_data_convertToJSON(peripherals_data_2);
	printf("repeating peripherals_data:\n%s\n", cJSON_Print(jsonperipherals_data_2));
}

int main() {
  test_peripherals_data(1);
  test_peripherals_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // peripherals_data_MAIN
#endif // peripherals_data_TEST
