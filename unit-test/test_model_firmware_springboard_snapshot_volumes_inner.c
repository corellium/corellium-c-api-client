#ifndef model_firmware_springboard_snapshot_volumes_inner_TEST
#define model_firmware_springboard_snapshot_volumes_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_firmware_springboard_snapshot_volumes_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_firmware_springboard_snapshot_volumes_inner.h"
model_firmware_springboard_snapshot_volumes_inner_t* instantiate_model_firmware_springboard_snapshot_volumes_inner(int include_optional);



model_firmware_springboard_snapshot_volumes_inner_t* instantiate_model_firmware_springboard_snapshot_volumes_inner(int include_optional) {
  model_firmware_springboard_snapshot_volumes_inner_t* model_firmware_springboard_snapshot_volumes_inner = NULL;
  if (include_optional) {
    model_firmware_springboard_snapshot_volumes_inner = model_firmware_springboard_snapshot_volumes_inner_create(
      32000000000
    );
  } else {
    model_firmware_springboard_snapshot_volumes_inner = model_firmware_springboard_snapshot_volumes_inner_create(
      32000000000
    );
  }

  return model_firmware_springboard_snapshot_volumes_inner;
}


#ifdef model_firmware_springboard_snapshot_volumes_inner_MAIN

void test_model_firmware_springboard_snapshot_volumes_inner(int include_optional) {
    model_firmware_springboard_snapshot_volumes_inner_t* model_firmware_springboard_snapshot_volumes_inner_1 = instantiate_model_firmware_springboard_snapshot_volumes_inner(include_optional);

	cJSON* jsonmodel_firmware_springboard_snapshot_volumes_inner_1 = model_firmware_springboard_snapshot_volumes_inner_convertToJSON(model_firmware_springboard_snapshot_volumes_inner_1);
	printf("model_firmware_springboard_snapshot_volumes_inner :\n%s\n", cJSON_Print(jsonmodel_firmware_springboard_snapshot_volumes_inner_1));
	model_firmware_springboard_snapshot_volumes_inner_t* model_firmware_springboard_snapshot_volumes_inner_2 = model_firmware_springboard_snapshot_volumes_inner_parseFromJSON(jsonmodel_firmware_springboard_snapshot_volumes_inner_1);
	cJSON* jsonmodel_firmware_springboard_snapshot_volumes_inner_2 = model_firmware_springboard_snapshot_volumes_inner_convertToJSON(model_firmware_springboard_snapshot_volumes_inner_2);
	printf("repeating model_firmware_springboard_snapshot_volumes_inner:\n%s\n", cJSON_Print(jsonmodel_firmware_springboard_snapshot_volumes_inner_2));
}

int main() {
  test_model_firmware_springboard_snapshot_volumes_inner(1);
  test_model_firmware_springboard_snapshot_volumes_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_firmware_springboard_snapshot_volumes_inner_MAIN
#endif // model_firmware_springboard_snapshot_volumes_inner_TEST
