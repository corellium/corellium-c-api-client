#ifndef web_player_allowed_domains_TEST
#define web_player_allowed_domains_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define web_player_allowed_domains_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/web_player_allowed_domains.h"
web_player_allowed_domains_t* instantiate_web_player_allowed_domains(int include_optional);



web_player_allowed_domains_t* instantiate_web_player_allowed_domains(int include_optional) {
  web_player_allowed_domains_t* web_player_allowed_domains = NULL;
  if (include_optional) {
    web_player_allowed_domains = web_player_allowed_domains_create(
      ["example.com"]
    );
  } else {
    web_player_allowed_domains = web_player_allowed_domains_create(
      ["example.com"]
    );
  }

  return web_player_allowed_domains;
}


#ifdef web_player_allowed_domains_MAIN

void test_web_player_allowed_domains(int include_optional) {
    web_player_allowed_domains_t* web_player_allowed_domains_1 = instantiate_web_player_allowed_domains(include_optional);

	cJSON* jsonweb_player_allowed_domains_1 = web_player_allowed_domains_convertToJSON(web_player_allowed_domains_1);
	printf("web_player_allowed_domains :\n%s\n", cJSON_Print(jsonweb_player_allowed_domains_1));
	web_player_allowed_domains_t* web_player_allowed_domains_2 = web_player_allowed_domains_parseFromJSON(jsonweb_player_allowed_domains_1);
	cJSON* jsonweb_player_allowed_domains_2 = web_player_allowed_domains_convertToJSON(web_player_allowed_domains_2);
	printf("repeating web_player_allowed_domains:\n%s\n", cJSON_Print(jsonweb_player_allowed_domains_2));
}

int main() {
  test_web_player_allowed_domains(1);
  test_web_player_allowed_domains(0);

  printf("Hello world \n");
  return 0;
}

#endif // web_player_allowed_domains_MAIN
#endif // web_player_allowed_domains_TEST
