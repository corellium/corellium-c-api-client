#ifndef totp_status_response_user_TEST
#define totp_status_response_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_status_response_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_status_response_user.h"
totp_status_response_user_t* instantiate_totp_status_response_user(int include_optional);



totp_status_response_user_t* instantiate_totp_status_response_user(int include_optional) {
  totp_status_response_user_t* totp_status_response_user = NULL;
  if (include_optional) {
    totp_status_response_user = totp_status_response_user_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    totp_status_response_user = totp_status_response_user_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return totp_status_response_user;
}


#ifdef totp_status_response_user_MAIN

void test_totp_status_response_user(int include_optional) {
    totp_status_response_user_t* totp_status_response_user_1 = instantiate_totp_status_response_user(include_optional);

	cJSON* jsontotp_status_response_user_1 = totp_status_response_user_convertToJSON(totp_status_response_user_1);
	printf("totp_status_response_user :\n%s\n", cJSON_Print(jsontotp_status_response_user_1));
	totp_status_response_user_t* totp_status_response_user_2 = totp_status_response_user_parseFromJSON(jsontotp_status_response_user_1);
	cJSON* jsontotp_status_response_user_2 = totp_status_response_user_convertToJSON(totp_status_response_user_2);
	printf("repeating totp_status_response_user:\n%s\n", cJSON_Print(jsontotp_status_response_user_2));
}

int main() {
  test_totp_status_response_user(1);
  test_totp_status_response_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_status_response_user_MAIN
#endif // totp_status_response_user_TEST
