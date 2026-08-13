#ifndef enable_netdump_body_TEST
#define enable_netdump_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define enable_netdump_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/enable_netdump_body.h"
enable_netdump_body_t* instantiate_enable_netdump_body(int include_optional);



enable_netdump_body_t* instantiate_enable_netdump_body(int include_optional) {
  enable_netdump_body_t* enable_netdump_body = NULL;
  if (include_optional) {
    enable_netdump_body = enable_netdump_body_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList()
    );
  } else {
    enable_netdump_body = enable_netdump_body_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList()
    );
  }

  return enable_netdump_body;
}


#ifdef enable_netdump_body_MAIN

void test_enable_netdump_body(int include_optional) {
    enable_netdump_body_t* enable_netdump_body_1 = instantiate_enable_netdump_body(include_optional);

	cJSON* jsonenable_netdump_body_1 = enable_netdump_body_convertToJSON(enable_netdump_body_1);
	printf("enable_netdump_body :\n%s\n", cJSON_Print(jsonenable_netdump_body_1));
	enable_netdump_body_t* enable_netdump_body_2 = enable_netdump_body_parseFromJSON(jsonenable_netdump_body_1);
	cJSON* jsonenable_netdump_body_2 = enable_netdump_body_convertToJSON(enable_netdump_body_2);
	printf("repeating enable_netdump_body:\n%s\n", cJSON_Print(jsonenable_netdump_body_2));
}

int main() {
  test_enable_netdump_body(1);
  test_enable_netdump_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // enable_netdump_body_MAIN
#endif // enable_netdump_body_TEST
