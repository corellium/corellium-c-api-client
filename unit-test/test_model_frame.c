#ifndef model_frame_TEST
#define model_frame_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_frame_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_frame.h"
model_frame_t* instantiate_model_frame(int include_optional);

#include "test_model_rect.c"
#include "test_model_frame_home.c"
#include "test_model_frame_dimensions.c"


model_frame_t* instantiate_model_frame(int include_optional) {
  model_frame_t* model_frame = NULL;
  if (include_optional) {
    model_frame = model_frame_create(
      300,
      619.49,
       // false, not to have infinite recursion
      instantiate_model_rect(0),
      null,
       // false, not to have infinite recursion
      instantiate_model_frame_dimensions(0),
      3,
      true
    );
  } else {
    model_frame = model_frame_create(
      300,
      619.49,
      NULL,
      null,
      NULL,
      3,
      true
    );
  }

  return model_frame;
}


#ifdef model_frame_MAIN

void test_model_frame(int include_optional) {
    model_frame_t* model_frame_1 = instantiate_model_frame(include_optional);

	cJSON* jsonmodel_frame_1 = model_frame_convertToJSON(model_frame_1);
	printf("model_frame :\n%s\n", cJSON_Print(jsonmodel_frame_1));
	model_frame_t* model_frame_2 = model_frame_parseFromJSON(jsonmodel_frame_1);
	cJSON* jsonmodel_frame_2 = model_frame_convertToJSON(model_frame_2);
	printf("repeating model_frame:\n%s\n", cJSON_Print(jsonmodel_frame_2));
}

int main() {
  test_model_frame(1);
  test_model_frame(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_frame_MAIN
#endif // model_frame_TEST
