#ifndef model_firmware_TEST
#define model_firmware_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_firmware_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_firmware.h"
model_firmware_t* instantiate_model_firmware(int include_optional);

#include "test_model_firmware_springboard_snapshot.c"


model_firmware_t* instantiate_model_firmware(int include_optional) {
  model_firmware_t* model_firmware = NULL;
  if (include_optional) {
    model_firmware = model_firmware_create(
      "12.1.4",
      "16D57",
      "ranchu",
      "34",
      "bf613433f156e8f1ab9ad5a554d89734e66c0e5b8dd4cb2848c9e9673847cbe8",
      "1c93e6b5931378118b909da6f3e5f6dd2e19b114",
      "703a35f48f8e299cb90a2d13653589e2",
      "sha256$1048576$bf613433f156e8f1ab9ad5a554d89734e66c0e5b8dd4cb2848c9e9673847cbe8",
      true,
      3448156160,
      "acme-fw-0001",
      {"variants":["domain"]},
      "2026-05-22T13:58:34Z",
      "2026-05-22T13:58:34.000Z",
      "http://updates-http.cdn-apple.com/2019WinterFCS/fullrestores/041-39370/31D8C81A-292C-11E9-80C6-2A11412B0A59/iPhone_4.7_P3_12.1.4_16D57_Restore.ipsw",
      "http://updates-http.cdn-apple.com/2019WinterFCS/fullrestores/041-39370/31D8C81A-292C-11E9-80C6-2A11412B0A59/iPhone_4.7_P3_12.1.4_16D57_Restore.ipsw",
      "iPhone_4.7_P3_12.1.4_16D57_Restore.ipsw",
      false,
      true,
       // false, not to have infinite recursion
      instantiate_model_firmware_springboard_snapshot(0)
    );
  } else {
    model_firmware = model_firmware_create(
      "12.1.4",
      "16D57",
      "ranchu",
      "34",
      "bf613433f156e8f1ab9ad5a554d89734e66c0e5b8dd4cb2848c9e9673847cbe8",
      "1c93e6b5931378118b909da6f3e5f6dd2e19b114",
      "703a35f48f8e299cb90a2d13653589e2",
      "sha256$1048576$bf613433f156e8f1ab9ad5a554d89734e66c0e5b8dd4cb2848c9e9673847cbe8",
      true,
      3448156160,
      "acme-fw-0001",
      {"variants":["domain"]},
      "2026-05-22T13:58:34Z",
      "2026-05-22T13:58:34.000Z",
      "http://updates-http.cdn-apple.com/2019WinterFCS/fullrestores/041-39370/31D8C81A-292C-11E9-80C6-2A11412B0A59/iPhone_4.7_P3_12.1.4_16D57_Restore.ipsw",
      "http://updates-http.cdn-apple.com/2019WinterFCS/fullrestores/041-39370/31D8C81A-292C-11E9-80C6-2A11412B0A59/iPhone_4.7_P3_12.1.4_16D57_Restore.ipsw",
      "iPhone_4.7_P3_12.1.4_16D57_Restore.ipsw",
      false,
      true,
      NULL
    );
  }

  return model_firmware;
}


#ifdef model_firmware_MAIN

void test_model_firmware(int include_optional) {
    model_firmware_t* model_firmware_1 = instantiate_model_firmware(include_optional);

	cJSON* jsonmodel_firmware_1 = model_firmware_convertToJSON(model_firmware_1);
	printf("model_firmware :\n%s\n", cJSON_Print(jsonmodel_firmware_1));
	model_firmware_t* model_firmware_2 = model_firmware_parseFromJSON(jsonmodel_firmware_1);
	cJSON* jsonmodel_firmware_2 = model_firmware_convertToJSON(model_firmware_2);
	printf("repeating model_firmware:\n%s\n", cJSON_Print(jsonmodel_firmware_2));
}

int main() {
  test_model_firmware(1);
  test_model_firmware(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_firmware_MAIN
#endif // model_firmware_TEST
