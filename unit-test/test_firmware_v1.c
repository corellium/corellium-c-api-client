#ifndef firmware_v1_TEST
#define firmware_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_v1.h"
firmware_v1_t* instantiate_firmware_v1(int include_optional);



firmware_v1_t* instantiate_firmware_v1(int include_optional) {
  firmware_v1_t* firmware_v1 = NULL;
  if (include_optional) {
    firmware_v1 = firmware_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  } else {
    firmware_v1 = firmware_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      56,
      "0",
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  }

  return firmware_v1;
}


#ifdef firmware_v1_MAIN

void test_firmware_v1(int include_optional) {
    firmware_v1_t* firmware_v1_1 = instantiate_firmware_v1(include_optional);

	cJSON* jsonfirmware_v1_1 = firmware_v1_convertToJSON(firmware_v1_1);
	printf("firmware_v1 :\n%s\n", cJSON_Print(jsonfirmware_v1_1));
	firmware_v1_t* firmware_v1_2 = firmware_v1_parseFromJSON(jsonfirmware_v1_1);
	cJSON* jsonfirmware_v1_2 = firmware_v1_convertToJSON(firmware_v1_2);
	printf("repeating firmware_v1:\n%s\n", cJSON_Print(jsonfirmware_v1_2));
}

int main() {
  test_firmware_v1(1);
  test_firmware_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_v1_MAIN
#endif // firmware_v1_TEST
