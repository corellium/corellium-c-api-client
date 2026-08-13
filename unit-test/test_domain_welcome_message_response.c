#ifndef domain_welcome_message_response_TEST
#define domain_welcome_message_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_welcome_message_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_welcome_message_response.h"
domain_welcome_message_response_t* instantiate_domain_welcome_message_response(int include_optional);



domain_welcome_message_response_t* instantiate_domain_welcome_message_response(int include_optional) {
  domain_welcome_message_response_t* domain_welcome_message_response = NULL;
  if (include_optional) {
    domain_welcome_message_response = domain_welcome_message_response_create(
      "0",
      "0",
      "0",
      1,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    domain_welcome_message_response = domain_welcome_message_response_create(
      "0",
      "0",
      "0",
      1,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return domain_welcome_message_response;
}


#ifdef domain_welcome_message_response_MAIN

void test_domain_welcome_message_response(int include_optional) {
    domain_welcome_message_response_t* domain_welcome_message_response_1 = instantiate_domain_welcome_message_response(include_optional);

	cJSON* jsondomain_welcome_message_response_1 = domain_welcome_message_response_convertToJSON(domain_welcome_message_response_1);
	printf("domain_welcome_message_response :\n%s\n", cJSON_Print(jsondomain_welcome_message_response_1));
	domain_welcome_message_response_t* domain_welcome_message_response_2 = domain_welcome_message_response_parseFromJSON(jsondomain_welcome_message_response_1);
	cJSON* jsondomain_welcome_message_response_2 = domain_welcome_message_response_convertToJSON(domain_welcome_message_response_2);
	printf("repeating domain_welcome_message_response:\n%s\n", cJSON_Print(jsondomain_welcome_message_response_2));
}

int main() {
  test_domain_welcome_message_response(1);
  test_domain_welcome_message_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_welcome_message_response_MAIN
#endif // domain_welcome_message_response_TEST
