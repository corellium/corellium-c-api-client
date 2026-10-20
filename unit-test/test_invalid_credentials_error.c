#ifndef invalid_credentials_error_TEST
#define invalid_credentials_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invalid_credentials_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invalid_credentials_error.h"
invalid_credentials_error_t* instantiate_invalid_credentials_error(int include_optional);



invalid_credentials_error_t* instantiate_invalid_credentials_error(int include_optional) {
  invalid_credentials_error_t* invalid_credentials_error = NULL;
  if (include_optional) {
    invalid_credentials_error = invalid_credentials_error_create(
      "The credentials are incorrect or you may be using a different authentication provider.",
      corellium_api_invalid_credentials_error_ERRORID_InvalidUsernameorPassword
    );
  } else {
    invalid_credentials_error = invalid_credentials_error_create(
      "The credentials are incorrect or you may be using a different authentication provider.",
      corellium_api_invalid_credentials_error_ERRORID_InvalidUsernameorPassword
    );
  }

  return invalid_credentials_error;
}


#ifdef invalid_credentials_error_MAIN

void test_invalid_credentials_error(int include_optional) {
    invalid_credentials_error_t* invalid_credentials_error_1 = instantiate_invalid_credentials_error(include_optional);

	cJSON* jsoninvalid_credentials_error_1 = invalid_credentials_error_convertToJSON(invalid_credentials_error_1);
	printf("invalid_credentials_error :\n%s\n", cJSON_Print(jsoninvalid_credentials_error_1));
	invalid_credentials_error_t* invalid_credentials_error_2 = invalid_credentials_error_parseFromJSON(jsoninvalid_credentials_error_1);
	cJSON* jsoninvalid_credentials_error_2 = invalid_credentials_error_convertToJSON(invalid_credentials_error_2);
	printf("repeating invalid_credentials_error:\n%s\n", cJSON_Print(jsoninvalid_credentials_error_2));
}

int main() {
  test_invalid_credentials_error(1);
  test_invalid_credentials_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // invalid_credentials_error_MAIN
#endif // invalid_credentials_error_TEST
