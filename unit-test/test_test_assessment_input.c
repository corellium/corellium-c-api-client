#ifndef test_assessment_input_TEST
#define test_assessment_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define test_assessment_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/test_assessment_input.h"
test_assessment_input_t* instantiate_test_assessment_input(int include_optional);



test_assessment_input_t* instantiate_test_assessment_input(int include_optional) {
  test_assessment_input_t* test_assessment_input = NULL;
  if (include_optional) {
    test_assessment_input = test_assessment_input_create(
      1,
      "masvs-storage-2-android-8"
    );
  } else {
    test_assessment_input = test_assessment_input_create(
      1,
      "masvs-storage-2-android-8"
    );
  }

  return test_assessment_input;
}


#ifdef test_assessment_input_MAIN

void test_test_assessment_input(int include_optional) {
    test_assessment_input_t* test_assessment_input_1 = instantiate_test_assessment_input(include_optional);

	cJSON* jsontest_assessment_input_1 = test_assessment_input_convertToJSON(test_assessment_input_1);
	printf("test_assessment_input :\n%s\n", cJSON_Print(jsontest_assessment_input_1));
	test_assessment_input_t* test_assessment_input_2 = test_assessment_input_parseFromJSON(jsontest_assessment_input_1);
	cJSON* jsontest_assessment_input_2 = test_assessment_input_convertToJSON(test_assessment_input_2);
	printf("repeating test_assessment_input:\n%s\n", cJSON_Print(jsontest_assessment_input_2));
}

int main() {
  test_test_assessment_input(1);
  test_test_assessment_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // test_assessment_input_MAIN
#endif // test_assessment_input_TEST
