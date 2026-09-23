#ifndef domain_config_input_TEST
#define domain_config_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_config_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_config_input.h"
domain_config_input_t* instantiate_domain_config_input(int include_optional);

#include "test_domain_config_input_trial.c"
#include "test_domain_config_input_webplayer.c"
#include "test_domain_config_input_snapshot_sharing_permissions.c"


domain_config_input_t* instantiate_domain_config_input(int include_optional) {
  domain_config_input_t* domain_config_input = NULL;
  if (include_optional) {
    domain_config_input = domain_config_input_create(
      true,
      true,
      "Acme Corp",
      "enterprise",
      "jane.doe@example.com",
      "LAUNCH2026",
       // false, not to have infinite recursion
      instantiate_domain_config_input_trial(0),
      false,
      true,
      true,
      false,
      false,
      ["10.0.0.5:6666"],
      true,
      true,
      true,
      true,
       // false, not to have infinite recursion
      instantiate_domain_config_input_webplayer(0),
       // false, not to have infinite recursion
      instantiate_domain_config_input_snapshot_sharing_permissions(0)
    );
  } else {
    domain_config_input = domain_config_input_create(
      true,
      true,
      "Acme Corp",
      "enterprise",
      "jane.doe@example.com",
      "LAUNCH2026",
      NULL,
      false,
      true,
      true,
      false,
      false,
      ["10.0.0.5:6666"],
      true,
      true,
      true,
      true,
      NULL,
      NULL
    );
  }

  return domain_config_input;
}


#ifdef domain_config_input_MAIN

void test_domain_config_input(int include_optional) {
    domain_config_input_t* domain_config_input_1 = instantiate_domain_config_input(include_optional);

	cJSON* jsondomain_config_input_1 = domain_config_input_convertToJSON(domain_config_input_1);
	printf("domain_config_input :\n%s\n", cJSON_Print(jsondomain_config_input_1));
	domain_config_input_t* domain_config_input_2 = domain_config_input_parseFromJSON(jsondomain_config_input_1);
	cJSON* jsondomain_config_input_2 = domain_config_input_convertToJSON(domain_config_input_2);
	printf("repeating domain_config_input:\n%s\n", cJSON_Print(jsondomain_config_input_2));
}

int main() {
  test_domain_config_input(1);
  test_domain_config_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_config_input_MAIN
#endif // domain_config_input_TEST
