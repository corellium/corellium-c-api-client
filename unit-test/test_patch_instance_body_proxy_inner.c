#ifndef patch_instance_body_proxy_inner_TEST
#define patch_instance_body_proxy_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_instance_body_proxy_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_instance_body_proxy_inner.h"
patch_instance_body_proxy_inner_t* instantiate_patch_instance_body_proxy_inner(int include_optional);



patch_instance_body_proxy_inner_t* instantiate_patch_instance_body_proxy_inner(int include_optional) {
  patch_instance_body_proxy_inner_t* patch_instance_body_proxy_inner = NULL;
  if (include_optional) {
    patch_instance_body_proxy_inner = patch_instance_body_proxy_inner_create(
      1.337,
      1,
      1,
      1.337
    );
  } else {
    patch_instance_body_proxy_inner = patch_instance_body_proxy_inner_create(
      1.337,
      1,
      1,
      1.337
    );
  }

  return patch_instance_body_proxy_inner;
}


#ifdef patch_instance_body_proxy_inner_MAIN

void test_patch_instance_body_proxy_inner(int include_optional) {
    patch_instance_body_proxy_inner_t* patch_instance_body_proxy_inner_1 = instantiate_patch_instance_body_proxy_inner(include_optional);

	cJSON* jsonpatch_instance_body_proxy_inner_1 = patch_instance_body_proxy_inner_convertToJSON(patch_instance_body_proxy_inner_1);
	printf("patch_instance_body_proxy_inner :\n%s\n", cJSON_Print(jsonpatch_instance_body_proxy_inner_1));
	patch_instance_body_proxy_inner_t* patch_instance_body_proxy_inner_2 = patch_instance_body_proxy_inner_parseFromJSON(jsonpatch_instance_body_proxy_inner_1);
	cJSON* jsonpatch_instance_body_proxy_inner_2 = patch_instance_body_proxy_inner_convertToJSON(patch_instance_body_proxy_inner_2);
	printf("repeating patch_instance_body_proxy_inner:\n%s\n", cJSON_Print(jsonpatch_instance_body_proxy_inner_2));
}

int main() {
  test_patch_instance_body_proxy_inner(1);
  test_patch_instance_body_proxy_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_instance_body_proxy_inner_MAIN
#endif // patch_instance_body_proxy_inner_TEST
