#ifndef assessment_wordlist_TEST
#define assessment_wordlist_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define assessment_wordlist_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/assessment_wordlist.h"
assessment_wordlist_t* instantiate_assessment_wordlist(int include_optional);



assessment_wordlist_t* instantiate_assessment_wordlist(int include_optional) {
  assessment_wordlist_t* assessment_wordlist = NULL;
  if (include_optional) {
    assessment_wordlist = assessment_wordlist_create(
      "0",
      "0"
    );
  } else {
    assessment_wordlist = assessment_wordlist_create(
      "0",
      "0"
    );
  }

  return assessment_wordlist;
}


#ifdef assessment_wordlist_MAIN

void test_assessment_wordlist(int include_optional) {
    assessment_wordlist_t* assessment_wordlist_1 = instantiate_assessment_wordlist(include_optional);

	cJSON* jsonassessment_wordlist_1 = assessment_wordlist_convertToJSON(assessment_wordlist_1);
	printf("assessment_wordlist :\n%s\n", cJSON_Print(jsonassessment_wordlist_1));
	assessment_wordlist_t* assessment_wordlist_2 = assessment_wordlist_parseFromJSON(jsonassessment_wordlist_1);
	cJSON* jsonassessment_wordlist_2 = assessment_wordlist_convertToJSON(assessment_wordlist_2);
	printf("repeating assessment_wordlist:\n%s\n", cJSON_Print(jsonassessment_wordlist_2));
}

int main() {
  test_assessment_wordlist(1);
  test_assessment_wordlist(0);

  printf("Hello world \n");
  return 0;
}

#endif // assessment_wordlist_MAIN
#endif // assessment_wordlist_TEST
