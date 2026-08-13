#ifndef assessment_results_TEST
#define assessment_results_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_results_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_results.h"
assessment_results_t* instantiate_assessment_results(int include_optional);



assessment_results_t* instantiate_assessment_results(int include_optional) {
  assessment_results_t* assessment_results = NULL;
  if (include_optional) {
    assessment_results = assessment_results_create(
      56,
      56,
      56,
      56,
      56,
      56,
      56
    );
  } else {
    assessment_results = assessment_results_create(
      56,
      56,
      56,
      56,
      56,
      56,
      56
    );
  }

  return assessment_results;
}


#ifdef assessment_results_MAIN

void test_assessment_results(int include_optional) {
    assessment_results_t* assessment_results_1 = instantiate_assessment_results(include_optional);

	cJSON* jsonassessment_results_1 = assessment_results_convertToJSON(assessment_results_1);
	printf("assessment_results :\n%s\n", cJSON_Print(jsonassessment_results_1));
	assessment_results_t* assessment_results_2 = assessment_results_parseFromJSON(jsonassessment_results_1);
	cJSON* jsonassessment_results_2 = assessment_results_convertToJSON(assessment_results_2);
	printf("repeating assessment_results:\n%s\n", cJSON_Print(jsonassessment_results_2));
}

int main() {
  test_assessment_results(1);
  test_assessment_results(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_results_MAIN
#endif // assessment_results_TEST
