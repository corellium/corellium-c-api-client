#ifndef totp_generate_response_TEST
#define totp_generate_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_generate_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_generate_response.h"
totp_generate_response_t* instantiate_totp_generate_response(int include_optional);



totp_generate_response_t* instantiate_totp_generate_response(int include_optional) {
  totp_generate_response_t* totp_generate_response = NULL;
  if (include_optional) {
    totp_generate_response = totp_generate_response_create(
      "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAAAAAA6fptVAAAAAXNSR0IArs4c6QAAAAtJREFUGFdjYAAAAAMAAWgmWQ0AAAAASUVORK5CYII=",
      "<totp-secret>"
    );
  } else {
    totp_generate_response = totp_generate_response_create(
      "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAAAAAA6fptVAAAAAXNSR0IArs4c6QAAAAtJREFUGFdjYAAAAAMAAWgmWQ0AAAAASUVORK5CYII=",
      "<totp-secret>"
    );
  }

  return totp_generate_response;
}


#ifdef totp_generate_response_MAIN

void test_totp_generate_response(int include_optional) {
    totp_generate_response_t* totp_generate_response_1 = instantiate_totp_generate_response(include_optional);

	cJSON* jsontotp_generate_response_1 = totp_generate_response_convertToJSON(totp_generate_response_1);
	printf("totp_generate_response :\n%s\n", cJSON_Print(jsontotp_generate_response_1));
	totp_generate_response_t* totp_generate_response_2 = totp_generate_response_parseFromJSON(jsontotp_generate_response_1);
	cJSON* jsontotp_generate_response_2 = totp_generate_response_convertToJSON(totp_generate_response_2);
	printf("repeating totp_generate_response:\n%s\n", cJSON_Print(jsontotp_generate_response_2));
}

int main() {
  test_totp_generate_response(1);
  test_totp_generate_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_generate_response_MAIN
#endif // totp_generate_response_TEST
