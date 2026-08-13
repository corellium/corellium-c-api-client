#ifndef set_domain_welcome_message_body_TEST
#define set_domain_welcome_message_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_domain_welcome_message_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_domain_welcome_message_body.h"
set_domain_welcome_message_body_t* instantiate_set_domain_welcome_message_body(int include_optional);



set_domain_welcome_message_body_t* instantiate_set_domain_welcome_message_body(int include_optional) {
  set_domain_welcome_message_body_t* set_domain_welcome_message_body = NULL;
  if (include_optional) {
    set_domain_welcome_message_body = set_domain_welcome_message_body_create(
      "0",
      1
    );
  } else {
    set_domain_welcome_message_body = set_domain_welcome_message_body_create(
      "0",
      1
    );
  }

  return set_domain_welcome_message_body;
}


#ifdef set_domain_welcome_message_body_MAIN

void test_set_domain_welcome_message_body(int include_optional) {
    set_domain_welcome_message_body_t* set_domain_welcome_message_body_1 = instantiate_set_domain_welcome_message_body(include_optional);

	cJSON* jsonset_domain_welcome_message_body_1 = set_domain_welcome_message_body_convertToJSON(set_domain_welcome_message_body_1);
	printf("set_domain_welcome_message_body :\n%s\n", cJSON_Print(jsonset_domain_welcome_message_body_1));
	set_domain_welcome_message_body_t* set_domain_welcome_message_body_2 = set_domain_welcome_message_body_parseFromJSON(jsonset_domain_welcome_message_body_1);
	cJSON* jsonset_domain_welcome_message_body_2 = set_domain_welcome_message_body_convertToJSON(set_domain_welcome_message_body_2);
	printf("repeating set_domain_welcome_message_body:\n%s\n", cJSON_Print(jsonset_domain_welcome_message_body_2));
}

int main() {
  test_set_domain_welcome_message_body(1);
  test_set_domain_welcome_message_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_domain_welcome_message_body_MAIN
#endif // set_domain_welcome_message_body_TEST
