#ifndef model_frame_dimensions_TEST
#define model_frame_dimensions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_frame_dimensions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_frame_dimensions.h"
model_frame_dimensions_t* instantiate_model_frame_dimensions(int include_optional);



model_frame_dimensions_t* instantiate_model_frame_dimensions(int include_optional) {
  model_frame_dimensions_t* model_frame_dimensions = NULL;
  if (include_optional) {
    model_frame_dimensions = model_frame_dimensions_create(
      1260,
      2736
    );
  } else {
    model_frame_dimensions = model_frame_dimensions_create(
      1260,
      2736
    );
  }

  return model_frame_dimensions;
}


#ifdef model_frame_dimensions_MAIN

void test_model_frame_dimensions(int include_optional) {
    model_frame_dimensions_t* model_frame_dimensions_1 = instantiate_model_frame_dimensions(include_optional);

	cJSON* jsonmodel_frame_dimensions_1 = model_frame_dimensions_convertToJSON(model_frame_dimensions_1);
	printf("model_frame_dimensions :\n%s\n", cJSON_Print(jsonmodel_frame_dimensions_1));
	model_frame_dimensions_t* model_frame_dimensions_2 = model_frame_dimensions_parseFromJSON(jsonmodel_frame_dimensions_1);
	cJSON* jsonmodel_frame_dimensions_2 = model_frame_dimensions_convertToJSON(model_frame_dimensions_2);
	printf("repeating model_frame_dimensions:\n%s\n", cJSON_Print(jsonmodel_frame_dimensions_2));
}

int main() {
  test_model_frame_dimensions(1);
  test_model_frame_dimensions(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_frame_dimensions_MAIN
#endif // model_frame_dimensions_TEST
