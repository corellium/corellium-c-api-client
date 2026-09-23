#ifndef open_id_config_TEST
#define open_id_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define open_id_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/open_id_config.h"
open_id_config_t* instantiate_open_id_config(int include_optional);



open_id_config_t* instantiate_open_id_config(int include_optional) {
  open_id_config_t* open_id_config = NULL;
  if (include_optional) {
    open_id_config = open_id_config_create(
      "https://accounts.example.com/.well-known/openid-configuration",
      "corellium-domain-client",
      "<client-secret>",
      false
    );
  } else {
    open_id_config = open_id_config_create(
      "https://accounts.example.com/.well-known/openid-configuration",
      "corellium-domain-client",
      "<client-secret>",
      false
    );
  }

  return open_id_config;
}


#ifdef open_id_config_MAIN

void test_open_id_config(int include_optional) {
    open_id_config_t* open_id_config_1 = instantiate_open_id_config(include_optional);

	cJSON* jsonopen_id_config_1 = open_id_config_convertToJSON(open_id_config_1);
	printf("open_id_config :\n%s\n", cJSON_Print(jsonopen_id_config_1));
	open_id_config_t* open_id_config_2 = open_id_config_parseFromJSON(jsonopen_id_config_1);
	cJSON* jsonopen_id_config_2 = open_id_config_convertToJSON(open_id_config_2);
	printf("repeating open_id_config:\n%s\n", cJSON_Print(jsonopen_id_config_2));
}

int main() {
  test_open_id_config(1);
  test_open_id_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // open_id_config_MAIN
#endif // open_id_config_TEST
