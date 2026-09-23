#ifndef update_trial_request_body_TEST
#define update_trial_request_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_trial_request_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_trial_request_body.h"
update_trial_request_body_t* instantiate_update_trial_request_body(int include_optional);



update_trial_request_body_t* instantiate_update_trial_request_body(int include_optional) {
  update_trial_request_body_t* update_trial_request_body = NULL;
  if (include_optional) {
    update_trial_request_body = update_trial_request_body_create(
      14,
      24
    );
  } else {
    update_trial_request_body = update_trial_request_body_create(
      14,
      24
    );
  }

  return update_trial_request_body;
}


#ifdef update_trial_request_body_MAIN

void test_update_trial_request_body(int include_optional) {
    update_trial_request_body_t* update_trial_request_body_1 = instantiate_update_trial_request_body(include_optional);

	cJSON* jsonupdate_trial_request_body_1 = update_trial_request_body_convertToJSON(update_trial_request_body_1);
	printf("update_trial_request_body :\n%s\n", cJSON_Print(jsonupdate_trial_request_body_1));
	update_trial_request_body_t* update_trial_request_body_2 = update_trial_request_body_parseFromJSON(jsonupdate_trial_request_body_1);
	cJSON* jsonupdate_trial_request_body_2 = update_trial_request_body_convertToJSON(update_trial_request_body_2);
	printf("repeating update_trial_request_body:\n%s\n", cJSON_Print(jsonupdate_trial_request_body_2));
}

int main() {
  test_update_trial_request_body(1);
  test_update_trial_request_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_trial_request_body_MAIN
#endif // update_trial_request_body_TEST
