#ifndef update_domain_settings_response_snapshot_sharing_permissions_TEST
#define update_domain_settings_response_snapshot_sharing_permissions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_domain_settings_response_snapshot_sharing_permissions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_domain_settings_response_snapshot_sharing_permissions.h"
update_domain_settings_response_snapshot_sharing_permissions_t* instantiate_update_domain_settings_response_snapshot_sharing_permissions(int include_optional);



update_domain_settings_response_snapshot_sharing_permissions_t* instantiate_update_domain_settings_response_snapshot_sharing_permissions(int include_optional) {
  update_domain_settings_response_snapshot_sharing_permissions_t* update_domain_settings_response_snapshot_sharing_permissions = NULL;
  if (include_optional) {
    update_domain_settings_response_snapshot_sharing_permissions = update_domain_settings_response_snapshot_sharing_permissions_create(
      true,
      true,
      true,
      true,
      true,
      true
    );
  } else {
    update_domain_settings_response_snapshot_sharing_permissions = update_domain_settings_response_snapshot_sharing_permissions_create(
      true,
      true,
      true,
      true,
      true,
      true
    );
  }

  return update_domain_settings_response_snapshot_sharing_permissions;
}


#ifdef update_domain_settings_response_snapshot_sharing_permissions_MAIN

void test_update_domain_settings_response_snapshot_sharing_permissions(int include_optional) {
    update_domain_settings_response_snapshot_sharing_permissions_t* update_domain_settings_response_snapshot_sharing_permissions_1 = instantiate_update_domain_settings_response_snapshot_sharing_permissions(include_optional);

	cJSON* jsonupdate_domain_settings_response_snapshot_sharing_permissions_1 = update_domain_settings_response_snapshot_sharing_permissions_convertToJSON(update_domain_settings_response_snapshot_sharing_permissions_1);
	printf("update_domain_settings_response_snapshot_sharing_permissions :\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_snapshot_sharing_permissions_1));
	update_domain_settings_response_snapshot_sharing_permissions_t* update_domain_settings_response_snapshot_sharing_permissions_2 = update_domain_settings_response_snapshot_sharing_permissions_parseFromJSON(jsonupdate_domain_settings_response_snapshot_sharing_permissions_1);
	cJSON* jsonupdate_domain_settings_response_snapshot_sharing_permissions_2 = update_domain_settings_response_snapshot_sharing_permissions_convertToJSON(update_domain_settings_response_snapshot_sharing_permissions_2);
	printf("repeating update_domain_settings_response_snapshot_sharing_permissions:\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_snapshot_sharing_permissions_2));
}

int main() {
  test_update_domain_settings_response_snapshot_sharing_permissions(1);
  test_update_domain_settings_response_snapshot_sharing_permissions(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_domain_settings_response_snapshot_sharing_permissions_MAIN
#endif // update_domain_settings_response_snapshot_sharing_permissions_TEST
