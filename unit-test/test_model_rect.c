#ifndef model_rect_TEST
#define model_rect_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_rect_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_rect.h"
model_rect_t* instantiate_model_rect(int include_optional);



model_rect_t* instantiate_model_rect(int include_optional) {
  model_rect_t* model_rect = NULL;
  if (include_optional) {
    model_rect = model_rect_create(
      10.29,
      12.04,
      275.91,
      599.12,
      0.12
    );
  } else {
    model_rect = model_rect_create(
      10.29,
      12.04,
      275.91,
      599.12,
      0.12
    );
  }

  return model_rect;
}


#ifdef model_rect_MAIN

void test_model_rect(int include_optional) {
    model_rect_t* model_rect_1 = instantiate_model_rect(include_optional);

	cJSON* jsonmodel_rect_1 = model_rect_convertToJSON(model_rect_1);
	printf("model_rect :\n%s\n", cJSON_Print(jsonmodel_rect_1));
	model_rect_t* model_rect_2 = model_rect_parseFromJSON(jsonmodel_rect_1);
	cJSON* jsonmodel_rect_2 = model_rect_convertToJSON(model_rect_2);
	printf("repeating model_rect:\n%s\n", cJSON_Print(jsonmodel_rect_2));
}

int main() {
  test_model_rect(1);
  test_model_rect(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_rect_MAIN
#endif // model_rect_TEST
