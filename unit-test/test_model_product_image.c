#ifndef model_product_image_TEST
#define model_product_image_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_product_image_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_product_image.h"
model_product_image_t* instantiate_model_product_image(int include_optional);

#include "test_model_product_image_inner.c"


model_product_image_t* instantiate_model_product_image(int include_optional) {
  model_product_image_t* model_product_image = NULL;
  if (include_optional) {
    model_product_image = model_product_image_create(
      80,
      null,
      true
    );
  } else {
    model_product_image = model_product_image_create(
      80,
      null,
      true
    );
  }

  return model_product_image;
}


#ifdef model_product_image_MAIN

void test_model_product_image(int include_optional) {
    model_product_image_t* model_product_image_1 = instantiate_model_product_image(include_optional);

	cJSON* jsonmodel_product_image_1 = model_product_image_convertToJSON(model_product_image_1);
	printf("model_product_image :\n%s\n", cJSON_Print(jsonmodel_product_image_1));
	model_product_image_t* model_product_image_2 = model_product_image_parseFromJSON(jsonmodel_product_image_1);
	cJSON* jsonmodel_product_image_2 = model_product_image_convertToJSON(model_product_image_2);
	printf("repeating model_product_image:\n%s\n", cJSON_Print(jsonmodel_product_image_2));
}

int main() {
  test_model_product_image(1);
  test_model_product_image(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_product_image_MAIN
#endif // model_product_image_TEST
