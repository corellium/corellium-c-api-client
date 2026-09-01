#ifndef hook_patch_type_TEST
#define hook_patch_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hook_patch_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hook_patch_type.h"
hook_patch_type_t* instantiate_hook_patch_type(int include_optional);



hook_patch_type_t* instantiate_hook_patch_type(int include_optional) {
  hook_patch_type_t* hook_patch_type = NULL;
  if (include_optional) {
    hook_patch_type = hook_patch_type_create(
    );
  } else {
    hook_patch_type = hook_patch_type_create(
    );
  }

  return hook_patch_type;
}


#ifdef hook_patch_type_MAIN

void test_hook_patch_type(int include_optional) {
    hook_patch_type_t* hook_patch_type_1 = instantiate_hook_patch_type(include_optional);

	cJSON* jsonhook_patch_type_1 = hook_patch_type_convertToJSON(hook_patch_type_1);
	printf("hook_patch_type :\n%s\n", cJSON_Print(jsonhook_patch_type_1));
	hook_patch_type_t* hook_patch_type_2 = hook_patch_type_parseFromJSON(jsonhook_patch_type_1);
	cJSON* jsonhook_patch_type_2 = hook_patch_type_convertToJSON(hook_patch_type_2);
	printf("repeating hook_patch_type:\n%s\n", cJSON_Print(jsonhook_patch_type_2));
}

int main() {
  test_hook_patch_type(1);
  test_hook_patch_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // hook_patch_type_MAIN
#endif // hook_patch_type_TEST
