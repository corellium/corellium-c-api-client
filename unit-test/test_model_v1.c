#ifndef model_v1_TEST
#define model_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_v1.h"
model_v1_t* instantiate_model_v1(int include_optional);



model_v1_t* instantiate_model_v1(int include_optional) {
  model_v1_t* model_v1 = NULL;
  if (include_optional) {
    model_v1 = model_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      1
    );
  } else {
    model_v1 = model_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      1
    );
  }

  return model_v1;
}


#ifdef model_v1_MAIN

void test_model_v1(int include_optional) {
    model_v1_t* model_v1_1 = instantiate_model_v1(include_optional);

	cJSON* jsonmodel_v1_1 = model_v1_convertToJSON(model_v1_1);
	printf("model_v1 :\n%s\n", cJSON_Print(jsonmodel_v1_1));
	model_v1_t* model_v1_2 = model_v1_parseFromJSON(jsonmodel_v1_1);
	cJSON* jsonmodel_v1_2 = model_v1_convertToJSON(model_v1_2);
	printf("repeating model_v1:\n%s\n", cJSON_Print(jsonmodel_v1_2));
}

int main() {
  test_model_v1(1);
  test_model_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_v1_MAIN
#endif // model_v1_TEST
