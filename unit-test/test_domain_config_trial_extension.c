#ifndef domain_config_trial_extension_TEST
#define domain_config_trial_extension_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_config_trial_extension_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_config_trial_extension.h"
domain_config_trial_extension_t* instantiate_domain_config_trial_extension(int include_optional);



domain_config_trial_extension_t* instantiate_domain_config_trial_extension(int include_optional) {
  domain_config_trial_extension_t* domain_config_trial_extension = NULL;
  if (include_optional) {
    domain_config_trial_extension = domain_config_trial_extension_create(
      7,
      "Need more time to evaluate the platform.",
      true,
      "Trial already extended twice."
    );
  } else {
    domain_config_trial_extension = domain_config_trial_extension_create(
      7,
      "Need more time to evaluate the platform.",
      true,
      "Trial already extended twice."
    );
  }

  return domain_config_trial_extension;
}


#ifdef domain_config_trial_extension_MAIN

void test_domain_config_trial_extension(int include_optional) {
    domain_config_trial_extension_t* domain_config_trial_extension_1 = instantiate_domain_config_trial_extension(include_optional);

	cJSON* jsondomain_config_trial_extension_1 = domain_config_trial_extension_convertToJSON(domain_config_trial_extension_1);
	printf("domain_config_trial_extension :\n%s\n", cJSON_Print(jsondomain_config_trial_extension_1));
	domain_config_trial_extension_t* domain_config_trial_extension_2 = domain_config_trial_extension_parseFromJSON(jsondomain_config_trial_extension_1);
	cJSON* jsondomain_config_trial_extension_2 = domain_config_trial_extension_convertToJSON(domain_config_trial_extension_2);
	printf("repeating domain_config_trial_extension:\n%s\n", cJSON_Print(jsondomain_config_trial_extension_2));
}

int main() {
  test_domain_config_trial_extension(1);
  test_domain_config_trial_extension(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_config_trial_extension_MAIN
#endif // domain_config_trial_extension_TEST
