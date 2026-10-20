#ifndef domain_config_input_snapshot_sharing_permissions_TEST
#define domain_config_input_snapshot_sharing_permissions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_config_input_snapshot_sharing_permissions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_config_input_snapshot_sharing_permissions.h"
domain_config_input_snapshot_sharing_permissions_t* instantiate_domain_config_input_snapshot_sharing_permissions(int include_optional);



domain_config_input_snapshot_sharing_permissions_t* instantiate_domain_config_input_snapshot_sharing_permissions(int include_optional) {
  domain_config_input_snapshot_sharing_permissions_t* domain_config_input_snapshot_sharing_permissions = NULL;
  if (include_optional) {
    domain_config_input_snapshot_sharing_permissions = domain_config_input_snapshot_sharing_permissions_create(
      true,
      true,
      true,
      true,
      true
    );
  } else {
    domain_config_input_snapshot_sharing_permissions = domain_config_input_snapshot_sharing_permissions_create(
      true,
      true,
      true,
      true,
      true
    );
  }

  return domain_config_input_snapshot_sharing_permissions;
}


#ifdef domain_config_input_snapshot_sharing_permissions_MAIN

void test_domain_config_input_snapshot_sharing_permissions(int include_optional) {
    domain_config_input_snapshot_sharing_permissions_t* domain_config_input_snapshot_sharing_permissions_1 = instantiate_domain_config_input_snapshot_sharing_permissions(include_optional);

	cJSON* jsondomain_config_input_snapshot_sharing_permissions_1 = domain_config_input_snapshot_sharing_permissions_convertToJSON(domain_config_input_snapshot_sharing_permissions_1);
	printf("domain_config_input_snapshot_sharing_permissions :\n%s\n", cJSON_Print(jsondomain_config_input_snapshot_sharing_permissions_1));
	domain_config_input_snapshot_sharing_permissions_t* domain_config_input_snapshot_sharing_permissions_2 = domain_config_input_snapshot_sharing_permissions_parseFromJSON(jsondomain_config_input_snapshot_sharing_permissions_1);
	cJSON* jsondomain_config_input_snapshot_sharing_permissions_2 = domain_config_input_snapshot_sharing_permissions_convertToJSON(domain_config_input_snapshot_sharing_permissions_2);
	printf("repeating domain_config_input_snapshot_sharing_permissions:\n%s\n", cJSON_Print(jsondomain_config_input_snapshot_sharing_permissions_2));
}

int main() {
  test_domain_config_input_snapshot_sharing_permissions(1);
  test_domain_config_input_snapshot_sharing_permissions(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_config_input_snapshot_sharing_permissions_MAIN
#endif // domain_config_input_snapshot_sharing_permissions_TEST
