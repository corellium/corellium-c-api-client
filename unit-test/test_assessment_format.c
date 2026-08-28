#ifndef assessment_format_TEST
#define assessment_format_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_format_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_format.h"
assessment_format_t* instantiate_assessment_format(int include_optional);



assessment_format_t* instantiate_assessment_format(int include_optional) {
  assessment_format_t* assessment_format = NULL;
  if (include_optional) {
    assessment_format = assessment_format_create(
    );
  } else {
    assessment_format = assessment_format_create(
    );
  }

  return assessment_format;
}


#ifdef assessment_format_MAIN

void test_assessment_format(int include_optional) {
    assessment_format_t* assessment_format_1 = instantiate_assessment_format(include_optional);

	cJSON* jsonassessment_format_1 = assessment_format_convertToJSON(assessment_format_1);
	printf("assessment_format :\n%s\n", cJSON_Print(jsonassessment_format_1));
	assessment_format_t* assessment_format_2 = assessment_format_parseFromJSON(jsonassessment_format_1);
	cJSON* jsonassessment_format_2 = assessment_format_convertToJSON(assessment_format_2);
	printf("repeating assessment_format:\n%s\n", cJSON_Print(jsonassessment_format_2));
}

int main() {
  test_assessment_format(1);
  test_assessment_format(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_format_MAIN
#endif // assessment_format_TEST
