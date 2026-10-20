#ifndef create_web_player_session_body_TEST
#define create_web_player_session_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_web_player_session_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_web_player_session_body.h"
create_web_player_session_body_t* instantiate_create_web_player_session_body(int include_optional);

#include "test_web_player_features.c"


create_web_player_session_body_t* instantiate_create_web_player_session_body(int include_optional) {
  create_web_player_session_body_t* create_web_player_session_body = NULL;
  if (include_optional) {
    create_web_player_session_body = create_web_player_session_body_create(
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      18000,
       // false, not to have infinite recursion
      instantiate_web_player_features(0),
      "web-console-1234"
    );
  } else {
    create_web_player_session_body = create_web_player_session_body_create(
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      18000,
      NULL,
      "web-console-1234"
    );
  }

  return create_web_player_session_body;
}


#ifdef create_web_player_session_body_MAIN

void test_create_web_player_session_body(int include_optional) {
    create_web_player_session_body_t* create_web_player_session_body_1 = instantiate_create_web_player_session_body(include_optional);

	cJSON* jsoncreate_web_player_session_body_1 = create_web_player_session_body_convertToJSON(create_web_player_session_body_1);
	printf("create_web_player_session_body :\n%s\n", cJSON_Print(jsoncreate_web_player_session_body_1));
	create_web_player_session_body_t* create_web_player_session_body_2 = create_web_player_session_body_parseFromJSON(jsoncreate_web_player_session_body_1);
	cJSON* jsoncreate_web_player_session_body_2 = create_web_player_session_body_convertToJSON(create_web_player_session_body_2);
	printf("repeating create_web_player_session_body:\n%s\n", cJSON_Print(jsoncreate_web_player_session_body_2));
}

int main() {
  test_create_web_player_session_body(1);
  test_create_web_player_session_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_web_player_session_body_MAIN
#endif // create_web_player_session_body_TEST
