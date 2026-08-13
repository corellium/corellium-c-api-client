#ifndef ensure_domain_settings_body_TEST
#define ensure_domain_settings_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ensure_domain_settings_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ensure_domain_settings_body.h"
ensure_domain_settings_body_t* instantiate_ensure_domain_settings_body(int include_optional);

#include "test_domain_config_input.c"
#include "test_ensure_domain_settings_body_admin_user.c"


ensure_domain_settings_body_t* instantiate_ensure_domain_settings_body(int include_optional) {
  ensure_domain_settings_body_t* ensure_domain_settings_body = NULL;
  if (include_optional) {
    ensure_domain_settings_body = ensure_domain_settings_body_create(
      "0",
      "0",
      56,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_domain_config_input(0),
       // false, not to have infinite recursion
      instantiate_ensure_domain_settings_body_admin_user(0)
    );
  } else {
    ensure_domain_settings_body = ensure_domain_settings_body_create(
      "0",
      "0",
      56,
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return ensure_domain_settings_body;
}


#ifdef ensure_domain_settings_body_MAIN

void test_ensure_domain_settings_body(int include_optional) {
    ensure_domain_settings_body_t* ensure_domain_settings_body_1 = instantiate_ensure_domain_settings_body(include_optional);

	cJSON* jsonensure_domain_settings_body_1 = ensure_domain_settings_body_convertToJSON(ensure_domain_settings_body_1);
	printf("ensure_domain_settings_body :\n%s\n", cJSON_Print(jsonensure_domain_settings_body_1));
	ensure_domain_settings_body_t* ensure_domain_settings_body_2 = ensure_domain_settings_body_parseFromJSON(jsonensure_domain_settings_body_1);
	cJSON* jsonensure_domain_settings_body_2 = ensure_domain_settings_body_convertToJSON(ensure_domain_settings_body_2);
	printf("repeating ensure_domain_settings_body:\n%s\n", cJSON_Print(jsonensure_domain_settings_body_2));
}

int main() {
  test_ensure_domain_settings_body(1);
  test_ensure_domain_settings_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // ensure_domain_settings_body_MAIN
#endif // ensure_domain_settings_body_TEST
