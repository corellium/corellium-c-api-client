#ifndef update_domain_settings_response_webplayer_TEST
#define update_domain_settings_response_webplayer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_domain_settings_response_webplayer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_domain_settings_response_webplayer.h"
update_domain_settings_response_webplayer_t* instantiate_update_domain_settings_response_webplayer(int include_optional);



update_domain_settings_response_webplayer_t* instantiate_update_domain_settings_response_webplayer(int include_optional) {
  update_domain_settings_response_webplayer_t* update_domain_settings_response_webplayer = NULL;
  if (include_optional) {
    update_domain_settings_response_webplayer = update_domain_settings_response_webplayer_create(
      ["app.example.com"]
    );
  } else {
    update_domain_settings_response_webplayer = update_domain_settings_response_webplayer_create(
      ["app.example.com"]
    );
  }

  return update_domain_settings_response_webplayer;
}


#ifdef update_domain_settings_response_webplayer_MAIN

void test_update_domain_settings_response_webplayer(int include_optional) {
    update_domain_settings_response_webplayer_t* update_domain_settings_response_webplayer_1 = instantiate_update_domain_settings_response_webplayer(include_optional);

	cJSON* jsonupdate_domain_settings_response_webplayer_1 = update_domain_settings_response_webplayer_convertToJSON(update_domain_settings_response_webplayer_1);
	printf("update_domain_settings_response_webplayer :\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_webplayer_1));
	update_domain_settings_response_webplayer_t* update_domain_settings_response_webplayer_2 = update_domain_settings_response_webplayer_parseFromJSON(jsonupdate_domain_settings_response_webplayer_1);
	cJSON* jsonupdate_domain_settings_response_webplayer_2 = update_domain_settings_response_webplayer_convertToJSON(update_domain_settings_response_webplayer_2);
	printf("repeating update_domain_settings_response_webplayer:\n%s\n", cJSON_Print(jsonupdate_domain_settings_response_webplayer_2));
}

int main() {
  test_update_domain_settings_response_webplayer(1);
  test_update_domain_settings_response_webplayer(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_domain_settings_response_webplayer_MAIN
#endif // update_domain_settings_response_webplayer_TEST
