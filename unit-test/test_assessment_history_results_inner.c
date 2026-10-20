#ifndef assessment_history_results_inner_TEST
#define assessment_history_results_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_history_results_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_history_results_inner.h"
assessment_history_results_inner_t* instantiate_assessment_history_results_inner(int include_optional);



assessment_history_results_inner_t* instantiate_assessment_history_results_inner(int include_optional) {
  assessment_history_results_inner_t* assessment_history_results_inner = NULL;
  if (include_optional) {
    assessment_history_results_inner = assessment_history_results_inner_create(
      "Jul 2025",
      15,
      3
    );
  } else {
    assessment_history_results_inner = assessment_history_results_inner_create(
      "Jul 2025",
      15,
      3
    );
  }

  return assessment_history_results_inner;
}


#ifdef assessment_history_results_inner_MAIN

void test_assessment_history_results_inner(int include_optional) {
    assessment_history_results_inner_t* assessment_history_results_inner_1 = instantiate_assessment_history_results_inner(include_optional);

	cJSON* jsonassessment_history_results_inner_1 = assessment_history_results_inner_convertToJSON(assessment_history_results_inner_1);
	printf("assessment_history_results_inner :\n%s\n", cJSON_Print(jsonassessment_history_results_inner_1));
	assessment_history_results_inner_t* assessment_history_results_inner_2 = assessment_history_results_inner_parseFromJSON(jsonassessment_history_results_inner_1);
	cJSON* jsonassessment_history_results_inner_2 = assessment_history_results_inner_convertToJSON(assessment_history_results_inner_2);
	printf("repeating assessment_history_results_inner:\n%s\n", cJSON_Print(jsonassessment_history_results_inner_2));
}

int main() {
  test_assessment_history_results_inner(1);
  test_assessment_history_results_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_history_results_inner_MAIN
#endif // assessment_history_results_inner_TEST
