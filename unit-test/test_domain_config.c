#ifndef domain_config_TEST
#define domain_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_config.h"
domain_config_t* instantiate_domain_config(int include_optional);

#include "test_domain_config_trial.c"
#include "test_domain_config_webplayer.c"
#include "test_domain_config_snapshot_sharing_permissions.c"


domain_config_t* instantiate_domain_config(int include_optional) {
  domain_config_t* domain_config = NULL;
  if (include_optional) {
    domain_config = domain_config_create(
      1,
      1,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_domain_config_trial(0),
      1,
      1,
      1,
      1,
      1,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_domain_config_webplayer(0),
       // false, not to have infinite recursion
      instantiate_domain_config_snapshot_sharing_permissions(0)
    );
  } else {
    domain_config = domain_config_create(
      1,
      1,
      "0",
      "0",
      NULL,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      NULL,
      NULL
    );
  }

  return domain_config;
}


#ifdef domain_config_MAIN

void test_domain_config(int include_optional) {
    domain_config_t* domain_config_1 = instantiate_domain_config(include_optional);

	cJSON* jsondomain_config_1 = domain_config_convertToJSON(domain_config_1);
	printf("domain_config :\n%s\n", cJSON_Print(jsondomain_config_1));
	domain_config_t* domain_config_2 = domain_config_parseFromJSON(jsondomain_config_1);
	cJSON* jsondomain_config_2 = domain_config_convertToJSON(domain_config_2);
	printf("repeating domain_config:\n%s\n", cJSON_Print(jsondomain_config_2));
}

int main() {
  test_domain_config(1);
  test_domain_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_config_MAIN
#endif // domain_config_TEST
