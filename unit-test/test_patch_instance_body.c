#ifndef patch_instance_body_TEST
#define patch_instance_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_instance_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_instance_body.h"
patch_instance_body_t* instantiate_patch_instance_body(int include_optional);

#include "test_patch_instance_body_boot_options.c"


patch_instance_body_t* instantiate_patch_instance_body(int include_optional) {
  patch_instance_body_t* patch_instance_body = NULL;
  if (include_optional) {
    patch_instance_body = patch_instance_body_create(
      "My iPhone 13 Pro",
      null,
      list_createList(),
      list_createList()
    );
  } else {
    patch_instance_body = patch_instance_body_create(
      "My iPhone 13 Pro",
      null,
      list_createList(),
      list_createList()
    );
  }

  return patch_instance_body;
}


#ifdef patch_instance_body_MAIN

void test_patch_instance_body(int include_optional) {
    patch_instance_body_t* patch_instance_body_1 = instantiate_patch_instance_body(include_optional);

	cJSON* jsonpatch_instance_body_1 = patch_instance_body_convertToJSON(patch_instance_body_1);
	printf("patch_instance_body :\n%s\n", cJSON_Print(jsonpatch_instance_body_1));
	patch_instance_body_t* patch_instance_body_2 = patch_instance_body_parseFromJSON(jsonpatch_instance_body_1);
	cJSON* jsonpatch_instance_body_2 = patch_instance_body_convertToJSON(patch_instance_body_2);
	printf("repeating patch_instance_body:\n%s\n", cJSON_Print(jsonpatch_instance_body_2));
}

int main() {
  test_patch_instance_body(1);
  test_patch_instance_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_instance_body_MAIN
#endif // patch_instance_body_TEST
