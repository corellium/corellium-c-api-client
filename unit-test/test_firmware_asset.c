#ifndef firmware_asset_TEST
#define firmware_asset_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_asset_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_asset.h"
firmware_asset_t* instantiate_firmware_asset(int include_optional);



firmware_asset_t* instantiate_firmware_asset(int include_optional) {
  firmware_asset_t* firmware_asset = NULL;
  if (include_optional) {
    firmware_asset = firmware_asset_create(
      "0",
      "0",
      "0",
      1.337,
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    firmware_asset = firmware_asset_create(
      "0",
      "0",
      "0",
      1.337,
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return firmware_asset;
}


#ifdef firmware_asset_MAIN

void test_firmware_asset(int include_optional) {
    firmware_asset_t* firmware_asset_1 = instantiate_firmware_asset(include_optional);

	cJSON* jsonfirmware_asset_1 = firmware_asset_convertToJSON(firmware_asset_1);
	printf("firmware_asset :\n%s\n", cJSON_Print(jsonfirmware_asset_1));
	firmware_asset_t* firmware_asset_2 = firmware_asset_parseFromJSON(jsonfirmware_asset_1);
	cJSON* jsonfirmware_asset_2 = firmware_asset_convertToJSON(firmware_asset_2);
	printf("repeating firmware_asset:\n%s\n", cJSON_Print(jsonfirmware_asset_2));
}

int main() {
  test_firmware_asset(1);
  test_firmware_asset(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_asset_MAIN
#endif // firmware_asset_TEST
