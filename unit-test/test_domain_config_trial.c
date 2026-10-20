#ifndef domain_config_trial_TEST
#define domain_config_trial_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_config_trial_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_config_trial.h"
domain_config_trial_t* instantiate_domain_config_trial(int include_optional);

#include "test_domain_config_trial_end_action.c"
#include "test_domain_config_trial_subscribe_action.c"
#include "test_domain_config_trial_extension.c"


domain_config_trial_t* instantiate_domain_config_trial(int include_optional) {
  domain_config_trial_t* domain_config_trial = NULL;
  if (include_optional) {
    domain_config_trial = domain_config_trial_create(
      1773479567000,
      1799971200000,
       // false, not to have infinite recursion
      instantiate_domain_config_trial_end_action(0),
       // false, not to have infinite recursion
      instantiate_domain_config_trial_subscribe_action(0),
      null
    );
  } else {
    domain_config_trial = domain_config_trial_create(
      1773479567000,
      1799971200000,
      NULL,
      NULL,
      null
    );
  }

  return domain_config_trial;
}


#ifdef domain_config_trial_MAIN

void test_domain_config_trial(int include_optional) {
    domain_config_trial_t* domain_config_trial_1 = instantiate_domain_config_trial(include_optional);

	cJSON* jsondomain_config_trial_1 = domain_config_trial_convertToJSON(domain_config_trial_1);
	printf("domain_config_trial :\n%s\n", cJSON_Print(jsondomain_config_trial_1));
	domain_config_trial_t* domain_config_trial_2 = domain_config_trial_parseFromJSON(jsondomain_config_trial_1);
	cJSON* jsondomain_config_trial_2 = domain_config_trial_convertToJSON(domain_config_trial_2);
	printf("repeating domain_config_trial:\n%s\n", cJSON_Print(jsondomain_config_trial_2));
}

int main() {
  test_domain_config_trial(1);
  test_domain_config_trial(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_config_trial_MAIN
#endif // domain_config_trial_TEST
