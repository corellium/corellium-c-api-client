#ifndef firmware_asset_v1_TEST
#define firmware_asset_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_asset_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_asset_v1.h"
firmware_asset_v1_t* instantiate_firmware_asset_v1(int include_optional);



firmware_asset_v1_t* instantiate_firmware_asset_v1(int include_optional) {
  firmware_asset_v1_t* firmware_asset_v1 = NULL;
  if (include_optional) {
    firmware_asset_v1 = firmware_asset_v1_create(
      "0",
      "0",
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    firmware_asset_v1 = firmware_asset_v1_create(
      "0",
      "0",
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return firmware_asset_v1;
}


#ifdef firmware_asset_v1_MAIN

void test_firmware_asset_v1(int include_optional) {
    firmware_asset_v1_t* firmware_asset_v1_1 = instantiate_firmware_asset_v1(include_optional);

	cJSON* jsonfirmware_asset_v1_1 = firmware_asset_v1_convertToJSON(firmware_asset_v1_1);
	printf("firmware_asset_v1 :\n%s\n", cJSON_Print(jsonfirmware_asset_v1_1));
	firmware_asset_v1_t* firmware_asset_v1_2 = firmware_asset_v1_parseFromJSON(jsonfirmware_asset_v1_1);
	cJSON* jsonfirmware_asset_v1_2 = firmware_asset_v1_convertToJSON(firmware_asset_v1_2);
	printf("repeating firmware_asset_v1:\n%s\n", cJSON_Print(jsonfirmware_asset_v1_2));
}

int main() {
  test_firmware_asset_v1(1);
  test_firmware_asset_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_asset_v1_MAIN
#endif // firmware_asset_v1_TEST
