#ifndef create_invites_body_TEST
#define create_invites_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_invites_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_invites_body.h"
create_invites_body_t* instantiate_create_invites_body(int include_optional);

#include "test_create_invites_body_settings.c"


create_invites_body_t* instantiate_create_invites_body(int include_optional) {
  create_invites_body_t* create_invites_body = NULL;
  if (include_optional) {
    create_invites_body = create_invites_body_create(
      list_createList(),
      1,
      null
    );
  } else {
    create_invites_body = create_invites_body_create(
      list_createList(),
      1,
      null
    );
  }

  return create_invites_body;
}


#ifdef create_invites_body_MAIN

void test_create_invites_body(int include_optional) {
    create_invites_body_t* create_invites_body_1 = instantiate_create_invites_body(include_optional);

	cJSON* jsoncreate_invites_body_1 = create_invites_body_convertToJSON(create_invites_body_1);
	printf("create_invites_body :\n%s\n", cJSON_Print(jsoncreate_invites_body_1));
	create_invites_body_t* create_invites_body_2 = create_invites_body_parseFromJSON(jsoncreate_invites_body_1);
	cJSON* jsoncreate_invites_body_2 = create_invites_body_convertToJSON(create_invites_body_2);
	printf("repeating create_invites_body:\n%s\n", cJSON_Print(jsoncreate_invites_body_2));
}

int main() {
  test_create_invites_body(1);
  test_create_invites_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_invites_body_MAIN
#endif // create_invites_body_TEST
