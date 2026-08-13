#ifndef hook_v1_TEST
#define hook_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hook_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hook_v1.h"
hook_v1_t* instantiate_hook_v1(int include_optional);



hook_v1_t* instantiate_hook_v1(int include_optional) {
  hook_v1_t* hook_v1 = NULL;
  if (include_optional) {
    hook_v1 = hook_v1_create(
      "0",
      "0",
      "0",
      "0",
      corellium_api_hook_v1_PATCHTYPE_csmfcc,
      1,
      "0",
      "0",
      "0"
    );
  } else {
    hook_v1 = hook_v1_create(
      "0",
      "0",
      "0",
      "0",
      corellium_api_hook_v1_PATCHTYPE_csmfcc,
      1,
      "0",
      "0",
      "0"
    );
  }

  return hook_v1;
}


#ifdef hook_v1_MAIN

void test_hook_v1(int include_optional) {
    hook_v1_t* hook_v1_1 = instantiate_hook_v1(include_optional);

	cJSON* jsonhook_v1_1 = hook_v1_convertToJSON(hook_v1_1);
	printf("hook_v1 :\n%s\n", cJSON_Print(jsonhook_v1_1));
	hook_v1_t* hook_v1_2 = hook_v1_parseFromJSON(jsonhook_v1_1);
	cJSON* jsonhook_v1_2 = hook_v1_convertToJSON(hook_v1_2);
	printf("repeating hook_v1:\n%s\n", cJSON_Print(jsonhook_v1_2));
}

int main() {
  test_hook_v1(1);
  test_hook_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // hook_v1_MAIN
#endif // hook_v1_TEST
