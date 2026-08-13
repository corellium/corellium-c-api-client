#ifndef create_domain_auth_provider_response_config_TEST
#define create_domain_auth_provider_response_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_domain_auth_provider_response_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_domain_auth_provider_response_config.h"
create_domain_auth_provider_response_config_t* instantiate_create_domain_auth_provider_response_config(int include_optional);



create_domain_auth_provider_response_config_t* instantiate_create_domain_auth_provider_response_config(int include_optional) {
  create_domain_auth_provider_response_config_t* create_domain_auth_provider_response_config = NULL;
  if (include_optional) {
    create_domain_auth_provider_response_config = create_domain_auth_provider_response_config_create(
      "0",
      "0",
      "0",
      1
    );
  } else {
    create_domain_auth_provider_response_config = create_domain_auth_provider_response_config_create(
      "0",
      "0",
      "0",
      1
    );
  }

  return create_domain_auth_provider_response_config;
}


#ifdef create_domain_auth_provider_response_config_MAIN

void test_create_domain_auth_provider_response_config(int include_optional) {
    create_domain_auth_provider_response_config_t* create_domain_auth_provider_response_config_1 = instantiate_create_domain_auth_provider_response_config(include_optional);

	cJSON* jsoncreate_domain_auth_provider_response_config_1 = create_domain_auth_provider_response_config_convertToJSON(create_domain_auth_provider_response_config_1);
	printf("create_domain_auth_provider_response_config :\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_response_config_1));
	create_domain_auth_provider_response_config_t* create_domain_auth_provider_response_config_2 = create_domain_auth_provider_response_config_parseFromJSON(jsoncreate_domain_auth_provider_response_config_1);
	cJSON* jsoncreate_domain_auth_provider_response_config_2 = create_domain_auth_provider_response_config_convertToJSON(create_domain_auth_provider_response_config_2);
	printf("repeating create_domain_auth_provider_response_config:\n%s\n", cJSON_Print(jsoncreate_domain_auth_provider_response_config_2));
}

int main() {
  test_create_domain_auth_provider_response_config(1);
  test_create_domain_auth_provider_response_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_domain_auth_provider_response_config_MAIN
#endif // create_domain_auth_provider_response_config_TEST
