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
      "b10bd74a-a906-46b9-a4f3-a45cccdc2576",
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "Welcome to Acme Corp! Get started by creating your first device.",
      true,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    domain_welcome_message_response = domain_welcome_message_response_create(
      "b10bd74a-a906-46b9-a4f3-a45cccdc2576",
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "Welcome to Acme Corp! Get started by creating your first device.",
      true,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
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
