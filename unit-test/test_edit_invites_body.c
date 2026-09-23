#ifndef edit_invites_body_TEST
#define edit_invites_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_invites_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_invites_body.h"
edit_invites_body_t* instantiate_edit_invites_body(int include_optional);

#include "test_edit_invites_body_changes.c"


edit_invites_body_t* instantiate_edit_invites_body(int include_optional) {
  edit_invites_body_t* edit_invites_body = NULL;
  if (include_optional) {
    edit_invites_body = edit_invites_body_create(
      ["5ac8f0be-616d-45b9-b0af-e586fc65ad19"],
       // false, not to have infinite recursion
      instantiate_edit_invites_body_changes(0)
    );
  } else {
    edit_invites_body = edit_invites_body_create(
      ["5ac8f0be-616d-45b9-b0af-e586fc65ad19"],
      NULL
    );
  }

  return edit_invites_body;
}


#ifdef edit_invites_body_MAIN

void test_edit_invites_body(int include_optional) {
    edit_invites_body_t* edit_invites_body_1 = instantiate_edit_invites_body(include_optional);

	cJSON* jsonedit_invites_body_1 = edit_invites_body_convertToJSON(edit_invites_body_1);
	printf("edit_invites_body :\n%s\n", cJSON_Print(jsonedit_invites_body_1));
	edit_invites_body_t* edit_invites_body_2 = edit_invites_body_parseFromJSON(jsonedit_invites_body_1);
	cJSON* jsonedit_invites_body_2 = edit_invites_body_convertToJSON(edit_invites_body_2);
	printf("repeating edit_invites_body:\n%s\n", cJSON_Print(jsonedit_invites_body_2));
}

int main() {
  test_edit_invites_body(1);
  test_edit_invites_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_invites_body_MAIN
#endif // edit_invites_body_TEST
