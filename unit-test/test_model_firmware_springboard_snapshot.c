#ifndef model_firmware_springboard_snapshot_TEST
#define model_firmware_springboard_snapshot_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_firmware_springboard_snapshot_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_firmware_springboard_snapshot.h"
model_firmware_springboard_snapshot_t* instantiate_model_firmware_springboard_snapshot(int include_optional);



model_firmware_springboard_snapshot_t* instantiate_model_firmware_springboard_snapshot(int include_optional) {
  model_firmware_springboard_snapshot_t* model_firmware_springboard_snapshot = NULL;
  if (include_optional) {
    model_firmware_springboard_snapshot = model_firmware_springboard_snapshot_create(
      list_createList()
    );
  } else {
    model_firmware_springboard_snapshot = model_firmware_springboard_snapshot_create(
      list_createList()
    );
  }

  return model_firmware_springboard_snapshot;
}


#ifdef model_firmware_springboard_snapshot_MAIN

void test_model_firmware_springboard_snapshot(int include_optional) {
    model_firmware_springboard_snapshot_t* model_firmware_springboard_snapshot_1 = instantiate_model_firmware_springboard_snapshot(include_optional);

	cJSON* jsonmodel_firmware_springboard_snapshot_1 = model_firmware_springboard_snapshot_convertToJSON(model_firmware_springboard_snapshot_1);
	printf("model_firmware_springboard_snapshot :\n%s\n", cJSON_Print(jsonmodel_firmware_springboard_snapshot_1));
	model_firmware_springboard_snapshot_t* model_firmware_springboard_snapshot_2 = model_firmware_springboard_snapshot_parseFromJSON(jsonmodel_firmware_springboard_snapshot_1);
	cJSON* jsonmodel_firmware_springboard_snapshot_2 = model_firmware_springboard_snapshot_convertToJSON(model_firmware_springboard_snapshot_2);
	printf("repeating model_firmware_springboard_snapshot:\n%s\n", cJSON_Print(jsonmodel_firmware_springboard_snapshot_2));
}

int main() {
  test_model_firmware_springboard_snapshot(1);
  test_model_firmware_springboard_snapshot(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_firmware_springboard_snapshot_MAIN
#endif // model_firmware_springboard_snapshot_TEST
