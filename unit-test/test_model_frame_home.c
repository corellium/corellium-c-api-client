#ifndef model_frame_home_TEST
#define model_frame_home_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define model_frame_home_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/model_frame_home.h"
model_frame_home_t* instantiate_model_frame_home(int include_optional);



model_frame_home_t* instantiate_model_frame_home(int include_optional) {
  model_frame_home_t* model_frame_home = NULL;
  if (include_optional) {
    model_frame_home = model_frame_home_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    model_frame_home = model_frame_home_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return model_frame_home;
}


#ifdef model_frame_home_MAIN

void test_model_frame_home(int include_optional) {
    model_frame_home_t* model_frame_home_1 = instantiate_model_frame_home(include_optional);

	cJSON* jsonmodel_frame_home_1 = model_frame_home_convertToJSON(model_frame_home_1);
	printf("model_frame_home :\n%s\n", cJSON_Print(jsonmodel_frame_home_1));
	model_frame_home_t* model_frame_home_2 = model_frame_home_parseFromJSON(jsonmodel_frame_home_1);
	cJSON* jsonmodel_frame_home_2 = model_frame_home_convertToJSON(model_frame_home_2);
	printf("repeating model_frame_home:\n%s\n", cJSON_Print(jsonmodel_frame_home_2));
}

int main() {
  test_model_frame_home(1);
  test_model_frame_home(0);

  printf("Hello world \n");
  return 0;
}

#endif // model_frame_home_MAIN
#endif // model_frame_home_TEST
