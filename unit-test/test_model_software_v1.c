#ifndef model_software_v1_TEST
#define model_software_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_software_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_software_v1.h"
model_software_v1_t* instantiate_model_software_v1(int include_optional);



model_software_v1_t* instantiate_model_software_v1(int include_optional) {
  model_software_v1_t* model_software_v1 = NULL;
  if (include_optional) {
    model_software_v1 = model_software_v1_create(
      "0",
      "0",
      "0",
      1.337,
      1.337,
      list_createList()
    );
  } else {
    model_software_v1 = model_software_v1_create(
      "0",
      "0",
      "0",
      1.337,
      1.337,
      list_createList()
    );
  }

  return model_software_v1;
}


#ifdef model_software_v1_MAIN

void test_model_software_v1(int include_optional) {
    model_software_v1_t* model_software_v1_1 = instantiate_model_software_v1(include_optional);

	cJSON* jsonmodel_software_v1_1 = model_software_v1_convertToJSON(model_software_v1_1);
	printf("model_software_v1 :\n%s\n", cJSON_Print(jsonmodel_software_v1_1));
	model_software_v1_t* model_software_v1_2 = model_software_v1_parseFromJSON(jsonmodel_software_v1_1);
	cJSON* jsonmodel_software_v1_2 = model_software_v1_convertToJSON(model_software_v1_2);
	printf("repeating model_software_v1:\n%s\n", cJSON_Print(jsonmodel_software_v1_2));
}

int main() {
  test_model_software_v1(1);
  test_model_software_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_software_v1_MAIN
#endif // model_software_v1_TEST
