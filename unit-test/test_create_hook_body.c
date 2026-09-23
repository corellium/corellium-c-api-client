#ifndef create_hook_body_TEST
#define create_hook_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_hook_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_hook_body.h"
create_hook_body_t* instantiate_create_hook_body(int include_optional);



create_hook_body_t* instantiate_create_hook_body(int include_optional) {
  create_hook_body_t* create_hook_body = NULL;
  if (include_optional) {
    create_hook_body = create_hook_body_create(
      "Bypass jailbreak detection",
      "0x1000042a4",
      "return 0;",
      corellium_api_create_hook_body__csmfcc,
      1
    );
  } else {
    create_hook_body = create_hook_body_create(
      "Bypass jailbreak detection",
      "0x1000042a4",
      "return 0;",
      corellium_api_create_hook_body__csmfcc,
      1
    );
  }

  return create_hook_body;
}


#ifdef create_hook_body_MAIN

void test_create_hook_body(int include_optional) {
    create_hook_body_t* create_hook_body_1 = instantiate_create_hook_body(include_optional);

	cJSON* jsoncreate_hook_body_1 = create_hook_body_convertToJSON(create_hook_body_1);
	printf("create_hook_body :\n%s\n", cJSON_Print(jsoncreate_hook_body_1));
	create_hook_body_t* create_hook_body_2 = create_hook_body_parseFromJSON(jsoncreate_hook_body_1);
	cJSON* jsoncreate_hook_body_2 = create_hook_body_convertToJSON(create_hook_body_2);
	printf("repeating create_hook_body:\n%s\n", cJSON_Print(jsoncreate_hook_body_2));
}

int main() {
  test_create_hook_body(1);
  test_create_hook_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_hook_body_MAIN
#endif // create_hook_body_TEST
