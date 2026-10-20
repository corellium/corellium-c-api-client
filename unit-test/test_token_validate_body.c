#ifndef token_validate_body_TEST
#define token_validate_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define token_validate_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/token_validate_body.h"
token_validate_body_t* instantiate_token_validate_body(int include_optional);



token_validate_body_t* instantiate_token_validate_body(int include_optional) {
  token_validate_body_t* token_validate_body = NULL;
  if (include_optional) {
    token_validate_body = token_validate_body_create(
      "<redacted>"
    );
  } else {
    token_validate_body = token_validate_body_create(
      "<redacted>"
    );
  }

  return token_validate_body;
}


#ifdef token_validate_body_MAIN

void test_token_validate_body(int include_optional) {
    token_validate_body_t* token_validate_body_1 = instantiate_token_validate_body(include_optional);

	cJSON* jsontoken_validate_body_1 = token_validate_body_convertToJSON(token_validate_body_1);
	printf("token_validate_body :\n%s\n", cJSON_Print(jsontoken_validate_body_1));
	token_validate_body_t* token_validate_body_2 = token_validate_body_parseFromJSON(jsontoken_validate_body_1);
	cJSON* jsontoken_validate_body_2 = token_validate_body_convertToJSON(token_validate_body_2);
	printf("repeating token_validate_body:\n%s\n", cJSON_Print(jsontoken_validate_body_2));
}

int main() {
  test_token_validate_body(1);
  test_token_validate_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // token_validate_body_MAIN
#endif // token_validate_body_TEST
