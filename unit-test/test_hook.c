#ifndef hook_TEST
#define hook_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hook_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hook.h"
hook_t* instantiate_hook(int include_optional);



hook_t* instantiate_hook(int include_optional) {
  hook_t* hook = NULL;
  if (include_optional) {
    hook = hook_create(
      "2a1192e8-c7de-4981-bc11-c87fd1f12d13",
      "Bypass jailbreak detection",
      "0x1000042a4",
      "return 0;",
      corellium_api_hook__csmfcc,
      true,
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    hook = hook_create(
      "2a1192e8-c7de-4981-bc11-c87fd1f12d13",
      "Bypass jailbreak detection",
      "0x1000042a4",
      "return 0;",
      corellium_api_hook__csmfcc,
      true,
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return hook;
}


#ifdef hook_MAIN

void test_hook(int include_optional) {
    hook_t* hook_1 = instantiate_hook(include_optional);

	cJSON* jsonhook_1 = hook_convertToJSON(hook_1);
	printf("hook :\n%s\n", cJSON_Print(jsonhook_1));
	hook_t* hook_2 = hook_parseFromJSON(jsonhook_1);
	cJSON* jsonhook_2 = hook_convertToJSON(hook_2);
	printf("repeating hook:\n%s\n", cJSON_Print(jsonhook_2));
}

int main() {
  test_hook(1);
  test_hook(0);

  printf("Hello world \n");
  return 0;
}

#endif // hook_MAIN
#endif // hook_TEST
