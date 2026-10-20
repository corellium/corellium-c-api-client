#ifndef assessment_history_v1_TEST
#define assessment_history_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_history_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_history_v1.h"
assessment_history_v1_t* instantiate_assessment_history_v1(int include_optional);



assessment_history_v1_t* instantiate_assessment_history_v1(int include_optional) {
  assessment_history_v1_t* assessment_history_v1 = NULL;
  if (include_optional) {
    assessment_history_v1 = assessment_history_v1_create(
      1.337,
      1.337,
      1.337,
      1.337,
      list_createList()
    );
  } else {
    assessment_history_v1 = assessment_history_v1_create(
      1.337,
      1.337,
      1.337,
      1.337,
      list_createList()
    );
  }

  return assessment_history_v1;
}


#ifdef assessment_history_v1_MAIN

void test_assessment_history_v1(int include_optional) {
    assessment_history_v1_t* assessment_history_v1_1 = instantiate_assessment_history_v1(include_optional);

	cJSON* jsonassessment_history_v1_1 = assessment_history_v1_convertToJSON(assessment_history_v1_1);
	printf("assessment_history_v1 :\n%s\n", cJSON_Print(jsonassessment_history_v1_1));
	assessment_history_v1_t* assessment_history_v1_2 = assessment_history_v1_parseFromJSON(jsonassessment_history_v1_1);
	cJSON* jsonassessment_history_v1_2 = assessment_history_v1_convertToJSON(assessment_history_v1_2);
	printf("repeating assessment_history_v1:\n%s\n", cJSON_Print(jsonassessment_history_v1_2));
}

int main() {
  test_assessment_history_v1(1);
  test_assessment_history_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_history_v1_MAIN
#endif // assessment_history_v1_TEST
