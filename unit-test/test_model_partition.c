#ifndef model_partition_TEST
#define model_partition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_partition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_partition.h"
model_partition_t* instantiate_model_partition(int include_optional);



model_partition_t* instantiate_model_partition(int include_optional) {
  model_partition_t* model_partition = NULL;
  if (include_optional) {
    model_partition = model_partition_create(
      "nand",
      4096,
      7812500,
      7812500,
      31250000,
      1024,
      [7812500,15625000,31250000],
      false
    );
  } else {
    model_partition = model_partition_create(
      "nand",
      4096,
      7812500,
      7812500,
      31250000,
      1024,
      [7812500,15625000,31250000],
      false
    );
  }

  return model_partition;
}


#ifdef model_partition_MAIN

void test_model_partition(int include_optional) {
    model_partition_t* model_partition_1 = instantiate_model_partition(include_optional);

	cJSON* jsonmodel_partition_1 = model_partition_convertToJSON(model_partition_1);
	printf("model_partition :\n%s\n", cJSON_Print(jsonmodel_partition_1));
	model_partition_t* model_partition_2 = model_partition_parseFromJSON(jsonmodel_partition_1);
	cJSON* jsonmodel_partition_2 = model_partition_convertToJSON(model_partition_2);
	printf("repeating model_partition:\n%s\n", cJSON_Print(jsonmodel_partition_2));
}

int main() {
  test_model_partition(1);
  test_model_partition(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_partition_MAIN
#endif // model_partition_TEST
