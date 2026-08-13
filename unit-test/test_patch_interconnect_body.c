#ifndef patch_interconnect_body_TEST
#define patch_interconnect_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_interconnect_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_interconnect_body.h"
patch_interconnect_body_t* instantiate_patch_interconnect_body(int include_optional);



patch_interconnect_body_t* instantiate_patch_interconnect_body(int include_optional) {
  patch_interconnect_body_t* patch_interconnect_body = NULL;
  if (include_optional) {
    patch_interconnect_body = patch_interconnect_body_create(
      "0",
      list_createList()
    );
  } else {
    patch_interconnect_body = patch_interconnect_body_create(
      "0",
      list_createList()
    );
  }

  return patch_interconnect_body;
}


#ifdef patch_interconnect_body_MAIN

void test_patch_interconnect_body(int include_optional) {
    patch_interconnect_body_t* patch_interconnect_body_1 = instantiate_patch_interconnect_body(include_optional);

	cJSON* jsonpatch_interconnect_body_1 = patch_interconnect_body_convertToJSON(patch_interconnect_body_1);
	printf("patch_interconnect_body :\n%s\n", cJSON_Print(jsonpatch_interconnect_body_1));
	patch_interconnect_body_t* patch_interconnect_body_2 = patch_interconnect_body_parseFromJSON(jsonpatch_interconnect_body_1);
	cJSON* jsonpatch_interconnect_body_2 = patch_interconnect_body_convertToJSON(patch_interconnect_body_2);
	printf("repeating patch_interconnect_body:\n%s\n", cJSON_Print(jsonpatch_interconnect_body_2));
}

int main() {
  test_patch_interconnect_body(1);
  test_patch_interconnect_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_interconnect_body_MAIN
#endif // patch_interconnect_body_TEST
