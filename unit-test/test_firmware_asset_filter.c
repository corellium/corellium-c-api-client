#ifndef firmware_asset_filter_TEST
#define firmware_asset_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_asset_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_asset_filter.h"
firmware_asset_filter_t* instantiate_firmware_asset_filter(int include_optional);



firmware_asset_filter_t* instantiate_firmware_asset_filter(int include_optional) {
  firmware_asset_filter_t* firmware_asset_filter = NULL;
  if (include_optional) {
    firmware_asset_filter = firmware_asset_filter_create(
      "0",
      "0"
    );
  } else {
    firmware_asset_filter = firmware_asset_filter_create(
      "0",
      "0"
    );
  }

  return firmware_asset_filter;
}


#ifdef firmware_asset_filter_MAIN

void test_firmware_asset_filter(int include_optional) {
    firmware_asset_filter_t* firmware_asset_filter_1 = instantiate_firmware_asset_filter(include_optional);

	cJSON* jsonfirmware_asset_filter_1 = firmware_asset_filter_convertToJSON(firmware_asset_filter_1);
	printf("firmware_asset_filter :\n%s\n", cJSON_Print(jsonfirmware_asset_filter_1));
	firmware_asset_filter_t* firmware_asset_filter_2 = firmware_asset_filter_parseFromJSON(jsonfirmware_asset_filter_1);
	cJSON* jsonfirmware_asset_filter_2 = firmware_asset_filter_convertToJSON(firmware_asset_filter_2);
	printf("repeating firmware_asset_filter:\n%s\n", cJSON_Print(jsonfirmware_asset_filter_2));
}

int main() {
  test_firmware_asset_filter(1);
  test_firmware_asset_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_asset_filter_MAIN
#endif // firmware_asset_filter_TEST
