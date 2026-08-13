#ifndef hook_list_TEST
#define hook_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hook_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hook_list.h"
hook_list_t* instantiate_hook_list(int include_optional);



hook_list_t* instantiate_hook_list(int include_optional) {
  hook_list_t* hook_list = NULL;
  if (include_optional) {
    hook_list = hook_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    hook_list = hook_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return hook_list;
}


#ifdef hook_list_MAIN

void test_hook_list(int include_optional) {
    hook_list_t* hook_list_1 = instantiate_hook_list(include_optional);

	cJSON* jsonhook_list_1 = hook_list_convertToJSON(hook_list_1);
	printf("hook_list :\n%s\n", cJSON_Print(jsonhook_list_1));
	hook_list_t* hook_list_2 = hook_list_parseFromJSON(jsonhook_list_1);
	cJSON* jsonhook_list_2 = hook_list_convertToJSON(hook_list_2);
	printf("repeating hook_list:\n%s\n", cJSON_Print(jsonhook_list_2));
}

int main() {
  test_hook_list(1);
  test_hook_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // hook_list_MAIN
#endif // hook_list_TEST
