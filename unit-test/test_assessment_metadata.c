#ifndef assessment_metadata_TEST
#define assessment_metadata_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_metadata_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_metadata.h"
assessment_metadata_t* instantiate_assessment_metadata(int include_optional);



assessment_metadata_t* instantiate_assessment_metadata(int include_optional) {
  assessment_metadata_t* assessment_metadata = NULL;
  if (include_optional) {
    assessment_metadata = assessment_metadata_create(
      "6.4.0"
    );
  } else {
    assessment_metadata = assessment_metadata_create(
      "6.4.0"
    );
  }

  return assessment_metadata;
}


#ifdef assessment_metadata_MAIN

void test_assessment_metadata(int include_optional) {
    assessment_metadata_t* assessment_metadata_1 = instantiate_assessment_metadata(include_optional);

	cJSON* jsonassessment_metadata_1 = assessment_metadata_convertToJSON(assessment_metadata_1);
	printf("assessment_metadata :\n%s\n", cJSON_Print(jsonassessment_metadata_1));
	assessment_metadata_t* assessment_metadata_2 = assessment_metadata_parseFromJSON(jsonassessment_metadata_1);
	cJSON* jsonassessment_metadata_2 = assessment_metadata_convertToJSON(assessment_metadata_2);
	printf("repeating assessment_metadata:\n%s\n", cJSON_Print(jsonassessment_metadata_2));
}

int main() {
  test_assessment_metadata(1);
  test_assessment_metadata(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_metadata_MAIN
#endif // assessment_metadata_TEST
