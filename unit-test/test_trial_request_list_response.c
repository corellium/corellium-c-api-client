#ifndef trial_request_list_response_TEST
#define trial_request_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trial_request_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trial_request_list_response.h"
trial_request_list_response_t* instantiate_trial_request_list_response(int include_optional);



trial_request_list_response_t* instantiate_trial_request_list_response(int include_optional) {
  trial_request_list_response_t* trial_request_list_response = NULL;
  if (include_optional) {
    trial_request_list_response = trial_request_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    trial_request_list_response = trial_request_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return trial_request_list_response;
}


#ifdef trial_request_list_response_MAIN

void test_trial_request_list_response(int include_optional) {
    trial_request_list_response_t* trial_request_list_response_1 = instantiate_trial_request_list_response(include_optional);

	cJSON* jsontrial_request_list_response_1 = trial_request_list_response_convertToJSON(trial_request_list_response_1);
	printf("trial_request_list_response :\n%s\n", cJSON_Print(jsontrial_request_list_response_1));
	trial_request_list_response_t* trial_request_list_response_2 = trial_request_list_response_parseFromJSON(jsontrial_request_list_response_1);
	cJSON* jsontrial_request_list_response_2 = trial_request_list_response_convertToJSON(trial_request_list_response_2);
	printf("repeating trial_request_list_response:\n%s\n", cJSON_Print(jsontrial_request_list_response_2));
}

int main() {
  test_trial_request_list_response(1);
  test_trial_request_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // trial_request_list_response_MAIN
#endif // trial_request_list_response_TEST
