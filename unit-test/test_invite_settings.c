#ifndef invite_settings_TEST
#define invite_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define invite_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/invite_settings.h"
invite_settings_t* instantiate_invite_settings(int include_optional);



invite_settings_t* instantiate_invite_settings(int include_optional) {
  invite_settings_t* invite_settings = NULL;
  if (include_optional) {
    invite_settings = invite_settings_create(
      list_createList(),
      list_createList()
    );
  } else {
    invite_settings = invite_settings_create(
      list_createList(),
      list_createList()
    );
  }

  return invite_settings;
}


#ifdef invite_settings_MAIN

void test_invite_settings(int include_optional) {
    invite_settings_t* invite_settings_1 = instantiate_invite_settings(include_optional);

	cJSON* jsoninvite_settings_1 = invite_settings_convertToJSON(invite_settings_1);
	printf("invite_settings :\n%s\n", cJSON_Print(jsoninvite_settings_1));
	invite_settings_t* invite_settings_2 = invite_settings_parseFromJSON(jsoninvite_settings_1);
	cJSON* jsoninvite_settings_2 = invite_settings_convertToJSON(invite_settings_2);
	printf("repeating invite_settings:\n%s\n", cJSON_Print(jsoninvite_settings_2));
}

int main() {
  test_invite_settings(1);
  test_invite_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // invite_settings_MAIN
#endif // invite_settings_TEST
