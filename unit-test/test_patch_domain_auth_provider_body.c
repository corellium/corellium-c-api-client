#ifndef patch_domain_auth_provider_body_TEST
#define patch_domain_auth_provider_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_domain_auth_provider_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_domain_auth_provider_body.h"
patch_domain_auth_provider_body_t* instantiate_patch_domain_auth_provider_body(int include_optional);

#include "test_domain_auth_provider_config.c"


patch_domain_auth_provider_body_t* instantiate_patch_domain_auth_provider_body(int include_optional) {
  patch_domain_auth_provider_body_t* patch_domain_auth_provider_body = NULL;
  if (include_optional) {
    patch_domain_auth_provider_body = patch_domain_auth_provider_body_create(
      "open-id-connect",
      true,
      "Log in with Okta",
      null
    );
  } else {
    patch_domain_auth_provider_body = patch_domain_auth_provider_body_create(
      "open-id-connect",
      true,
      "Log in with Okta",
      null
    );
  }

  return patch_domain_auth_provider_body;
}


#ifdef patch_domain_auth_provider_body_MAIN

void test_patch_domain_auth_provider_body(int include_optional) {
    patch_domain_auth_provider_body_t* patch_domain_auth_provider_body_1 = instantiate_patch_domain_auth_provider_body(include_optional);

	cJSON* jsonpatch_domain_auth_provider_body_1 = patch_domain_auth_provider_body_convertToJSON(patch_domain_auth_provider_body_1);
	printf("patch_domain_auth_provider_body :\n%s\n", cJSON_Print(jsonpatch_domain_auth_provider_body_1));
	patch_domain_auth_provider_body_t* patch_domain_auth_provider_body_2 = patch_domain_auth_provider_body_parseFromJSON(jsonpatch_domain_auth_provider_body_1);
	cJSON* jsonpatch_domain_auth_provider_body_2 = patch_domain_auth_provider_body_convertToJSON(patch_domain_auth_provider_body_2);
	printf("repeating patch_domain_auth_provider_body:\n%s\n", cJSON_Print(jsonpatch_domain_auth_provider_body_2));
}

int main() {
  test_patch_domain_auth_provider_body(1);
  test_patch_domain_auth_provider_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_domain_auth_provider_body_MAIN
#endif // patch_domain_auth_provider_body_TEST
