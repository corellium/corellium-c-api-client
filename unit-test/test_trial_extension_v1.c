#ifndef trial_extension_v1_TEST
#define trial_extension_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trial_extension_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trial_extension_v1.h"
trial_extension_v1_t* instantiate_trial_extension_v1(int include_optional);



trial_extension_v1_t* instantiate_trial_extension_v1(int include_optional) {
  trial_extension_v1_t* trial_extension_v1 = NULL;
  if (include_optional) {
    trial_extension_v1 = trial_extension_v1_create(
      1.337,
      "0",
      1,
      "0"
    );
  } else {
    trial_extension_v1 = trial_extension_v1_create(
      1.337,
      "0",
      1,
      "0"
    );
  }

  return trial_extension_v1;
}


#ifdef trial_extension_v1_MAIN

void test_trial_extension_v1(int include_optional) {
    trial_extension_v1_t* trial_extension_v1_1 = instantiate_trial_extension_v1(include_optional);

	cJSON* jsontrial_extension_v1_1 = trial_extension_v1_convertToJSON(trial_extension_v1_1);
	printf("trial_extension_v1 :\n%s\n", cJSON_Print(jsontrial_extension_v1_1));
	trial_extension_v1_t* trial_extension_v1_2 = trial_extension_v1_parseFromJSON(jsontrial_extension_v1_1);
	cJSON* jsontrial_extension_v1_2 = trial_extension_v1_convertToJSON(trial_extension_v1_2);
	printf("repeating trial_extension_v1:\n%s\n", cJSON_Print(jsontrial_extension_v1_2));
}

int main() {
  test_trial_extension_v1(1);
  test_trial_extension_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // trial_extension_v1_MAIN
#endif // trial_extension_v1_TEST
