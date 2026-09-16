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



model_firmware_t* instantiate_model_firmware(int include_optional) {
  model_firmware_t* model_firmware = NULL;
  if (include_optional) {
    model_firmware = model_firmware_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1.337,
      "0",
      0,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    model_firmware = model_firmware_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1.337,
      "0",
      0,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
      1
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
