#ifndef invalid_totp_error_TEST
#define invalid_totp_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invalid_totp_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invalid_totp_error.h"
invalid_totp_error_t* instantiate_invalid_totp_error(int include_optional);



invalid_totp_error_t* instantiate_invalid_totp_error(int include_optional) {
  invalid_totp_error_t* invalid_totp_error = NULL;
  if (include_optional) {
    invalid_totp_error = invalid_totp_error_create(
      "Invalid TOTP.",
      corellium_api_invalid_totp_error_ERRORID_InvalidTOTP
    );
  } else {
    invalid_totp_error = invalid_totp_error_create(
      "Invalid TOTP.",
      corellium_api_invalid_totp_error_ERRORID_InvalidTOTP
    );
  }

  return invalid_totp_error;
}


#ifdef invalid_totp_error_MAIN

void test_invalid_totp_error(int include_optional) {
    invalid_totp_error_t* invalid_totp_error_1 = instantiate_invalid_totp_error(include_optional);

	cJSON* jsoninvalid_totp_error_1 = invalid_totp_error_convertToJSON(invalid_totp_error_1);
	printf("invalid_totp_error :\n%s\n", cJSON_Print(jsoninvalid_totp_error_1));
	invalid_totp_error_t* invalid_totp_error_2 = invalid_totp_error_parseFromJSON(jsoninvalid_totp_error_1);
	cJSON* jsoninvalid_totp_error_2 = invalid_totp_error_convertToJSON(invalid_totp_error_2);
	printf("repeating invalid_totp_error:\n%s\n", cJSON_Print(jsoninvalid_totp_error_2));
}

int main() {
  test_invalid_totp_error(1);
  test_invalid_totp_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // invalid_totp_error_MAIN
#endif // invalid_totp_error_TEST
