#ifndef model_product_image_inner_TEST
#define model_product_image_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_product_image_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_product_image_inner.h"
model_product_image_inner_t* instantiate_model_product_image_inner(int include_optional);



model_product_image_inner_t* instantiate_model_product_image_inner(int include_optional) {
  model_product_image_inner_t* model_product_image_inner = NULL;
  if (include_optional) {
    model_product_image_inner = model_product_image_inner_create(
      10.29,
      12.04,
      275.91,
      599.12,
      0.12
    );
  } else {
    model_product_image_inner = model_product_image_inner_create(
      10.29,
      12.04,
      275.91,
      599.12,
      0.12
    );
  }

  return model_product_image_inner;
}


#ifdef model_product_image_inner_MAIN

void test_model_product_image_inner(int include_optional) {
    model_product_image_inner_t* model_product_image_inner_1 = instantiate_model_product_image_inner(include_optional);

	cJSON* jsonmodel_product_image_inner_1 = model_product_image_inner_convertToJSON(model_product_image_inner_1);
	printf("model_product_image_inner :\n%s\n", cJSON_Print(jsonmodel_product_image_inner_1));
	model_product_image_inner_t* model_product_image_inner_2 = model_product_image_inner_parseFromJSON(jsonmodel_product_image_inner_1);
	cJSON* jsonmodel_product_image_inner_2 = model_product_image_inner_convertToJSON(model_product_image_inner_2);
	printf("repeating model_product_image_inner:\n%s\n", cJSON_Print(jsonmodel_product_image_inner_2));
}

int main() {
  test_model_product_image_inner(1);
  test_model_product_image_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_product_image_inner_MAIN
#endif // model_product_image_inner_TEST
