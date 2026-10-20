#ifndef firmware_TEST
#define firmware_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware.h"
firmware_t* instantiate_firmware(int include_optional);



firmware_t* instantiate_firmware(int include_optional) {
  firmware_t* firmware = NULL;
  if (include_optional) {
    firmware = firmware_create(
      ["iPhone12,1","iPhone12,3"],
      ["https://example.com/firmware-assets/asset.bin"],
      "firmware.ipsw",
      "ios",
      7838404608,
      "https://example.com/firmware.ipsw",
      "17.5",
      "21F79",
      "5d41402abc4b2a76b9719d911017c592",
      "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d",
      "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
      "sha256$1048576$2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
      "2026-05-22T13:58:34.000Z",
      "2026-05-22T13:58:34.000Z",
      {"variants":["domain"]},
      "acme-fw-0001",
      "ranchu",
      "34",
      true,
      true,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    firmware = firmware_create(
      ["iPhone12,1","iPhone12,3"],
      ["https://example.com/firmware-assets/asset.bin"],
      "firmware.ipsw",
      "ios",
      7838404608,
      "https://example.com/firmware.ipsw",
      "17.5",
      "21F79",
      "5d41402abc4b2a76b9719d911017c592",
      "aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d",
      "2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
      "sha256$1048576$2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824",
      "2026-05-22T13:58:34.000Z",
      "2026-05-22T13:58:34.000Z",
      {"variants":["domain"]},
      "acme-fw-0001",
      "ranchu",
      "34",
      true,
      true,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return firmware;
}


#ifdef firmware_MAIN

void test_firmware(int include_optional) {
    firmware_t* firmware_1 = instantiate_firmware(include_optional);

	cJSON* jsonfirmware_1 = firmware_convertToJSON(firmware_1);
	printf("firmware :\n%s\n", cJSON_Print(jsonfirmware_1));
	firmware_t* firmware_2 = firmware_parseFromJSON(jsonfirmware_1);
	cJSON* jsonfirmware_2 = firmware_convertToJSON(firmware_2);
	printf("repeating firmware:\n%s\n", cJSON_Print(jsonfirmware_2));
}

int main() {
  test_firmware(1);
  test_firmware(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_MAIN
#endif // firmware_TEST
