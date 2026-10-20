#ifndef assessment_bundle_TEST
#define assessment_bundle_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_bundle_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_bundle.h"
assessment_bundle_t* instantiate_assessment_bundle(int include_optional);



assessment_bundle_t* instantiate_assessment_bundle(int include_optional) {
  assessment_bundle_t* assessment_bundle = NULL;
  if (include_optional) {
    assessment_bundle = assessment_bundle_create(
      "0",
      "Camera",
      "1.2.0"
    );
  } else {
    assessment_bundle = assessment_bundle_create(
      "0",
      "Camera",
      "1.2.0"
    );
  }

  return assessment_bundle;
}


#ifdef assessment_bundle_MAIN

void test_assessment_bundle(int include_optional) {
    assessment_bundle_t* assessment_bundle_1 = instantiate_assessment_bundle(include_optional);

	cJSON* jsonassessment_bundle_1 = assessment_bundle_convertToJSON(assessment_bundle_1);
	printf("assessment_bundle :\n%s\n", cJSON_Print(jsonassessment_bundle_1));
	assessment_bundle_t* assessment_bundle_2 = assessment_bundle_parseFromJSON(jsonassessment_bundle_1);
	cJSON* jsonassessment_bundle_2 = assessment_bundle_convertToJSON(assessment_bundle_2);
	printf("repeating assessment_bundle:\n%s\n", cJSON_Print(jsonassessment_bundle_2));
}

int main() {
  test_assessment_bundle(1);
  test_assessment_bundle(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_bundle_MAIN
#endif // assessment_bundle_TEST
