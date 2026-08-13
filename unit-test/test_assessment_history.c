#ifndef assessment_history_TEST
#define assessment_history_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_history_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_history.h"
assessment_history_t* instantiate_assessment_history(int include_optional);



assessment_history_t* instantiate_assessment_history(int include_optional) {
  assessment_history_t* assessment_history = NULL;
  if (include_optional) {
    assessment_history = assessment_history_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    assessment_history = assessment_history_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return assessment_history;
}


#ifdef assessment_history_MAIN

void test_assessment_history(int include_optional) {
    assessment_history_t* assessment_history_1 = instantiate_assessment_history(include_optional);

	cJSON* jsonassessment_history_1 = assessment_history_convertToJSON(assessment_history_1);
	printf("assessment_history :\n%s\n", cJSON_Print(jsonassessment_history_1));
	assessment_history_t* assessment_history_2 = assessment_history_parseFromJSON(jsonassessment_history_1);
	cJSON* jsonassessment_history_2 = assessment_history_convertToJSON(assessment_history_2);
	printf("repeating assessment_history:\n%s\n", cJSON_Print(jsonassessment_history_2));
}

int main() {
  test_assessment_history(1);
  test_assessment_history(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_history_MAIN
#endif // assessment_history_TEST
