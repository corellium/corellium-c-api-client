#ifndef invite_created_TEST
#define invite_created_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_created_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_created.h"
invite_created_t* instantiate_invite_created(int include_optional);



invite_created_t* instantiate_invite_created(int include_optional) {
  invite_created_t* invite_created = NULL;
  if (include_optional) {
    invite_created = invite_created_create(
      "0",
      "0",
      0
    );
  } else {
    invite_created = invite_created_create(
      "0",
      "0",
      0
    );
  }

  return invite_created;
}


#ifdef invite_created_MAIN

void test_invite_created(int include_optional) {
    invite_created_t* invite_created_1 = instantiate_invite_created(include_optional);

	cJSON* jsoninvite_created_1 = invite_created_convertToJSON(invite_created_1);
	printf("invite_created :\n%s\n", cJSON_Print(jsoninvite_created_1));
	invite_created_t* invite_created_2 = invite_created_parseFromJSON(jsoninvite_created_1);
	cJSON* jsoninvite_created_2 = invite_created_convertToJSON(invite_created_2);
	printf("repeating invite_created:\n%s\n", cJSON_Print(jsoninvite_created_2));
}

int main() {
  test_invite_created(1);
  test_invite_created(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_created_MAIN
#endif // invite_created_TEST
