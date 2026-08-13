#ifndef reset_password_body_TEST
#define reset_password_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reset_password_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reset_password_body.h"
reset_password_body_t* instantiate_reset_password_body(int include_optional);



reset_password_body_t* instantiate_reset_password_body(int include_optional) {
  reset_password_body_t* reset_password_body = NULL;
  if (include_optional) {
    reset_password_body = reset_password_body_create(
      "0",
      "0",
      "0"
    );
  } else {
    reset_password_body = reset_password_body_create(
      "0",
      "0",
      "0"
    );
  }

  return reset_password_body;
}


#ifdef reset_password_body_MAIN

void test_reset_password_body(int include_optional) {
    reset_password_body_t* reset_password_body_1 = instantiate_reset_password_body(include_optional);

	cJSON* jsonreset_password_body_1 = reset_password_body_convertToJSON(reset_password_body_1);
	printf("reset_password_body :\n%s\n", cJSON_Print(jsonreset_password_body_1));
	reset_password_body_t* reset_password_body_2 = reset_password_body_parseFromJSON(jsonreset_password_body_1);
	cJSON* jsonreset_password_body_2 = reset_password_body_convertToJSON(reset_password_body_2);
	printf("repeating reset_password_body:\n%s\n", cJSON_Print(jsonreset_password_body_2));
}

int main() {
  test_reset_password_body(1);
  test_reset_password_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // reset_password_body_MAIN
#endif // reset_password_body_TEST
