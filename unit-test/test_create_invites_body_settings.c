#ifndef create_invites_body_settings_TEST
#define create_invites_body_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_invites_body_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_invites_body_settings.h"
create_invites_body_settings_t* instantiate_create_invites_body_settings(int include_optional);



create_invites_body_settings_t* instantiate_create_invites_body_settings(int include_optional) {
  create_invites_body_settings_t* create_invites_body_settings = NULL;
  if (include_optional) {
    create_invites_body_settings = create_invites_body_settings_create(
      [089c8ffd-ca4d-4d35-80ab-0847d18b7213],
      [[1c41b1bc-4f53-48a8-b690-ad30611e1960, admin]]
    );
  } else {
    create_invites_body_settings = create_invites_body_settings_create(
      [089c8ffd-ca4d-4d35-80ab-0847d18b7213],
      [[1c41b1bc-4f53-48a8-b690-ad30611e1960, admin]]
    );
  }

  return create_invites_body_settings;
}


#ifdef create_invites_body_settings_MAIN

void test_create_invites_body_settings(int include_optional) {
    create_invites_body_settings_t* create_invites_body_settings_1 = instantiate_create_invites_body_settings(include_optional);

	cJSON* jsoncreate_invites_body_settings_1 = create_invites_body_settings_convertToJSON(create_invites_body_settings_1);
	printf("create_invites_body_settings :\n%s\n", cJSON_Print(jsoncreate_invites_body_settings_1));
	create_invites_body_settings_t* create_invites_body_settings_2 = create_invites_body_settings_parseFromJSON(jsoncreate_invites_body_settings_1);
	cJSON* jsoncreate_invites_body_settings_2 = create_invites_body_settings_convertToJSON(create_invites_body_settings_2);
	printf("repeating create_invites_body_settings:\n%s\n", cJSON_Print(jsoncreate_invites_body_settings_2));
}

int main() {
  test_create_invites_body_settings(1);
  test_create_invites_body_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_invites_body_settings_MAIN
#endif // create_invites_body_settings_TEST
