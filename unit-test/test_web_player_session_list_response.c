#ifndef web_player_session_list_response_TEST
#define web_player_session_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define web_player_session_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/web_player_session_list_response.h"
web_player_session_list_response_t* instantiate_web_player_session_list_response(int include_optional);



web_player_session_list_response_t* instantiate_web_player_session_list_response(int include_optional) {
  web_player_session_list_response_t* web_player_session_list_response = NULL;
  if (include_optional) {
    web_player_session_list_response = web_player_session_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    web_player_session_list_response = web_player_session_list_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return web_player_session_list_response;
}


#ifdef web_player_session_list_response_MAIN

void test_web_player_session_list_response(int include_optional) {
    web_player_session_list_response_t* web_player_session_list_response_1 = instantiate_web_player_session_list_response(include_optional);

	cJSON* jsonweb_player_session_list_response_1 = web_player_session_list_response_convertToJSON(web_player_session_list_response_1);
	printf("web_player_session_list_response :\n%s\n", cJSON_Print(jsonweb_player_session_list_response_1));
	web_player_session_list_response_t* web_player_session_list_response_2 = web_player_session_list_response_parseFromJSON(jsonweb_player_session_list_response_1);
	cJSON* jsonweb_player_session_list_response_2 = web_player_session_list_response_convertToJSON(web_player_session_list_response_2);
	printf("repeating web_player_session_list_response:\n%s\n", cJSON_Print(jsonweb_player_session_list_response_2));
}

int main() {
  test_web_player_session_list_response(1);
  test_web_player_session_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // web_player_session_list_response_MAIN
#endif // web_player_session_list_response_TEST
