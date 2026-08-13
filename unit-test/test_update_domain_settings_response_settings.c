#ifndef update_domain_settings_response_settings_TEST
#define update_domain_settings_response_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_domain_settings_response_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_domain_settings_response_settings.h"
update_domain_settings_response_settings_t* instantiate_update_domain_settings_response_settings(int include_optional);



update_domain_settings_response_settings_t* instantiate_update_domain_settings_response_settings(int include_optional) {
  update_domain_settings_response_settings_t* update_domain_settings_response_settings = NULL;
  if (include_optional) {
    update_domain_settings_response_settings = update_domain_settings_response_settings_create(
      1
    );
  } else {
    update_domain_settings_response_settings = update_domain_settings_response_settings_create(
      1
    );
  }

  return update_domain_settings_response_settings;
}


#ifdef update_domain_settings_response_settings_MAIN

void test_update_domain_settings_response_settings(int include_optional) {
    update_domain_settings_response_settings_t* update_domain_settings_response_settings_1 = instantiate_update_domain_settings_response_settings(include_optional);

	cJSON* jsonupdate_domain_settings_response_settings_1 = update_domain_settings_response_settings_convertToJSON(update_domain_settings_response_settings_1);
	printf("update_domain_settings_response_settings :\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_settings_1));
	update_domain_settings_response_settings_t* update_domain_settings_response_settings_2 = update_domain_settings_response_settings_parseFromJSON(jsonupdate_domain_settings_response_settings_1);
	cJSON* jsonupdate_domain_settings_response_settings_2 = update_domain_settings_response_settings_convertToJSON(update_domain_settings_response_settings_2);
	printf("repeating update_domain_settings_response_settings:\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_settings_2));
}

int main() {
  test_update_domain_settings_response_settings(1);
  test_update_domain_settings_response_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_domain_settings_response_settings_MAIN
#endif // update_domain_settings_response_settings_TEST
