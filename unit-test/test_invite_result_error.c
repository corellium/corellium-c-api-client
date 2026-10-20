#ifndef invite_result_error_TEST
#define invite_result_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_result_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_result_error.h"
invite_result_error_t* instantiate_invite_result_error(int include_optional);



invite_result_error_t* instantiate_invite_result_error(int include_optional) {
  invite_result_error_t* invite_result_error = NULL;
  if (include_optional) {
    invite_result_error = invite_result_error_create(
      "An invite has already been sent to jane.doe@example.com for this domain"
    );
  } else {
    invite_result_error = invite_result_error_create(
      "An invite has already been sent to jane.doe@example.com for this domain"
    );
  }

  return invite_result_error;
}


#ifdef invite_result_error_MAIN

void test_invite_result_error(int include_optional) {
    invite_result_error_t* invite_result_error_1 = instantiate_invite_result_error(include_optional);

	cJSON* jsoninvite_result_error_1 = invite_result_error_convertToJSON(invite_result_error_1);
	printf("invite_result_error :\n%s\n", cJSON_Print(jsoninvite_result_error_1));
	invite_result_error_t* invite_result_error_2 = invite_result_error_parseFromJSON(jsoninvite_result_error_1);
	cJSON* jsoninvite_result_error_2 = invite_result_error_convertToJSON(invite_result_error_2);
	printf("repeating invite_result_error:\n%s\n", cJSON_Print(jsoninvite_result_error_2));
}

int main() {
  test_invite_result_error(1);
  test_invite_result_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_result_error_MAIN
#endif // invite_result_error_TEST
