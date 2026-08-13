#ifndef patch_project_body_TEST
#define patch_project_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_project_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_project_body.h"
patch_project_body_t* instantiate_patch_project_body(int include_optional);

#include "test_patch_project_body_settings.c"
#include "test_patch_project_body_quotas.c"


patch_project_body_t* instantiate_patch_project_body(int include_optional) {
  patch_project_body_t* patch_project_body = NULL;
  if (include_optional) {
    patch_project_body = patch_project_body_create(
      "0",
      null,
      null
    );
  } else {
    patch_project_body = patch_project_body_create(
      "0",
      null,
      null
    );
  }

  return patch_project_body;
}


#ifdef patch_project_body_MAIN

void test_patch_project_body(int include_optional) {
    patch_project_body_t* patch_project_body_1 = instantiate_patch_project_body(include_optional);

	cJSON* jsonpatch_project_body_1 = patch_project_body_convertToJSON(patch_project_body_1);
	printf("patch_project_body :\n%s\n", cJSON_Print(jsonpatch_project_body_1));
	patch_project_body_t* patch_project_body_2 = patch_project_body_parseFromJSON(jsonpatch_project_body_1);
	cJSON* jsonpatch_project_body_2 = patch_project_body_convertToJSON(patch_project_body_2);
	printf("repeating patch_project_body:\n%s\n", cJSON_Print(jsonpatch_project_body_2));
}

int main() {
  test_patch_project_body(1);
  test_patch_project_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_project_body_MAIN
#endif // patch_project_body_TEST
