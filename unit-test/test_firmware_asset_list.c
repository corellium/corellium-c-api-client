#ifndef firmware_asset_list_TEST
#define firmware_asset_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_asset_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_asset_list.h"
firmware_asset_list_t* instantiate_firmware_asset_list(int include_optional);



firmware_asset_list_t* instantiate_firmware_asset_list(int include_optional) {
  firmware_asset_list_t* firmware_asset_list = NULL;
  if (include_optional) {
    firmware_asset_list = firmware_asset_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    firmware_asset_list = firmware_asset_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return firmware_asset_list;
}


#ifdef firmware_asset_list_MAIN

void test_firmware_asset_list(int include_optional) {
    firmware_asset_list_t* firmware_asset_list_1 = instantiate_firmware_asset_list(include_optional);

	cJSON* jsonfirmware_asset_list_1 = firmware_asset_list_convertToJSON(firmware_asset_list_1);
	printf("firmware_asset_list :\n%s\n", cJSON_Print(jsonfirmware_asset_list_1));
	firmware_asset_list_t* firmware_asset_list_2 = firmware_asset_list_parseFromJSON(jsonfirmware_asset_list_1);
	cJSON* jsonfirmware_asset_list_2 = firmware_asset_list_convertToJSON(firmware_asset_list_2);
	printf("repeating firmware_asset_list:\n%s\n", cJSON_Print(jsonfirmware_asset_list_2));
}

int main() {
  test_firmware_asset_list(1);
  test_firmware_asset_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_asset_list_MAIN
#endif // firmware_asset_list_TEST
