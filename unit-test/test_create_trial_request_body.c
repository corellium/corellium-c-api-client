#ifndef create_trial_request_body_TEST
#define create_trial_request_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_trial_request_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_trial_request_body.h"
create_trial_request_body_t* instantiate_create_trial_request_body(int include_optional);



create_trial_request_body_t* instantiate_create_trial_request_body(int include_optional) {
  create_trial_request_body_t* create_trial_request_body = NULL;
  if (include_optional) {
    create_trial_request_body = create_trial_request_body_create(
      "0",
      "0",
      "0",
      "0",
      corellium_api_create_trial_request_body_TYPE_individual,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    create_trial_request_body = create_trial_request_body_create(
      "0",
      "0",
      "0",
      "0",
      corellium_api_create_trial_request_body_TYPE_individual,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return create_trial_request_body;
}


#ifdef create_trial_request_body_MAIN

void test_create_trial_request_body(int include_optional) {
    create_trial_request_body_t* create_trial_request_body_1 = instantiate_create_trial_request_body(include_optional);

	cJSON* jsoncreate_trial_request_body_1 = create_trial_request_body_convertToJSON(create_trial_request_body_1);
	printf("create_trial_request_body :\n%s\n", cJSON_Print(jsoncreate_trial_request_body_1));
	create_trial_request_body_t* create_trial_request_body_2 = create_trial_request_body_parseFromJSON(jsoncreate_trial_request_body_1);
	cJSON* jsoncreate_trial_request_body_2 = create_trial_request_body_convertToJSON(create_trial_request_body_2);
	printf("repeating create_trial_request_body:\n%s\n", cJSON_Print(jsoncreate_trial_request_body_2));
}

int main() {
  test_create_trial_request_body(1);
  test_create_trial_request_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_trial_request_body_MAIN
#endif // create_trial_request_body_TEST
