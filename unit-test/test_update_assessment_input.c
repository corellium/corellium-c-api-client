#ifndef update_assessment_input_TEST
#define update_assessment_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_assessment_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_assessment_input.h"
update_assessment_input_t* instantiate_update_assessment_input(int include_optional);



update_assessment_input_t* instantiate_update_assessment_input(int include_optional) {
  update_assessment_input_t* update_assessment_input = NULL;
  if (include_optional) {
    update_assessment_input = update_assessment_input_create(
      corellium_api_update_assessment_input_STATUS_"testing"
    );
  } else {
    update_assessment_input = update_assessment_input_create(
      corellium_api_update_assessment_input_STATUS_"testing"
    );
  }

  return update_assessment_input;
}


#ifdef update_assessment_input_MAIN

void test_update_assessment_input(int include_optional) {
    update_assessment_input_t* update_assessment_input_1 = instantiate_update_assessment_input(include_optional);

	cJSON* jsonupdate_assessment_input_1 = update_assessment_input_convertToJSON(update_assessment_input_1);
	printf("update_assessment_input :\n%s\n", cJSON_Print(jsonupdate_assessment_input_1));
	update_assessment_input_t* update_assessment_input_2 = update_assessment_input_parseFromJSON(jsonupdate_assessment_input_1);
	cJSON* jsonupdate_assessment_input_2 = update_assessment_input_convertToJSON(update_assessment_input_2);
	printf("repeating update_assessment_input:\n%s\n", cJSON_Print(jsonupdate_assessment_input_2));
}

int main() {
  test_update_assessment_input(1);
  test_update_assessment_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_assessment_input_MAIN
#endif // update_assessment_input_TEST
