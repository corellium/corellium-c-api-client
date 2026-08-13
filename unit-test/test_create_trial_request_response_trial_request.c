#ifndef create_trial_request_response_trial_request_TEST
#define create_trial_request_response_trial_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_trial_request_response_trial_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_trial_request_response_trial_request.h"
create_trial_request_response_trial_request_t* instantiate_create_trial_request_response_trial_request(int include_optional);



create_trial_request_response_trial_request_t* instantiate_create_trial_request_response_trial_request(int include_optional) {
  create_trial_request_response_trial_request_t* create_trial_request_response_trial_request = NULL;
  if (include_optional) {
    create_trial_request_response_trial_request = create_trial_request_response_trial_request_create(
      "0",
      "0",
      "0"
    );
  } else {
    create_trial_request_response_trial_request = create_trial_request_response_trial_request_create(
      "0",
      "0",
      "0"
    );
  }

  return create_trial_request_response_trial_request;
}


#ifdef create_trial_request_response_trial_request_MAIN

void test_create_trial_request_response_trial_request(int include_optional) {
    create_trial_request_response_trial_request_t* create_trial_request_response_trial_request_1 = instantiate_create_trial_request_response_trial_request(include_optional);

	cJSON* jsoncreate_trial_request_response_trial_request_1 = create_trial_request_response_trial_request_convertToJSON(create_trial_request_response_trial_request_1);
	printf("create_trial_request_response_trial_request :\n%s\n", cJSON_Print(jsoncreate_trial_request_response_trial_request_1));
	create_trial_request_response_trial_request_t* create_trial_request_response_trial_request_2 = create_trial_request_response_trial_request_parseFromJSON(jsoncreate_trial_request_response_trial_request_1);
	cJSON* jsoncreate_trial_request_response_trial_request_2 = create_trial_request_response_trial_request_convertToJSON(create_trial_request_response_trial_request_2);
	printf("repeating create_trial_request_response_trial_request:\n%s\n", cJSON_Print(jsoncreate_trial_request_response_trial_request_2));
}

int main() {
  test_create_trial_request_response_trial_request(1);
  test_create_trial_request_response_trial_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_trial_request_response_trial_request_MAIN
#endif // create_trial_request_response_trial_request_TEST
