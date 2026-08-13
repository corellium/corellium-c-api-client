#ifndef domain_config_trial_subscribe_action_TEST
#define domain_config_trial_subscribe_action_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_config_trial_subscribe_action_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_config_trial_subscribe_action.h"
domain_config_trial_subscribe_action_t* instantiate_domain_config_trial_subscribe_action(int include_optional);



domain_config_trial_subscribe_action_t* instantiate_domain_config_trial_subscribe_action(int include_optional) {
  domain_config_trial_subscribe_action_t* domain_config_trial_subscribe_action = NULL;
  if (include_optional) {
    domain_config_trial_subscribe_action = domain_config_trial_subscribe_action_create(
      "0"
    );
  } else {
    domain_config_trial_subscribe_action = domain_config_trial_subscribe_action_create(
      "0"
    );
  }

  return domain_config_trial_subscribe_action;
}


#ifdef domain_config_trial_subscribe_action_MAIN

void test_domain_config_trial_subscribe_action(int include_optional) {
    domain_config_trial_subscribe_action_t* domain_config_trial_subscribe_action_1 = instantiate_domain_config_trial_subscribe_action(include_optional);

	cJSON* jsondomain_config_trial_subscribe_action_1 = domain_config_trial_subscribe_action_convertToJSON(domain_config_trial_subscribe_action_1);
	printf("domain_config_trial_subscribe_action :\n%s\n", cJSON_Print(jsondomain_config_trial_subscribe_action_1));
	domain_config_trial_subscribe_action_t* domain_config_trial_subscribe_action_2 = domain_config_trial_subscribe_action_parseFromJSON(jsondomain_config_trial_subscribe_action_1);
	cJSON* jsondomain_config_trial_subscribe_action_2 = domain_config_trial_subscribe_action_convertToJSON(domain_config_trial_subscribe_action_2);
	printf("repeating domain_config_trial_subscribe_action:\n%s\n", cJSON_Print(jsondomain_config_trial_subscribe_action_2));
}

int main() {
  test_domain_config_trial_subscribe_action(1);
  test_domain_config_trial_subscribe_action(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_config_trial_subscribe_action_MAIN
#endif // domain_config_trial_subscribe_action_TEST
