#ifndef web_player_session_v1_TEST
#define web_player_session_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define web_player_session_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/web_player_session_v1.h"
web_player_session_v1_t* instantiate_web_player_session_v1(int include_optional);



web_player_session_v1_t* instantiate_web_player_session_v1(int include_optional) {
  web_player_session_v1_t* web_player_session_v1 = NULL;
  if (include_optional) {
    web_player_session_v1 = web_player_session_v1_create(
      "0",
      "0",
      1.337
    );
  } else {
    web_player_session_v1 = web_player_session_v1_create(
      "0",
      "0",
      1.337
    );
  }

  return web_player_session_v1;
}


#ifdef web_player_session_v1_MAIN

void test_web_player_session_v1(int include_optional) {
    web_player_session_v1_t* web_player_session_v1_1 = instantiate_web_player_session_v1(include_optional);

	cJSON* jsonweb_player_session_v1_1 = web_player_session_v1_convertToJSON(web_player_session_v1_1);
	printf("web_player_session_v1 :\n%s\n", cJSON_Print(jsonweb_player_session_v1_1));
	web_player_session_v1_t* web_player_session_v1_2 = web_player_session_v1_parseFromJSON(jsonweb_player_session_v1_1);
	cJSON* jsonweb_player_session_v1_2 = web_player_session_v1_convertToJSON(web_player_session_v1_2);
	printf("repeating web_player_session_v1:\n%s\n", cJSON_Print(jsonweb_player_session_v1_2));
}

int main() {
  test_web_player_session_v1(1);
  test_web_player_session_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // web_player_session_v1_MAIN
#endif // web_player_session_v1_TEST
