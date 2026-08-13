#ifndef update_trial_request_params_TEST
#define update_trial_request_params_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_trial_request_params_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_trial_request_params.h"
update_trial_request_params_t* instantiate_update_trial_request_params(int include_optional);



update_trial_request_params_t* instantiate_update_trial_request_params(int include_optional) {
  update_trial_request_params_t* update_trial_request_params = NULL;
  if (include_optional) {
    update_trial_request_params = update_trial_request_params_create(
      1.337,
      1.337
    );
  } else {
    update_trial_request_params = update_trial_request_params_create(
      1.337,
      1.337
    );
  }

  return update_trial_request_params;
}


#ifdef update_trial_request_params_MAIN

void test_update_trial_request_params(int include_optional) {
    update_trial_request_params_t* update_trial_request_params_1 = instantiate_update_trial_request_params(include_optional);

	cJSON* jsonupdate_trial_request_params_1 = update_trial_request_params_convertToJSON(update_trial_request_params_1);
	printf("update_trial_request_params :\n%s\n", cJSON_Print(jsonupdate_trial_request_params_1));
	update_trial_request_params_t* update_trial_request_params_2 = update_trial_request_params_parseFromJSON(jsonupdate_trial_request_params_1);
	cJSON* jsonupdate_trial_request_params_2 = update_trial_request_params_convertToJSON(update_trial_request_params_2);
	printf("repeating update_trial_request_params:\n%s\n", cJSON_Print(jsonupdate_trial_request_params_2));
}

int main() {
  test_update_trial_request_params(1);
  test_update_trial_request_params(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_trial_request_params_MAIN
#endif // update_trial_request_params_TEST
