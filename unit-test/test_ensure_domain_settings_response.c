#ifndef ensure_domain_settings_response_TEST
#define ensure_domain_settings_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ensure_domain_settings_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ensure_domain_settings_response.h"
ensure_domain_settings_response_t* instantiate_ensure_domain_settings_response(int include_optional);

#include "test_ensure_domain_settings_response_user.c"


ensure_domain_settings_response_t* instantiate_ensure_domain_settings_response(int include_optional) {
  ensure_domain_settings_response_t* ensure_domain_settings_response = NULL;
  if (include_optional) {
    ensure_domain_settings_response = ensure_domain_settings_response_create(
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_ensure_domain_settings_response_user(0)
    );
  } else {
    ensure_domain_settings_response = ensure_domain_settings_response_create(
      1,
      "0",
      NULL
    );
  }

  return ensure_domain_settings_response;
}


#ifdef ensure_domain_settings_response_MAIN

void test_ensure_domain_settings_response(int include_optional) {
    ensure_domain_settings_response_t* ensure_domain_settings_response_1 = instantiate_ensure_domain_settings_response(include_optional);

	cJSON* jsonensure_domain_settings_response_1 = ensure_domain_settings_response_convertToJSON(ensure_domain_settings_response_1);
	printf("ensure_domain_settings_response :\n%s\n", cJSON_Print(jsonensure_domain_settings_response_1));
	ensure_domain_settings_response_t* ensure_domain_settings_response_2 = ensure_domain_settings_response_parseFromJSON(jsonensure_domain_settings_response_1);
	cJSON* jsonensure_domain_settings_response_2 = ensure_domain_settings_response_convertToJSON(ensure_domain_settings_response_2);
	printf("repeating ensure_domain_settings_response:\n%s\n", cJSON_Print(jsonensure_domain_settings_response_2));
}

int main() {
  test_ensure_domain_settings_response(1);
  test_ensure_domain_settings_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // ensure_domain_settings_response_MAIN
#endif // ensure_domain_settings_response_TEST
