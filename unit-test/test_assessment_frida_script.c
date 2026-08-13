#ifndef assessment_frida_script_TEST
#define assessment_frida_script_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_frida_script_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_frida_script.h"
assessment_frida_script_t* instantiate_assessment_frida_script(int include_optional);



assessment_frida_script_t* instantiate_assessment_frida_script(int include_optional) {
  assessment_frida_script_t* assessment_frida_script = NULL;
  if (include_optional) {
    assessment_frida_script = assessment_frida_script_create(
      "0",
      "0"
    );
  } else {
    assessment_frida_script = assessment_frida_script_create(
      "0",
      "0"
    );
  }

  return assessment_frida_script;
}


#ifdef assessment_frida_script_MAIN

void test_assessment_frida_script(int include_optional) {
    assessment_frida_script_t* assessment_frida_script_1 = instantiate_assessment_frida_script(include_optional);

	cJSON* jsonassessment_frida_script_1 = assessment_frida_script_convertToJSON(assessment_frida_script_1);
	printf("assessment_frida_script :\n%s\n", cJSON_Print(jsonassessment_frida_script_1));
	assessment_frida_script_t* assessment_frida_script_2 = assessment_frida_script_parseFromJSON(jsonassessment_frida_script_1);
	cJSON* jsonassessment_frida_script_2 = assessment_frida_script_convertToJSON(assessment_frida_script_2);
	printf("repeating assessment_frida_script:\n%s\n", cJSON_Print(jsonassessment_frida_script_2));
}

int main() {
  test_assessment_frida_script(1);
  test_assessment_frida_script(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_frida_script_MAIN
#endif // assessment_frida_script_TEST
