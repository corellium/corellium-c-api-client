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
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "https://example.com/firmware-assets/asset.bin",
      "aGVsbG8gd29ybGQ=",
      324,
      "5d41402abc4b2a76b9719d911017c592",
      "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d",
      "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
      "2026-05-22T13:58:34.000Z",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    firmware_asset = firmware_asset_create(
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "https://example.com/firmware-assets/asset.bin",
      "aGVsbG8gd29ybGQ=",
      324,
      "5d41402abc4b2a76b9719d911017c592",
      "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d",
      "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
      "2026-05-22T13:58:34.000Z",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
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
