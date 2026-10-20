#ifndef create_project_body_settings_TEST
#define create_project_body_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_project_body_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_project_body_settings.h"
create_project_body_settings_t* instantiate_create_project_body_settings(int include_optional);



create_project_body_settings_t* instantiate_create_project_body_settings(int include_optional) {
  create_project_body_settings_t* create_project_body_settings = NULL;
  if (include_optional) {
    create_project_body_settings = create_project_body_settings_create(
      1,
      true,
      true,
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7"
    );
  } else {
    create_project_body_settings = create_project_body_settings_create(
      1,
      true,
      true,
      "0eb5d1e7-2c10-42b1-95fc-30e4e4885cd7"
    );
  }

  return create_project_body_settings;
}


#ifdef create_project_body_settings_MAIN

void test_create_project_body_settings(int include_optional) {
    create_project_body_settings_t* create_project_body_settings_1 = instantiate_create_project_body_settings(include_optional);

	cJSON* jsoncreate_project_body_settings_1 = create_project_body_settings_convertToJSON(create_project_body_settings_1);
	printf("create_project_body_settings :\n%s\n", cJSON_Print(jsoncreate_project_body_settings_1));
	create_project_body_settings_t* create_project_body_settings_2 = create_project_body_settings_parseFromJSON(jsoncreate_project_body_settings_1);
	cJSON* jsoncreate_project_body_settings_2 = create_project_body_settings_convertToJSON(create_project_body_settings_2);
	printf("repeating create_project_body_settings:\n%s\n", cJSON_Print(jsoncreate_project_body_settings_2));
}

int main() {
  test_create_project_body_settings(1);
  test_create_project_body_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_project_body_settings_MAIN
#endif // create_project_body_settings_TEST
