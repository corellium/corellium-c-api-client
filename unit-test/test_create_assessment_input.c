#ifndef create_assessment_input_TEST
#define create_assessment_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_assessment_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_assessment_input.h"
create_assessment_input_t* instantiate_create_assessment_input(int include_optional);



create_assessment_input_t* instantiate_create_assessment_input(int include_optional) {
  create_assessment_input_t* create_assessment_input = NULL;
  if (include_optional) {
    create_assessment_input = create_assessment_input_create(
      "0",
      "com.android.egg",
      "0",
      "0",
      "0"
    );
  } else {
    create_assessment_input = create_assessment_input_create(
      "0",
      "com.android.egg",
      "0",
      "0",
      "0"
    );
  }

  return create_assessment_input;
}


#ifdef create_assessment_input_MAIN

void test_create_assessment_input(int include_optional) {
    create_assessment_input_t* create_assessment_input_1 = instantiate_create_assessment_input(include_optional);

	cJSON* jsoncreate_assessment_input_1 = create_assessment_input_convertToJSON(create_assessment_input_1);
	printf("create_assessment_input :\n%s\n", cJSON_Print(jsoncreate_assessment_input_1));
	create_assessment_input_t* create_assessment_input_2 = create_assessment_input_parseFromJSON(jsoncreate_assessment_input_1);
	cJSON* jsoncreate_assessment_input_2 = create_assessment_input_convertToJSON(create_assessment_input_2);
	printf("repeating create_assessment_input:\n%s\n", cJSON_Print(jsoncreate_assessment_input_2));
}

int main() {
  test_create_assessment_input(1);
  test_create_assessment_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_assessment_input_MAIN
#endif // create_assessment_input_TEST
