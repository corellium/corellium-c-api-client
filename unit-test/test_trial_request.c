#ifndef trial_request_TEST
#define trial_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trial_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trial_request.h"
trial_request_t* instantiate_trial_request(int include_optional);



trial_request_t* instantiate_trial_request(int include_optional) {
  trial_request_t* trial_request = NULL;
  if (include_optional) {
    trial_request = trial_request_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      0,
      1.337,
      1.337,
      "0"
    );
  } else {
    trial_request = trial_request_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      0,
      1.337,
      1.337,
      "0"
    );
  }

  return trial_request;
}


#ifdef trial_request_MAIN

void test_trial_request(int include_optional) {
    trial_request_t* trial_request_1 = instantiate_trial_request(include_optional);

	cJSON* jsontrial_request_1 = trial_request_convertToJSON(trial_request_1);
	printf("trial_request :\n%s\n", cJSON_Print(jsontrial_request_1));
	trial_request_t* trial_request_2 = trial_request_parseFromJSON(jsontrial_request_1);
	cJSON* jsontrial_request_2 = trial_request_convertToJSON(trial_request_2);
	printf("repeating trial_request:\n%s\n", cJSON_Print(jsontrial_request_2));
}

int main() {
  test_trial_request(1);
  test_trial_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // trial_request_MAIN
#endif // trial_request_TEST
