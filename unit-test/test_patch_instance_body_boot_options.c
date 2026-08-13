#ifndef patch_instance_body_boot_options_TEST
#define patch_instance_body_boot_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_instance_body_boot_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_instance_body_boot_options.h"
patch_instance_body_boot_options_t* instantiate_patch_instance_body_boot_options(int include_optional);

#include "test_instance_boot_options_kernel.c"
#include "test_instance_boot_options_pongo.c"


patch_instance_body_boot_options_t* instantiate_patch_instance_body_boot_options(int include_optional) {
  patch_instance_body_boot_options_t* patch_instance_body_boot_options = NULL;
  if (include_optional) {
    patch_instance_body_boot_options = patch_instance_body_boot_options_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1.337,
      1.337,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_instance_boot_options_kernel(0),
       // false, not to have infinite recursion
      instantiate_instance_boot_options_pongo(0)
    );
  } else {
    patch_instance_body_boot_options = patch_instance_body_boot_options_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1.337,
      1.337,
      list_createList(),
      NULL,
      NULL
    );
  }

  return patch_instance_body_boot_options;
}


#ifdef patch_instance_body_boot_options_MAIN

void test_patch_instance_body_boot_options(int include_optional) {
    patch_instance_body_boot_options_t* patch_instance_body_boot_options_1 = instantiate_patch_instance_body_boot_options(include_optional);

	cJSON* jsonpatch_instance_body_boot_options_1 = patch_instance_body_boot_options_convertToJSON(patch_instance_body_boot_options_1);
	printf("patch_instance_body_boot_options :\n%s\n", cJSON_Print(jsonpatch_instance_body_boot_options_1));
	patch_instance_body_boot_options_t* patch_instance_body_boot_options_2 = patch_instance_body_boot_options_parseFromJSON(jsonpatch_instance_body_boot_options_1);
	cJSON* jsonpatch_instance_body_boot_options_2 = patch_instance_body_boot_options_convertToJSON(patch_instance_body_boot_options_2);
	printf("repeating patch_instance_body_boot_options:\n%s\n", cJSON_Print(jsonpatch_instance_body_boot_options_2));
}

int main() {
  test_patch_instance_body_boot_options(1);
  test_patch_instance_body_boot_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_instance_body_boot_options_MAIN
#endif // patch_instance_body_boot_options_TEST
