#ifndef totp_disable_body_TEST
#define totp_disable_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_disable_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_disable_body.h"
totp_disable_body_t* instantiate_totp_disable_body(int include_optional);



totp_disable_body_t* instantiate_totp_disable_body(int include_optional) {
  totp_disable_body_t* totp_disable_body = NULL;
  if (include_optional) {
    totp_disable_body = totp_disable_body_create(
      "0",
      "0"
    );
  } else {
    totp_disable_body = totp_disable_body_create(
      "0",
      "0"
    );
  }

  return totp_disable_body;
}


#ifdef totp_disable_body_MAIN

void test_totp_disable_body(int include_optional) {
    totp_disable_body_t* totp_disable_body_1 = instantiate_totp_disable_body(include_optional);

	cJSON* jsontotp_disable_body_1 = totp_disable_body_convertToJSON(totp_disable_body_1);
	printf("totp_disable_body :\n%s\n", cJSON_Print(jsontotp_disable_body_1));
	totp_disable_body_t* totp_disable_body_2 = totp_disable_body_parseFromJSON(jsontotp_disable_body_1);
	cJSON* jsontotp_disable_body_2 = totp_disable_body_convertToJSON(totp_disable_body_2);
	printf("repeating totp_disable_body:\n%s\n", cJSON_Print(jsontotp_disable_body_2));
}

int main() {
  test_totp_disable_body(1);
  test_totp_disable_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_disable_body_MAIN
#endif // totp_disable_body_TEST
