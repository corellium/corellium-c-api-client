#ifndef invite_created_entry_TEST
#define invite_created_entry_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_created_entry_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_created_entry.h"
invite_created_entry_t* instantiate_invite_created_entry(int include_optional);

#include "test_invite_created.c"


invite_created_entry_t* instantiate_invite_created_entry(int include_optional) {
  invite_created_entry_t* invite_created_entry = NULL;
  if (include_optional) {
    invite_created_entry = invite_created_entry_create(
       // false, not to have infinite recursion
      instantiate_invite_created(0)
    );
  } else {
    invite_created_entry = invite_created_entry_create(
      NULL
    );
  }

  return invite_created_entry;
}


#ifdef invite_created_entry_MAIN

void test_invite_created_entry(int include_optional) {
    invite_created_entry_t* invite_created_entry_1 = instantiate_invite_created_entry(include_optional);

	cJSON* jsoninvite_created_entry_1 = invite_created_entry_convertToJSON(invite_created_entry_1);
	printf("invite_created_entry :\n%s\n", cJSON_Print(jsoninvite_created_entry_1));
	invite_created_entry_t* invite_created_entry_2 = invite_created_entry_parseFromJSON(jsoninvite_created_entry_1);
	cJSON* jsoninvite_created_entry_2 = invite_created_entry_convertToJSON(invite_created_entry_2);
	printf("repeating invite_created_entry:\n%s\n", cJSON_Print(jsoninvite_created_entry_2));
}

int main() {
  test_invite_created_entry(1);
  test_invite_created_entry(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_created_entry_MAIN
#endif // invite_created_entry_TEST
