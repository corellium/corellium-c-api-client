#ifndef totp_status_response_TEST
#define totp_status_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_status_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_status_response.h"
totp_status_response_t* instantiate_totp_status_response(int include_optional);

#include "test_totp_status_response_user.c"
#include "test_totp_status_response_domain.c"


totp_status_response_t* instantiate_totp_status_response(int include_optional) {
  totp_status_response_t* totp_status_response = NULL;
  if (include_optional) {
    totp_status_response = totp_status_response_create(
      "0",
      1.337,
       // false, not to have infinite recursion
      instantiate_totp_status_response_user(0),
       // false, not to have infinite recursion
      instantiate_totp_status_response_domain(0)
    );
  } else {
    totp_status_response = totp_status_response_create(
      "0",
      1.337,
      NULL,
      NULL
    );
  }

  return totp_status_response;
}


#ifdef totp_status_response_MAIN

void test_totp_status_response(int include_optional) {
    totp_status_response_t* totp_status_response_1 = instantiate_totp_status_response(include_optional);

	cJSON* jsontotp_status_response_1 = totp_status_response_convertToJSON(totp_status_response_1);
	printf("totp_status_response :\n%s\n", cJSON_Print(jsontotp_status_response_1));
	totp_status_response_t* totp_status_response_2 = totp_status_response_parseFromJSON(jsontotp_status_response_1);
	cJSON* jsontotp_status_response_2 = totp_status_response_convertToJSON(totp_status_response_2);
	printf("repeating totp_status_response:\n%s\n", cJSON_Print(jsontotp_status_response_2));
}

int main() {
  test_totp_status_response(1);
  test_totp_status_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_status_response_MAIN
#endif // totp_status_response_TEST
