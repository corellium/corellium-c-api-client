#ifndef get_invite_by_token_body_TEST
#define get_invite_by_token_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_invite_by_token_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_invite_by_token_body.h"
get_invite_by_token_body_t* instantiate_get_invite_by_token_body(int include_optional);



get_invite_by_token_body_t* instantiate_get_invite_by_token_body(int include_optional) {
  get_invite_by_token_body_t* get_invite_by_token_body = NULL;
  if (include_optional) {
    get_invite_by_token_body = get_invite_by_token_body_create(
      "<token>"
    );
  } else {
    get_invite_by_token_body = get_invite_by_token_body_create(
      "<token>"
    );
  }

  return get_invite_by_token_body;
}


#ifdef get_invite_by_token_body_MAIN

void test_get_invite_by_token_body(int include_optional) {
    get_invite_by_token_body_t* get_invite_by_token_body_1 = instantiate_get_invite_by_token_body(include_optional);

	cJSON* jsonget_invite_by_token_body_1 = get_invite_by_token_body_convertToJSON(get_invite_by_token_body_1);
	printf("get_invite_by_token_body :\n%s\n", cJSON_Print(jsonget_invite_by_token_body_1));
	get_invite_by_token_body_t* get_invite_by_token_body_2 = get_invite_by_token_body_parseFromJSON(jsonget_invite_by_token_body_1);
	cJSON* jsonget_invite_by_token_body_2 = get_invite_by_token_body_convertToJSON(get_invite_by_token_body_2);
	printf("repeating get_invite_by_token_body:\n%s\n", cJSON_Print(jsonget_invite_by_token_body_2));
}

int main() {
  test_get_invite_by_token_body(1);
  test_get_invite_by_token_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_invite_by_token_body_MAIN
#endif // get_invite_by_token_body_TEST
