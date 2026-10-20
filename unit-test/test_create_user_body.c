#ifndef create_user_body_TEST
#define create_user_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_user_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_user_body.h"
create_user_body_t* instantiate_create_user_body(int include_optional);



create_user_body_t* instantiate_create_user_body(int include_optional) {
  create_user_body_t* create_user_body = NULL;
  if (include_optional) {
    create_user_body = create_user_body_create(
      "<redacted>",
      true,
      "jane.doe",
      "Domain Administrator",
      "jane.doe@example.com",
      false
    );
  } else {
    create_user_body = create_user_body_create(
      "<redacted>",
      true,
      "jane.doe",
      "Domain Administrator",
      "jane.doe@example.com",
      false
    );
  }

  return create_user_body;
}


#ifdef create_user_body_MAIN

void test_create_user_body(int include_optional) {
    create_user_body_t* create_user_body_1 = instantiate_create_user_body(include_optional);

	cJSON* jsoncreate_user_body_1 = create_user_body_convertToJSON(create_user_body_1);
	printf("create_user_body :\n%s\n", cJSON_Print(jsoncreate_user_body_1));
	create_user_body_t* create_user_body_2 = create_user_body_parseFromJSON(jsoncreate_user_body_1);
	cJSON* jsoncreate_user_body_2 = create_user_body_convertToJSON(create_user_body_2);
	printf("repeating create_user_body:\n%s\n", cJSON_Print(jsoncreate_user_body_2));
}

int main() {
  test_create_user_body(1);
  test_create_user_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_user_body_MAIN
#endif // create_user_body_TEST
