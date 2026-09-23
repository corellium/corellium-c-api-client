#ifndef patch_firmware_service_config_body_TEST
#define patch_firmware_service_config_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_firmware_service_config_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_firmware_service_config_body.h"
patch_firmware_service_config_body_t* instantiate_patch_firmware_service_config_body(int include_optional);



patch_firmware_service_config_body_t* instantiate_patch_firmware_service_config_body(int include_optional) {
  patch_firmware_service_config_body_t* patch_firmware_service_config_body = NULL;
  if (include_optional) {
    patch_firmware_service_config_body = patch_firmware_service_config_body_create(
      false,
      false,
      false,
      true,
      true,
      [{"device":{"product":"iPhone16,.*"},"include":true}]
    );
  } else {
    patch_firmware_service_config_body = patch_firmware_service_config_body_create(
      false,
      false,
      false,
      true,
      true,
      [{"device":{"product":"iPhone16,.*"},"include":true}]
    );
  }

  return patch_firmware_service_config_body;
}


#ifdef patch_firmware_service_config_body_MAIN

void test_patch_firmware_service_config_body(int include_optional) {
    patch_firmware_service_config_body_t* patch_firmware_service_config_body_1 = instantiate_patch_firmware_service_config_body(include_optional);

	cJSON* jsonpatch_firmware_service_config_body_1 = patch_firmware_service_config_body_convertToJSON(patch_firmware_service_config_body_1);
	printf("patch_firmware_service_config_body :\n%s\n", cJSON_Print(jsonpatch_firmware_service_config_body_1));
	patch_firmware_service_config_body_t* patch_firmware_service_config_body_2 = patch_firmware_service_config_body_parseFromJSON(jsonpatch_firmware_service_config_body_1);
	cJSON* jsonpatch_firmware_service_config_body_2 = patch_firmware_service_config_body_convertToJSON(patch_firmware_service_config_body_2);
	printf("repeating patch_firmware_service_config_body:\n%s\n", cJSON_Print(jsonpatch_firmware_service_config_body_2));
}

int main() {
  test_patch_firmware_service_config_body(1);
  test_patch_firmware_service_config_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_firmware_service_config_body_MAIN
#endif // patch_firmware_service_config_body_TEST
