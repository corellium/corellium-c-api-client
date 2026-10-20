#ifndef assessment_history_line_item_TEST
#define assessment_history_line_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_history_line_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_history_line_item.h"
assessment_history_line_item_t* instantiate_assessment_history_line_item(int include_optional);



assessment_history_line_item_t* instantiate_assessment_history_line_item(int include_optional) {
  assessment_history_line_item_t* assessment_history_line_item = NULL;
  if (include_optional) {
    assessment_history_line_item = assessment_history_line_item_create(
      1.337,
      1.337,
      1.337
    );
  } else {
    assessment_history_line_item = assessment_history_line_item_create(
      1.337,
      1.337,
      1.337
    );
  }

  return assessment_history_line_item;
}


#ifdef assessment_history_line_item_MAIN

void test_assessment_history_line_item(int include_optional) {
    assessment_history_line_item_t* assessment_history_line_item_1 = instantiate_assessment_history_line_item(include_optional);

	cJSON* jsonassessment_history_line_item_1 = assessment_history_line_item_convertToJSON(assessment_history_line_item_1);
	printf("assessment_history_line_item :\n%s\n", cJSON_Print(jsonassessment_history_line_item_1));
	assessment_history_line_item_t* assessment_history_line_item_2 = assessment_history_line_item_parseFromJSON(jsonassessment_history_line_item_1);
	cJSON* jsonassessment_history_line_item_2 = assessment_history_line_item_convertToJSON(assessment_history_line_item_2);
	printf("repeating assessment_history_line_item:\n%s\n", cJSON_Print(jsonassessment_history_line_item_2));
}

int main() {
  test_assessment_history_line_item(1);
  test_assessment_history_line_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_history_line_item_MAIN
#endif // assessment_history_line_item_TEST
