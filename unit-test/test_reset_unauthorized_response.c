#ifndef reset_unauthorized_response_TEST
#define reset_unauthorized_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reset_unauthorized_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reset_unauthorized_response.h"
reset_unauthorized_response_t* instantiate_reset_unauthorized_response(int include_optional);



reset_unauthorized_response_t* instantiate_reset_unauthorized_response(int include_optional) {
  reset_unauthorized_response_t* reset_unauthorized_response = NULL;
  if (include_optional) {
    reset_unauthorized_response = reset_unauthorized_response_create(
      "Access denied",
      corellium_api_reset_unauthorized_response_ERRORID_Unauthorized
    );
  } else {
    reset_unauthorized_response = reset_unauthorized_response_create(
      "Access denied",
      corellium_api_reset_unauthorized_response_ERRORID_Unauthorized
    );
  }

  return reset_unauthorized_response;
}


#ifdef reset_unauthorized_response_MAIN

void test_reset_unauthorized_response(int include_optional) {
    reset_unauthorized_response_t* reset_unauthorized_response_1 = instantiate_reset_unauthorized_response(include_optional);

	cJSON* jsonreset_unauthorized_response_1 = reset_unauthorized_response_convertToJSON(reset_unauthorized_response_1);
	printf("reset_unauthorized_response :\n%s\n", cJSON_Print(jsonreset_unauthorized_response_1));
	reset_unauthorized_response_t* reset_unauthorized_response_2 = reset_unauthorized_response_parseFromJSON(jsonreset_unauthorized_response_1);
	cJSON* jsonreset_unauthorized_response_2 = reset_unauthorized_response_convertToJSON(reset_unauthorized_response_2);
	printf("repeating reset_unauthorized_response:\n%s\n", cJSON_Print(jsonreset_unauthorized_response_2));
}

int main() {
  test_reset_unauthorized_response(1);
  test_reset_unauthorized_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // reset_unauthorized_response_MAIN
#endif // reset_unauthorized_response_TEST
