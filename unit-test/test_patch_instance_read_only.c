#ifndef patch_instance_read_only_TEST
#define patch_instance_read_only_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_instance_read_only_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_instance_read_only.h"
patch_instance_read_only_t* instantiate_patch_instance_read_only(int include_optional);



patch_instance_read_only_t* instantiate_patch_instance_read_only(int include_optional) {
  patch_instance_read_only_t* patch_instance_read_only = NULL;
  if (include_optional) {
    patch_instance_read_only = patch_instance_read_only_create(
      "0"
    );
  } else {
    patch_instance_read_only = patch_instance_read_only_create(
      "0"
    );
  }

  return patch_instance_read_only;
}


#ifdef patch_instance_read_only_MAIN

void test_patch_instance_read_only(int include_optional) {
    patch_instance_read_only_t* patch_instance_read_only_1 = instantiate_patch_instance_read_only(include_optional);

	cJSON* jsonpatch_instance_read_only_1 = patch_instance_read_only_convertToJSON(patch_instance_read_only_1);
	printf("patch_instance_read_only :\n%s\n", cJSON_Print(jsonpatch_instance_read_only_1));
	patch_instance_read_only_t* patch_instance_read_only_2 = patch_instance_read_only_parseFromJSON(jsonpatch_instance_read_only_1);
	cJSON* jsonpatch_instance_read_only_2 = patch_instance_read_only_convertToJSON(patch_instance_read_only_2);
	printf("repeating patch_instance_read_only:\n%s\n", cJSON_Print(jsonpatch_instance_read_only_2));
}

int main() {
  test_patch_instance_read_only(1);
  test_patch_instance_read_only(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_instance_read_only_MAIN
#endif // patch_instance_read_only_TEST
