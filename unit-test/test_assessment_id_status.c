#ifndef assessment_id_status_TEST
#define assessment_id_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_id_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_id_status.h"
assessment_id_status_t* instantiate_assessment_id_status(int include_optional);



assessment_id_status_t* instantiate_assessment_id_status(int include_optional) {
  assessment_id_status_t* assessment_id_status = NULL;
  if (include_optional) {
    assessment_id_status = assessment_id_status_create(
      "0",
      corellium_api_assessment_id_status__"complete"
    );
  } else {
    assessment_id_status = assessment_id_status_create(
      "0",
      corellium_api_assessment_id_status__"complete"
    );
  }

  return assessment_id_status;
}


#ifdef assessment_id_status_MAIN

void test_assessment_id_status(int include_optional) {
    assessment_id_status_t* assessment_id_status_1 = instantiate_assessment_id_status(include_optional);

	cJSON* jsonassessment_id_status_1 = assessment_id_status_convertToJSON(assessment_id_status_1);
	printf("assessment_id_status :\n%s\n", cJSON_Print(jsonassessment_id_status_1));
	assessment_id_status_t* assessment_id_status_2 = assessment_id_status_parseFromJSON(jsonassessment_id_status_1);
	cJSON* jsonassessment_id_status_2 = assessment_id_status_convertToJSON(assessment_id_status_2);
	printf("repeating assessment_id_status:\n%s\n", cJSON_Print(jsonassessment_id_status_2));
}

int main() {
  test_assessment_id_status(1);
  test_assessment_id_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_id_status_MAIN
#endif // assessment_id_status_TEST
