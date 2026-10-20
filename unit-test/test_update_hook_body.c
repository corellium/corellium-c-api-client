#ifndef update_hook_body_TEST
#define update_hook_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_hook_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_hook_body.h"
update_hook_body_t* instantiate_update_hook_body(int include_optional);



update_hook_body_t* instantiate_update_hook_body(int include_optional) {
  update_hook_body_t* update_hook_body = NULL;
  if (include_optional) {
    update_hook_body = update_hook_body_create(
      "Bypass jailbreak detection",
      "0x1000042a4",
      "return 0;",
      corellium_api_update_hook_body__csmfcc,
      false
    );
  } else {
    update_hook_body = update_hook_body_create(
      "Bypass jailbreak detection",
      "0x1000042a4",
      "return 0;",
      corellium_api_update_hook_body__csmfcc,
      false
    );
  }

  return update_hook_body;
}


#ifdef update_hook_body_MAIN

void test_update_hook_body(int include_optional) {
    update_hook_body_t* update_hook_body_1 = instantiate_update_hook_body(include_optional);

	cJSON* jsonupdate_hook_body_1 = update_hook_body_convertToJSON(update_hook_body_1);
	printf("update_hook_body :\n%s\n", cJSON_Print(jsonupdate_hook_body_1));
	update_hook_body_t* update_hook_body_2 = update_hook_body_parseFromJSON(jsonupdate_hook_body_1);
	cJSON* jsonupdate_hook_body_2 = update_hook_body_convertToJSON(update_hook_body_2);
	printf("repeating update_hook_body:\n%s\n", cJSON_Print(jsonupdate_hook_body_2));
}

int main() {
  test_update_hook_body(1);
  test_update_hook_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_hook_body_MAIN
#endif // update_hook_body_TEST
