#ifndef domain_welcome_message_response_v1_TEST
#define domain_welcome_message_response_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_welcome_message_response_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_welcome_message_response_v1.h"
domain_welcome_message_response_v1_t* instantiate_domain_welcome_message_response_v1(int include_optional);



domain_welcome_message_response_v1_t* instantiate_domain_welcome_message_response_v1(int include_optional) {
  domain_welcome_message_response_v1_t* domain_welcome_message_response_v1 = NULL;
  if (include_optional) {
    domain_welcome_message_response_v1 = domain_welcome_message_response_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    domain_welcome_message_response_v1 = domain_welcome_message_response_v1_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return domain_welcome_message_response_v1;
}


#ifdef domain_welcome_message_response_v1_MAIN

void test_domain_welcome_message_response_v1(int include_optional) {
    domain_welcome_message_response_v1_t* domain_welcome_message_response_v1_1 = instantiate_domain_welcome_message_response_v1(include_optional);

	cJSON* jsondomain_welcome_message_response_v1_1 = domain_welcome_message_response_v1_convertToJSON(domain_welcome_message_response_v1_1);
	printf("domain_welcome_message_response_v1 :\n%s\n", cJSON_Print(jsondomain_welcome_message_response_v1_1));
	domain_welcome_message_response_v1_t* domain_welcome_message_response_v1_2 = domain_welcome_message_response_v1_parseFromJSON(jsondomain_welcome_message_response_v1_1);
	cJSON* jsondomain_welcome_message_response_v1_2 = domain_welcome_message_response_v1_convertToJSON(domain_welcome_message_response_v1_2);
	printf("repeating domain_welcome_message_response_v1:\n%s\n", cJSON_Print(jsondomain_welcome_message_response_v1_2));
}

int main() {
  test_domain_welcome_message_response_v1(1);
  test_domain_welcome_message_response_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_welcome_message_response_v1_MAIN
#endif // domain_welcome_message_response_v1_TEST
