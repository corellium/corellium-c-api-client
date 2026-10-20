#ifndef extended_firmware_asset_info_v1_TEST
#define extended_firmware_asset_info_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extended_firmware_asset_info_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extended_firmware_asset_info_v1.h"
extended_firmware_asset_info_v1_t* instantiate_extended_firmware_asset_info_v1(int include_optional);



extended_firmware_asset_info_v1_t* instantiate_extended_firmware_asset_info_v1(int include_optional) {
  extended_firmware_asset_info_v1_t* extended_firmware_asset_info_v1 = NULL;
  if (include_optional) {
    extended_firmware_asset_info_v1 = extended_firmware_asset_info_v1_create(
      list_createList(),
      list_createList()
    );
  } else {
    extended_firmware_asset_info_v1 = extended_firmware_asset_info_v1_create(
      list_createList(),
      list_createList()
    );
  }

  return extended_firmware_asset_info_v1;
}


#ifdef extended_firmware_asset_info_v1_MAIN

void test_extended_firmware_asset_info_v1(int include_optional) {
    extended_firmware_asset_info_v1_t* extended_firmware_asset_info_v1_1 = instantiate_extended_firmware_asset_info_v1(include_optional);

	cJSON* jsonextended_firmware_asset_info_v1_1 = extended_firmware_asset_info_v1_convertToJSON(extended_firmware_asset_info_v1_1);
	printf("extended_firmware_asset_info_v1 :\n%s\n", cJSON_Print(jsonextended_firmware_asset_info_v1_1));
	extended_firmware_asset_info_v1_t* extended_firmware_asset_info_v1_2 = extended_firmware_asset_info_v1_parseFromJSON(jsonextended_firmware_asset_info_v1_1);
	cJSON* jsonextended_firmware_asset_info_v1_2 = extended_firmware_asset_info_v1_convertToJSON(extended_firmware_asset_info_v1_2);
	printf("repeating extended_firmware_asset_info_v1:\n%s\n", cJSON_Print(jsonextended_firmware_asset_info_v1_2));
}

int main() {
  test_extended_firmware_asset_info_v1(1);
  test_extended_firmware_asset_info_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // extended_firmware_asset_info_v1_MAIN
#endif // extended_firmware_asset_info_v1_TEST
