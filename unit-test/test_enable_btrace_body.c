#ifndef enable_btrace_body_TEST
#define enable_btrace_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define enable_btrace_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/enable_btrace_body.h"
enable_btrace_body_t* instantiate_enable_btrace_body(int include_optional);



enable_btrace_body_t* instantiate_enable_btrace_body(int include_optional) {
  enable_btrace_body_t* enable_btrace_body = NULL;
  if (include_optional) {
    enable_btrace_body = enable_btrace_body_create(
      list_createList()
    );
  } else {
    enable_btrace_body = enable_btrace_body_create(
      list_createList()
    );
  }

  return enable_btrace_body;
}


#ifdef enable_btrace_body_MAIN

void test_enable_btrace_body(int include_optional) {
    enable_btrace_body_t* enable_btrace_body_1 = instantiate_enable_btrace_body(include_optional);

	cJSON* jsonenable_btrace_body_1 = enable_btrace_body_convertToJSON(enable_btrace_body_1);
	printf("enable_btrace_body :\n%s\n", cJSON_Print(jsonenable_btrace_body_1));
	enable_btrace_body_t* enable_btrace_body_2 = enable_btrace_body_parseFromJSON(jsonenable_btrace_body_1);
	cJSON* jsonenable_btrace_body_2 = enable_btrace_body_convertToJSON(enable_btrace_body_2);
	printf("repeating enable_btrace_body:\n%s\n", cJSON_Print(jsonenable_btrace_body_2));
}

int main() {
  test_enable_btrace_body(1);
  test_enable_btrace_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // enable_btrace_body_MAIN
#endif // enable_btrace_body_TEST
