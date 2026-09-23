#ifndef enable_sslsplit_body_TEST
#define enable_sslsplit_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define enable_sslsplit_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/enable_sslsplit_body.h"
enable_sslsplit_body_t* instantiate_enable_sslsplit_body(int include_optional);



enable_sslsplit_body_t* instantiate_enable_sslsplit_body(int include_optional) {
  enable_sslsplit_body_t* enable_sslsplit_body = NULL;
  if (include_optional) {
    enable_sslsplit_body = enable_sslsplit_body_create(
      true
    );
  } else {
    enable_sslsplit_body = enable_sslsplit_body_create(
      true
    );
  }

  return enable_sslsplit_body;
}


#ifdef enable_sslsplit_body_MAIN

void test_enable_sslsplit_body(int include_optional) {
    enable_sslsplit_body_t* enable_sslsplit_body_1 = instantiate_enable_sslsplit_body(include_optional);

	cJSON* jsonenable_sslsplit_body_1 = enable_sslsplit_body_convertToJSON(enable_sslsplit_body_1);
	printf("enable_sslsplit_body :\n%s\n", cJSON_Print(jsonenable_sslsplit_body_1));
	enable_sslsplit_body_t* enable_sslsplit_body_2 = enable_sslsplit_body_parseFromJSON(jsonenable_sslsplit_body_1);
	cJSON* jsonenable_sslsplit_body_2 = enable_sslsplit_body_convertToJSON(enable_sslsplit_body_2);
	printf("repeating enable_sslsplit_body:\n%s\n", cJSON_Print(jsonenable_sslsplit_body_2));
}

int main() {
  test_enable_sslsplit_body(1);
  test_enable_sslsplit_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // enable_sslsplit_body_MAIN
#endif // enable_sslsplit_body_TEST
