#ifndef web_player_session_domain_TEST
#define web_player_session_domain_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define web_player_session_domain_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/web_player_session_domain.h"
web_player_session_domain_t* instantiate_web_player_session_domain(int include_optional);



web_player_session_domain_t* instantiate_web_player_session_domain(int include_optional) {
  web_player_session_domain_t* web_player_session_domain = NULL;
  if (include_optional) {
    web_player_session_domain = web_player_session_domain_create(
      "acme-corp",
      "Acme Corp",
      "all-modal",
      8,
      false,
      true
    );
  } else {
    web_player_session_domain = web_player_session_domain_create(
      "acme-corp",
      "Acme Corp",
      "all-modal",
      8,
      false,
      true
    );
  }

  return web_player_session_domain;
}


#ifdef web_player_session_domain_MAIN

void test_web_player_session_domain(int include_optional) {
    web_player_session_domain_t* web_player_session_domain_1 = instantiate_web_player_session_domain(include_optional);

	cJSON* jsonweb_player_session_domain_1 = web_player_session_domain_convertToJSON(web_player_session_domain_1);
	printf("web_player_session_domain :\n%s\n", cJSON_Print(jsonweb_player_session_domain_1));
	web_player_session_domain_t* web_player_session_domain_2 = web_player_session_domain_parseFromJSON(jsonweb_player_session_domain_1);
	cJSON* jsonweb_player_session_domain_2 = web_player_session_domain_convertToJSON(web_player_session_domain_2);
	printf("repeating web_player_session_domain:\n%s\n", cJSON_Print(jsonweb_player_session_domain_2));
}

int main() {
  test_web_player_session_domain(1);
  test_web_player_session_domain(0);

  printf("Hello world \n");
  return 0;
}

#endif // web_player_session_domain_MAIN
#endif // web_player_session_domain_TEST
