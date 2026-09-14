#ifndef create_domain_auth_provider_body_TEST
#define create_domain_auth_provider_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_domain_auth_provider_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_domain_auth_provider_body.h"
create_domain_auth_provider_body_t* instantiate_create_domain_auth_provider_body(int include_optional);

#include "test_domain_auth_provider_config.c"


create_domain_auth_provider_body_t* instantiate_create_domain_auth_provider_body(int include_optional) {
  create_domain_auth_provider_body_t* create_domain_auth_provider_body = NULL;
  if (include_optional) {
    create_domain_auth_provider_body = create_domain_auth_provider_body_create(
      "0",
      1,
      "0",
      null
    );
  } else {
    create_domain_auth_provider_body = create_domain_auth_provider_body_create(
      "0",
      1,
      "0",
      null
    );
  }

  return create_domain_auth_provider_body;
}


#ifdef create_domain_auth_provider_body_MAIN

void test_create_domain_auth_provider_body(int include_optional) {
    create_domain_auth_provider_body_t* create_domain_auth_provider_body_1 = instantiate_create_domain_auth_provider_body(include_optional);

	cJSON* jsoncreate_domain_auth_provider_body_1 = create_domain_auth_provider_body_convertToJSON(create_domain_auth_provider_body_1);
	printf("create_domain_auth_provider_body :\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_body_1));
	create_domain_auth_provider_body_t* create_domain_auth_provider_body_2 = create_domain_auth_provider_body_parseFromJSON(jsoncreate_domain_auth_provider_body_1);
	cJSON* jsoncreate_domain_auth_provider_body_2 = create_domain_auth_provider_body_convertToJSON(create_domain_auth_provider_body_2);
	printf("repeating create_domain_auth_provider_body:\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_body_2));
}

int main() {
  test_create_domain_auth_provider_body(1);
  test_create_domain_auth_provider_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_domain_auth_provider_body_MAIN
#endif // create_domain_auth_provider_body_TEST
