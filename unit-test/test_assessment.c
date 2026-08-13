#ifndef assessment_TEST
#define assessment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment.h"
assessment_t* instantiate_assessment(int include_optional);

#include "test_assessment_bundle.c"
#include "test_assessment_wordlist.c"
#include "test_assessment_frida_script.c"
#include "test_assessment_results.c"
#include "test_assessment_metadata.c"
#include "test_assessment_severity_counts.c"


assessment_t* instantiate_assessment(int include_optional) {
  assessment_t* assessment = NULL;
  if (include_optional) {
    assessment = assessment_create(
      "0",
      corellium_api_assessment_STATUS_"complete",
      "0",
       // false, not to have infinite recursion
      instantiate_assessment_bundle(0),
       // false, not to have infinite recursion
      instantiate_assessment_wordlist(0),
       // false, not to have infinite recursion
      instantiate_assessment_frida_script(0),
      "0",
       // false, not to have infinite recursion
      instantiate_assessment_results(0),
       // false, not to have infinite recursion
      instantiate_assessment_metadata(0),
       // false, not to have infinite recursion
      instantiate_assessment_severity_counts(0),
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    assessment = assessment_create(
      "0",
      corellium_api_assessment_STATUS_"complete",
      "0",
      NULL,
      NULL,
      NULL,
      "0",
      NULL,
      NULL,
      NULL,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return assessment;
}


#ifdef assessment_MAIN

void test_assessment(int include_optional) {
    assessment_t* assessment_1 = instantiate_assessment(include_optional);

	cJSON* jsonassessment_1 = assessment_convertToJSON(assessment_1);
	printf("assessment :\n%s\n", cJSON_Print(jsonassessment_1));
	assessment_t* assessment_2 = assessment_parseFromJSON(jsonassessment_1);
	cJSON* jsonassessment_2 = assessment_convertToJSON(assessment_2);
	printf("repeating assessment:\n%s\n", cJSON_Print(jsonassessment_2));
}

int main() {
  test_assessment(1);
  test_assessment(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_MAIN
#endif // assessment_TEST
