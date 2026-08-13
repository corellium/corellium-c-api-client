#ifndef token_v1_TEST
#define token_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define token_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/token_v1.h"
token_v1_t* instantiate_token_v1(int include_optional);



token_v1_t* instantiate_token_v1(int include_optional) {
  token_v1_t* token_v1 = NULL;
  if (include_optional) {
    token_v1 = token_v1_create(
      "0"
    );
  } else {
    token_v1 = token_v1_create(
      "0"
    );
  }

  return token_v1;
}


#ifdef token_v1_MAIN

void test_token_v1(int include_optional) {
    token_v1_t* token_v1_1 = instantiate_token_v1(include_optional);

	cJSON* jsontoken_v1_1 = token_v1_convertToJSON(token_v1_1);
	printf("token_v1 :\n%s\n", cJSON_Print(jsontoken_v1_1));
	token_v1_t* token_v1_2 = token_v1_parseFromJSON(jsontoken_v1_1);
	cJSON* jsontoken_v1_2 = token_v1_convertToJSON(token_v1_2);
	printf("repeating token_v1:\n%s\n", cJSON_Print(jsontoken_v1_2));
}

int main() {
  test_token_v1(1);
  test_token_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // token_v1_MAIN
#endif // token_v1_TEST
