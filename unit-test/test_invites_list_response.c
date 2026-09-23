#ifndef invites_list_response_TEST
#define invites_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invites_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invites_list_response.h"
invites_list_response_t* instantiate_invites_list_response(int include_optional);



invites_list_response_t* instantiate_invites_list_response(int include_optional) {
  invites_list_response_t* invites_list_response = NULL;
  if (include_optional) {
    invites_list_response = invites_list_response_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    invites_list_response = invites_list_response_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return invites_list_response;
}


#ifdef invites_list_response_MAIN

void test_invites_list_response(int include_optional) {
    invites_list_response_t* invites_list_response_1 = instantiate_invites_list_response(include_optional);

	cJSON* jsoninvites_list_response_1 = invites_list_response_convertToJSON(invites_list_response_1);
	printf("invites_list_response :\n%s\n", cJSON_Print(jsoninvites_list_response_1));
	invites_list_response_t* invites_list_response_2 = invites_list_response_parseFromJSON(jsoninvites_list_response_1);
	cJSON* jsoninvites_list_response_2 = invites_list_response_convertToJSON(invites_list_response_2);
	printf("repeating invites_list_response:\n%s\n", cJSON_Print(jsoninvites_list_response_2));
}

int main() {
  test_invites_list_response(1);
  test_invites_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // invites_list_response_MAIN
#endif // invites_list_response_TEST
