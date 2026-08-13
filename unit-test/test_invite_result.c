#ifndef invite_result_TEST
#define invite_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_result.h"
invite_result_t* instantiate_invite_result(int include_optional);

#include "test_invite_result_invite.c"
#include "test_invite_result_error.c"


invite_result_t* instantiate_invite_result(int include_optional) {
  invite_result_t* invite_result = NULL;
  if (include_optional) {
    invite_result = invite_result_create(
      null,
       // false, not to have infinite recursion
      instantiate_invite_result_error(0)
    );
  } else {
    invite_result = invite_result_create(
      null,
      NULL
    );
  }

  return invite_result;
}


#ifdef invite_result_MAIN

void test_invite_result(int include_optional) {
    invite_result_t* invite_result_1 = instantiate_invite_result(include_optional);

	cJSON* jsoninvite_result_1 = invite_result_convertToJSON(invite_result_1);
	printf("invite_result :\n%s\n", cJSON_Print(jsoninvite_result_1));
	invite_result_t* invite_result_2 = invite_result_parseFromJSON(jsoninvite_result_1);
	cJSON* jsoninvite_result_2 = invite_result_convertToJSON(invite_result_2);
	printf("repeating invite_result:\n%s\n", cJSON_Print(jsoninvite_result_2));
}

int main() {
  test_invite_result(1);
  test_invite_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_result_MAIN
#endif // invite_result_TEST
