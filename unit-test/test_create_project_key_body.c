#ifndef create_project_key_body_TEST
#define create_project_key_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_project_key_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_project_key_body.h"
create_project_key_body_t* instantiate_create_project_key_body(int include_optional);



create_project_key_body_t* instantiate_create_project_key_body(int include_optional) {
  create_project_key_body_t* create_project_key_body = NULL;
  if (include_optional) {
    create_project_key_body = create_project_key_body_create(
      corellium_api_create_project_key_body_KIND_ssh,
      "Build server key",
      "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIJUlGdieyRXdiVIyQjqthDE1YzmwzH0ZeZuHkBuC9Gwr user@example.com"
    );
  } else {
    create_project_key_body = create_project_key_body_create(
      corellium_api_create_project_key_body_KIND_ssh,
      "Build server key",
      "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIJUlGdieyRXdiVIyQjqthDE1YzmwzH0ZeZuHkBuC9Gwr user@example.com"
    );
  }

  return create_project_key_body;
}


#ifdef create_project_key_body_MAIN

void test_create_project_key_body(int include_optional) {
    create_project_key_body_t* create_project_key_body_1 = instantiate_create_project_key_body(include_optional);

	cJSON* jsoncreate_project_key_body_1 = create_project_key_body_convertToJSON(create_project_key_body_1);
	printf("create_project_key_body :\n%s\n", cJSON_Print(jsoncreate_project_key_body_1));
	create_project_key_body_t* create_project_key_body_2 = create_project_key_body_parseFromJSON(jsoncreate_project_key_body_1);
	cJSON* jsoncreate_project_key_body_2 = create_project_key_body_convertToJSON(create_project_key_body_2);
	printf("repeating create_project_key_body:\n%s\n", cJSON_Print(jsoncreate_project_key_body_2));
}

int main() {
  test_create_project_key_body(1);
  test_create_project_key_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_project_key_body_MAIN
#endif // create_project_key_body_TEST
