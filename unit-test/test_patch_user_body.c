#ifndef patch_user_body_TEST
#define patch_user_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_user_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_user_body.h"
patch_user_body_t* instantiate_patch_user_body(int include_optional);



patch_user_body_t* instantiate_patch_user_body(int include_optional) {
  patch_user_body_t* patch_user_body = NULL;
  if (include_optional) {
    patch_user_body = patch_user_body_create(
      "jane.doe",
      "Domain Administrator",
      "jane.doe@example.com",
      false,
      "<redacted>",
      {"lastVPNType":"ovpn"},
      true,
      "2026-05-22T13:58:34.000Z",
      true
    );
  } else {
    patch_user_body = patch_user_body_create(
      "jane.doe",
      "Domain Administrator",
      "jane.doe@example.com",
      false,
      "<redacted>",
      {"lastVPNType":"ovpn"},
      true,
      "2026-05-22T13:58:34.000Z",
      true
    );
  }

  return patch_user_body;
}


#ifdef patch_user_body_MAIN

void test_patch_user_body(int include_optional) {
    patch_user_body_t* patch_user_body_1 = instantiate_patch_user_body(include_optional);

	cJSON* jsonpatch_user_body_1 = patch_user_body_convertToJSON(patch_user_body_1);
	printf("patch_user_body :\n%s\n", cJSON_Print(jsonpatch_user_body_1));
	patch_user_body_t* patch_user_body_2 = patch_user_body_parseFromJSON(jsonpatch_user_body_1);
	cJSON* jsonpatch_user_body_2 = patch_user_body_convertToJSON(patch_user_body_2);
	printf("repeating patch_user_body:\n%s\n", cJSON_Print(jsonpatch_user_body_2));
}

int main() {
  test_patch_user_body(1);
  test_patch_user_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_user_body_MAIN
#endif // patch_user_body_TEST
