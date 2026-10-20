#ifndef patch_project_body_settings_TEST
#define patch_project_body_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_project_body_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_project_body_settings.h"
patch_project_body_settings_t* instantiate_patch_project_body_settings(int include_optional);



patch_project_body_settings_t* instantiate_patch_project_body_settings(int include_optional) {
  patch_project_body_settings_t* patch_project_body_settings = NULL;
  if (include_optional) {
    patch_project_body_settings = patch_project_body_settings_create(
      1,
      true,
      true,
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7"
    );
  } else {
    patch_project_body_settings = patch_project_body_settings_create(
      1,
      true,
      true,
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7"
    );
  }

  return patch_project_body_settings;
}


#ifdef patch_project_body_settings_MAIN

void test_patch_project_body_settings(int include_optional) {
    patch_project_body_settings_t* patch_project_body_settings_1 = instantiate_patch_project_body_settings(include_optional);

	cJSON* jsonpatch_project_body_settings_1 = patch_project_body_settings_convertToJSON(patch_project_body_settings_1);
	printf("patch_project_body_settings :\n%s\n", cJSON_Print(jsonpatch_project_body_settings_1));
	patch_project_body_settings_t* patch_project_body_settings_2 = patch_project_body_settings_parseFromJSON(jsonpatch_project_body_settings_1);
	cJSON* jsonpatch_project_body_settings_2 = patch_project_body_settings_convertToJSON(patch_project_body_settings_2);
	printf("repeating patch_project_body_settings:\n%s\n", cJSON_Print(jsonpatch_project_body_settings_2));
}

int main() {
  test_patch_project_body_settings(1);
  test_patch_project_body_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_project_body_settings_MAIN
#endif // patch_project_body_settings_TEST
