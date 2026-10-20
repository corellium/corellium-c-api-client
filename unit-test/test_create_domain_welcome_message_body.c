#ifndef create_domain_welcome_message_body_TEST
#define create_domain_welcome_message_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_domain_welcome_message_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_domain_welcome_message_body.h"
create_domain_welcome_message_body_t* instantiate_create_domain_welcome_message_body(int include_optional);



create_domain_welcome_message_body_t* instantiate_create_domain_welcome_message_body(int include_optional) {
  create_domain_welcome_message_body_t* create_domain_welcome_message_body = NULL;
  if (include_optional) {
    create_domain_welcome_message_body = create_domain_welcome_message_body_create(
      "0",
      1
    );
  } else {
    create_domain_welcome_message_body = create_domain_welcome_message_body_create(
      "0",
      1
    );
  }

  return create_domain_welcome_message_body;
}


#ifdef create_domain_welcome_message_body_MAIN

void test_create_domain_welcome_message_body(int include_optional) {
    create_domain_welcome_message_body_t* create_domain_welcome_message_body_1 = instantiate_create_domain_welcome_message_body(include_optional);

	cJSON* jsoncreate_domain_welcome_message_body_1 = create_domain_welcome_message_body_convertToJSON(create_domain_welcome_message_body_1);
	printf("create_domain_welcome_message_body :\n%s\n", cJSON_Print(jsoncreate_domain_welcome_message_body_1));
	create_domain_welcome_message_body_t* create_domain_welcome_message_body_2 = create_domain_welcome_message_body_parseFromJSON(jsoncreate_domain_welcome_message_body_1);
	cJSON* jsoncreate_domain_welcome_message_body_2 = create_domain_welcome_message_body_convertToJSON(create_domain_welcome_message_body_2);
	printf("repeating create_domain_welcome_message_body:\n%s\n", cJSON_Print(jsoncreate_domain_welcome_message_body_2));
}

int main() {
  test_create_domain_welcome_message_body(1);
  test_create_domain_welcome_message_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_domain_welcome_message_body_MAIN
#endif // create_domain_welcome_message_body_TEST
