#ifndef patch_domain_body_TEST
#define patch_domain_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_domain_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_domain_body.h"
patch_domain_body_t* instantiate_patch_domain_body(int include_optional);

#include "test_trial_extension.c"
#include "test_device_auto_shutdown_schema.c"
#include "test_patch_domain_body_webplayer.c"
#include "test_snapshot_sharing_permissions_request_schema.c"


patch_domain_body_t* instantiate_patch_domain_body(int include_optional) {
  patch_domain_body_t* patch_domain_body = NULL;
  if (include_optional) {
    patch_domain_body = patch_domain_body_create(
      true,
       // false, not to have infinite recursion
      instantiate_trial_extension(0),
       // false, not to have infinite recursion
      instantiate_device_auto_shutdown_schema(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_patch_domain_body_webplayer(0),
       // false, not to have infinite recursion
      instantiate_snapshot_sharing_permissions_request_schema(0)
    );
  } else {
    patch_domain_body = patch_domain_body_create(
      true,
      NULL,
      NULL,
      list_createList(),
      NULL,
      NULL
    );
  }

  return patch_domain_body;
}


#ifdef patch_domain_body_MAIN

void test_patch_domain_body(int include_optional) {
    patch_domain_body_t* patch_domain_body_1 = instantiate_patch_domain_body(include_optional);

	cJSON* jsonpatch_domain_body_1 = patch_domain_body_convertToJSON(patch_domain_body_1);
	printf("patch_domain_body :\n%s\n", cJSON_Print(jsonpatch_domain_body_1));
	patch_domain_body_t* patch_domain_body_2 = patch_domain_body_parseFromJSON(jsonpatch_domain_body_1);
	cJSON* jsonpatch_domain_body_2 = patch_domain_body_convertToJSON(patch_domain_body_2);
	printf("repeating patch_domain_body:\n%s\n", cJSON_Print(jsonpatch_domain_body_2));
}

int main() {
  test_patch_domain_body(1);
  test_patch_domain_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_domain_body_MAIN
#endif // patch_domain_body_TEST
