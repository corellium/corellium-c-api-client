#ifndef update_domain_settings_response_TEST
#define update_domain_settings_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_domain_settings_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_domain_settings_response.h"
update_domain_settings_response_t* instantiate_update_domain_settings_response(int include_optional);

#include "test_update_domain_settings_response_settings.c"
#include "test_trial_extension.c"
#include "test_device_auto_shutdown_schema.c"
#include "test_update_domain_settings_response_webplayer.c"
#include "test_update_domain_settings_response_snapshot_sharing_permissions.c"


update_domain_settings_response_t* instantiate_update_domain_settings_response(int include_optional) {
  update_domain_settings_response_t* update_domain_settings_response = NULL;
  if (include_optional) {
    update_domain_settings_response = update_domain_settings_response_create(
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
       // false, not to have infinite recursion
      instantiate_update_domain_settings_response_settings(0),
       // false, not to have infinite recursion
      instantiate_trial_extension(0),
       // false, not to have infinite recursion
      instantiate_device_auto_shutdown_schema(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_update_domain_settings_response_webplayer(0),
       // false, not to have infinite recursion
      instantiate_update_domain_settings_response_snapshot_sharing_permissions(0)
    );
  } else {
    update_domain_settings_response = update_domain_settings_response_create(
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      NULL,
      NULL,
      NULL,
      list_createList(),
      NULL,
      NULL
    );
  }

  return update_domain_settings_response;
}


#ifdef update_domain_settings_response_MAIN

void test_update_domain_settings_response(int include_optional) {
    update_domain_settings_response_t* update_domain_settings_response_1 = instantiate_update_domain_settings_response(include_optional);

	cJSON* jsonupdate_domain_settings_response_1 = update_domain_settings_response_convertToJSON(update_domain_settings_response_1);
	printf("update_domain_settings_response :\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_1));
	update_domain_settings_response_t* update_domain_settings_response_2 = update_domain_settings_response_parseFromJSON(jsonupdate_domain_settings_response_1);
	cJSON* jsonupdate_domain_settings_response_2 = update_domain_settings_response_convertToJSON(update_domain_settings_response_2);
	printf("repeating update_domain_settings_response:\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_2));
}

int main() {
  test_update_domain_settings_response(1);
  test_update_domain_settings_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_domain_settings_response_MAIN
#endif // update_domain_settings_response_TEST
