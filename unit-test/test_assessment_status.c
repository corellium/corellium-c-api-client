#ifndef assessment_status_TEST
#define assessment_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_status.h"
assessment_status_t* instantiate_assessment_status(int include_optional);



assessment_status_t* instantiate_assessment_status(int include_optional) {
  assessment_status_t* assessment_status = NULL;
  if (include_optional) {
    assessment_status = assessment_status_create(
    );
  } else {
    assessment_status = assessment_status_create(
    );
  }

  return assessment_status;
}


#ifdef assessment_status_MAIN

void test_assessment_status(int include_optional) {
    assessment_status_t* assessment_status_1 = instantiate_assessment_status(include_optional);

	cJSON* jsonassessment_status_1 = assessment_status_convertToJSON(assessment_status_1);
	printf("assessment_status :\n%s\n", cJSON_Print(jsonassessment_status_1));
	assessment_status_t* assessment_status_2 = assessment_status_parseFromJSON(jsonassessment_status_1);
	cJSON* jsonassessment_status_2 = assessment_status_convertToJSON(assessment_status_2);
	printf("repeating assessment_status:\n%s\n", cJSON_Print(jsonassessment_status_2));
}

int main() {
  test_assessment_status(1);
  test_assessment_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_status_MAIN
#endif // assessment_status_TEST
