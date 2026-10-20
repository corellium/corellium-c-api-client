#ifndef ensure_domain_settings_body_admin_user_TEST
#define ensure_domain_settings_body_admin_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ensure_domain_settings_body_admin_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ensure_domain_settings_body_admin_user.h"
ensure_domain_settings_body_admin_user_t* instantiate_ensure_domain_settings_body_admin_user(int include_optional);



ensure_domain_settings_body_admin_user_t* instantiate_ensure_domain_settings_body_admin_user(int include_optional) {
  ensure_domain_settings_body_admin_user_t* ensure_domain_settings_body_admin_user = NULL;
  if (include_optional) {
    ensure_domain_settings_body_admin_user = ensure_domain_settings_body_admin_user_create(
      "jane.doe",
      "jane.doe@example.com",
      "Jane Doe",
      "https://billing.example.com/portal"
    );
  } else {
    ensure_domain_settings_body_admin_user = ensure_domain_settings_body_admin_user_create(
      "jane.doe",
      "jane.doe@example.com",
      "Jane Doe",
      "https://billing.example.com/portal"
    );
  }

  return ensure_domain_settings_body_admin_user;
}


#ifdef ensure_domain_settings_body_admin_user_MAIN

void test_ensure_domain_settings_body_admin_user(int include_optional) {
    ensure_domain_settings_body_admin_user_t* ensure_domain_settings_body_admin_user_1 = instantiate_ensure_domain_settings_body_admin_user(include_optional);

	cJSON* jsonensure_domain_settings_body_admin_user_1 = ensure_domain_settings_body_admin_user_convertToJSON(ensure_domain_settings_body_admin_user_1);
	printf("ensure_domain_settings_body_admin_user :\n%s\n", cJSON_Print(jsonensure_domain_settings_body_admin_user_1));
	ensure_domain_settings_body_admin_user_t* ensure_domain_settings_body_admin_user_2 = ensure_domain_settings_body_admin_user_parseFromJSON(jsonensure_domain_settings_body_admin_user_1);
	cJSON* jsonensure_domain_settings_body_admin_user_2 = ensure_domain_settings_body_admin_user_convertToJSON(ensure_domain_settings_body_admin_user_2);
	printf("repeating ensure_domain_settings_body_admin_user:\n%s\n", cJSON_Print(jsonensure_domain_settings_body_admin_user_2));
}

int main() {
  test_ensure_domain_settings_body_admin_user(1);
  test_ensure_domain_settings_body_admin_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // ensure_domain_settings_body_admin_user_MAIN
#endif // ensure_domain_settings_body_admin_user_TEST
