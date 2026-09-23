#ifndef firmware_info_device_firmwares_inner_TEST
#define firmware_info_device_firmwares_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define firmware_info_device_firmwares_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/firmware_info_device_firmwares_inner.h"
firmware_info_device_firmwares_inner_t* instantiate_firmware_info_device_firmwares_inner(int include_optional);



firmware_info_device_firmwares_inner_t* instantiate_firmware_info_device_firmwares_inner(int include_optional) {
  firmware_info_device_firmwares_inner_t* firmware_info_device_firmwares_inner = NULL;
  if (include_optional) {
    firmware_info_device_firmwares_inner = firmware_info_device_firmwares_inner_create(
      "iPhone12,1_16.4_20E247_Restore.ipsw",
      "16.4",
      "20E247",
      "https://example.com/download/iPhone12,1_16.4_20E247_Restore.ipsw",
      "https://example.com/vendor/iPhone12,1_16.4_20E247_Restore.ipsw"
    );
  } else {
    firmware_info_device_firmwares_inner = firmware_info_device_firmwares_inner_create(
      "iPhone12,1_16.4_20E247_Restore.ipsw",
      "16.4",
      "20E247",
      "https://example.com/download/iPhone12,1_16.4_20E247_Restore.ipsw",
      "https://example.com/vendor/iPhone12,1_16.4_20E247_Restore.ipsw"
    );
  }

  return firmware_info_device_firmwares_inner;
}


#ifdef firmware_info_device_firmwares_inner_MAIN

void test_firmware_info_device_firmwares_inner(int include_optional) {
    firmware_info_device_firmwares_inner_t* firmware_info_device_firmwares_inner_1 = instantiate_firmware_info_device_firmwares_inner(include_optional);

	cJSON* jsonfirmware_info_device_firmwares_inner_1 = firmware_info_device_firmwares_inner_convertToJSON(firmware_info_device_firmwares_inner_1);
	printf("firmware_info_device_firmwares_inner :\n%s\n", cJSON_Print(jsonfirmware_info_device_firmwares_inner_1));
	firmware_info_device_firmwares_inner_t* firmware_info_device_firmwares_inner_2 = firmware_info_device_firmwares_inner_parseFromJSON(jsonfirmware_info_device_firmwares_inner_1);
	cJSON* jsonfirmware_info_device_firmwares_inner_2 = firmware_info_device_firmwares_inner_convertToJSON(firmware_info_device_firmwares_inner_2);
	printf("repeating firmware_info_device_firmwares_inner:\n%s\n", cJSON_Print(jsonfirmware_info_device_firmwares_inner_2));
}

int main() {
  test_firmware_info_device_firmwares_inner(1);
  test_firmware_info_device_firmwares_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // firmware_info_device_firmwares_inner_MAIN
#endif // firmware_info_device_firmwares_inner_TEST
