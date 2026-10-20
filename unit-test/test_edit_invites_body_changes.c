#ifndef edit_invites_body_changes_TEST
#define edit_invites_body_changes_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define edit_invites_body_changes_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/edit_invites_body_changes.h"
edit_invites_body_changes_t* instantiate_edit_invites_body_changes(int include_optional);

#include "test_invite_settings.c"


edit_invites_body_changes_t* instantiate_edit_invites_body_changes(int include_optional) {
  edit_invites_body_changes_t* edit_invites_body_changes = NULL;
  if (include_optional) {
    edit_invites_body_changes = edit_invites_body_changes_create(
       // false, not to have infinite recursion
      instantiate_invite_settings(0)
    );
  } else {
    edit_invites_body_changes = edit_invites_body_changes_create(
      NULL
    );
  }

  return edit_invites_body_changes;
}


#ifdef edit_invites_body_changes_MAIN

void test_edit_invites_body_changes(int include_optional) {
    edit_invites_body_changes_t* edit_invites_body_changes_1 = instantiate_edit_invites_body_changes(include_optional);

	cJSON* jsonedit_invites_body_changes_1 = edit_invites_body_changes_convertToJSON(edit_invites_body_changes_1);
	printf("edit_invites_body_changes :\n%s\n", cJSON_Print(jsonedit_invites_body_changes_1));
	edit_invites_body_changes_t* edit_invites_body_changes_2 = edit_invites_body_changes_parseFromJSON(jsonedit_invites_body_changes_1);
	cJSON* jsonedit_invites_body_changes_2 = edit_invites_body_changes_convertToJSON(edit_invites_body_changes_2);
	printf("repeating edit_invites_body_changes:\n%s\n", cJSON_Print(jsonedit_invites_body_changes_2));
}

int main() {
  test_edit_invites_body_changes(1);
  test_edit_invites_body_changes(0);

  printf("Hello world \n");
  return 0;
}

#endif // edit_invites_body_changes_MAIN
#endif // edit_invites_body_changes_TEST
