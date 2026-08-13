#ifndef extended_firmware_asset_info_TEST
#define extended_firmware_asset_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extended_firmware_asset_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extended_firmware_asset_info.h"
extended_firmware_asset_info_t* instantiate_extended_firmware_asset_info(int include_optional);



extended_firmware_asset_info_t* instantiate_extended_firmware_asset_info(int include_optional) {
  extended_firmware_asset_info_t* extended_firmware_asset_info = NULL;
  if (include_optional) {
    extended_firmware_asset_info = extended_firmware_asset_info_create(
      list_createList(),
      list_createList()
    );
  } else {
    extended_firmware_asset_info = extended_firmware_asset_info_create(
      list_createList(),
      list_createList()
    );
  }

  return extended_firmware_asset_info;
}


#ifdef extended_firmware_asset_info_MAIN

void test_extended_firmware_asset_info(int include_optional) {
    extended_firmware_asset_info_t* extended_firmware_asset_info_1 = instantiate_extended_firmware_asset_info(include_optional);

	cJSON* jsonextended_firmware_asset_info_1 = extended_firmware_asset_info_convertToJSON(extended_firmware_asset_info_1);
	printf("extended_firmware_asset_info :\n%s\n", cJSON_Print(jsonextended_firmware_asset_info_1));
	extended_firmware_asset_info_t* extended_firmware_asset_info_2 = extended_firmware_asset_info_parseFromJSON(jsonextended_firmware_asset_info_1);
	cJSON* jsonextended_firmware_asset_info_2 = extended_firmware_asset_info_convertToJSON(extended_firmware_asset_info_2);
	printf("repeating extended_firmware_asset_info:\n%s\n", cJSON_Print(jsonextended_firmware_asset_info_2));
}

int main() {
  test_extended_firmware_asset_info(1);
  test_extended_firmware_asset_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // extended_firmware_asset_info_MAIN
#endif // extended_firmware_asset_info_TEST
