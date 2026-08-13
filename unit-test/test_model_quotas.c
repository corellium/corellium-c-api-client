#ifndef model_quotas_TEST
#define model_quotas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_quotas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_quotas.h"
model_quotas_t* instantiate_model_quotas(int include_optional);



model_quotas_t* instantiate_model_quotas(int include_optional) {
  model_quotas_t* model_quotas = NULL;
  if (include_optional) {
    model_quotas = model_quotas_create(
      1.337
    );
  } else {
    model_quotas = model_quotas_create(
      1.337
    );
  }

  return model_quotas;
}


#ifdef model_quotas_MAIN

void test_model_quotas(int include_optional) {
    model_quotas_t* model_quotas_1 = instantiate_model_quotas(include_optional);

	cJSON* jsonmodel_quotas_1 = model_quotas_convertToJSON(model_quotas_1);
	printf("model_quotas :\n%s\n", cJSON_Print(jsonmodel_quotas_1));
	model_quotas_t* model_quotas_2 = model_quotas_parseFromJSON(jsonmodel_quotas_1);
	cJSON* jsonmodel_quotas_2 = model_quotas_convertToJSON(model_quotas_2);
	printf("repeating model_quotas:\n%s\n", cJSON_Print(jsonmodel_quotas_2));
}

int main() {
  test_model_quotas(1);
  test_model_quotas(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_quotas_MAIN
#endif // model_quotas_TEST
