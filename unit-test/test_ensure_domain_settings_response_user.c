#ifndef ensure_domain_settings_response_user_TEST
#define ensure_domain_settings_response_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ensure_domain_settings_response_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ensure_domain_settings_response_user.h"
ensure_domain_settings_response_user_t* instantiate_ensure_domain_settings_response_user(int include_optional);



ensure_domain_settings_response_user_t* instantiate_ensure_domain_settings_response_user(int include_optional) {
  ensure_domain_settings_response_user_t* ensure_domain_settings_response_user = NULL;
  if (include_optional) {
    ensure_domain_settings_response_user = ensure_domain_settings_response_user_create(
      "0",
      1
    );
  } else {
    ensure_domain_settings_response_user = ensure_domain_settings_response_user_create(
      "0",
      1
    );
  }

  return ensure_domain_settings_response_user;
}


#ifdef ensure_domain_settings_response_user_MAIN

void test_ensure_domain_settings_response_user(int include_optional) {
    ensure_domain_settings_response_user_t* ensure_domain_settings_response_user_1 = instantiate_ensure_domain_settings_response_user(include_optional);

	cJSON* jsonensure_domain_settings_response_user_1 = ensure_domain_settings_response_user_convertToJSON(ensure_domain_settings_response_user_1);
	printf("ensure_domain_settings_response_user :\n%s\n", cJSON_Print(jsonensure_domain_settings_response_user_1));
	ensure_domain_settings_response_user_t* ensure_domain_settings_response_user_2 = ensure_domain_settings_response_user_parseFromJSON(jsonensure_domain_settings_response_user_1);
	cJSON* jsonensure_domain_settings_response_user_2 = ensure_domain_settings_response_user_convertToJSON(ensure_domain_settings_response_user_2);
	printf("repeating ensure_domain_settings_response_user:\n%s\n", cJSON_Print(jsonensure_domain_settings_response_user_2));
}

int main() {
  test_ensure_domain_settings_response_user(1);
  test_ensure_domain_settings_response_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // ensure_domain_settings_response_user_MAIN
#endif // ensure_domain_settings_response_user_TEST
