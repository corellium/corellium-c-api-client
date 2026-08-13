#ifndef assessment_severity_counts_TEST
#define assessment_severity_counts_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_severity_counts_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_severity_counts.h"
assessment_severity_counts_t* instantiate_assessment_severity_counts(int include_optional);



assessment_severity_counts_t* instantiate_assessment_severity_counts(int include_optional) {
  assessment_severity_counts_t* assessment_severity_counts = NULL;
  if (include_optional) {
    assessment_severity_counts = assessment_severity_counts_create(
      56,
      56,
      56,
      56
    );
  } else {
    assessment_severity_counts = assessment_severity_counts_create(
      56,
      56,
      56,
      56
    );
  }

  return assessment_severity_counts;
}


#ifdef assessment_severity_counts_MAIN

void test_assessment_severity_counts(int include_optional) {
    assessment_severity_counts_t* assessment_severity_counts_1 = instantiate_assessment_severity_counts(include_optional);

	cJSON* jsonassessment_severity_counts_1 = assessment_severity_counts_convertToJSON(assessment_severity_counts_1);
	printf("assessment_severity_counts :\n%s\n", cJSON_Print(jsonassessment_severity_counts_1));
	assessment_severity_counts_t* assessment_severity_counts_2 = assessment_severity_counts_parseFromJSON(jsonassessment_severity_counts_1);
	cJSON* jsonassessment_severity_counts_2 = assessment_severity_counts_convertToJSON(assessment_severity_counts_2);
	printf("repeating assessment_severity_counts:\n%s\n", cJSON_Print(jsonassessment_severity_counts_2));
}

int main() {
  test_assessment_severity_counts(1);
  test_assessment_severity_counts(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_severity_counts_MAIN
#endif // assessment_severity_counts_TEST
