#ifndef totp_enable_body_TEST
#define totp_enable_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_enable_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_enable_body.h"
totp_enable_body_t* instantiate_totp_enable_body(int include_optional);



totp_enable_body_t* instantiate_totp_enable_body(int include_optional) {
  totp_enable_body_t* totp_enable_body = NULL;
  if (include_optional) {
    totp_enable_body = totp_enable_body_create(
      "0",
      "0",
      "0"
    );
  } else {
    totp_enable_body = totp_enable_body_create(
      "0",
      "0",
      "0"
    );
  }

  return totp_enable_body;
}


#ifdef totp_enable_body_MAIN

void test_totp_enable_body(int include_optional) {
    totp_enable_body_t* totp_enable_body_1 = instantiate_totp_enable_body(include_optional);

	cJSON* jsontotp_enable_body_1 = totp_enable_body_convertToJSON(totp_enable_body_1);
	printf("totp_enable_body :\n%s\n", cJSON_Print(jsontotp_enable_body_1));
	totp_enable_body_t* totp_enable_body_2 = totp_enable_body_parseFromJSON(jsontotp_enable_body_1);
	cJSON* jsontotp_enable_body_2 = totp_enable_body_convertToJSON(totp_enable_body_2);
	printf("repeating totp_enable_body:\n%s\n", cJSON_Print(jsontotp_enable_body_2));
}

int main() {
  test_totp_enable_body(1);
  test_totp_enable_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_enable_body_MAIN
#endif // totp_enable_body_TEST
