#ifndef totp_status_response_domain_TEST
#define totp_status_response_domain_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_status_response_domain_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_status_response_domain.h"
totp_status_response_domain_t* instantiate_totp_status_response_domain(int include_optional);



totp_status_response_domain_t* instantiate_totp_status_response_domain(int include_optional) {
  totp_status_response_domain_t* totp_status_response_domain = NULL;
  if (include_optional) {
    totp_status_response_domain = totp_status_response_domain_create(
      "acme-corp",
      "Acme Corp"
    );
  } else {
    totp_status_response_domain = totp_status_response_domain_create(
      "acme-corp",
      "Acme Corp"
    );
  }

  return totp_status_response_domain;
}


#ifdef totp_status_response_domain_MAIN

void test_totp_status_response_domain(int include_optional) {
    totp_status_response_domain_t* totp_status_response_domain_1 = instantiate_totp_status_response_domain(include_optional);

	cJSON* jsontotp_status_response_domain_1 = totp_status_response_domain_convertToJSON(totp_status_response_domain_1);
	printf("totp_status_response_domain :\n%s\n", cJSON_Print(jsontotp_status_response_domain_1));
	totp_status_response_domain_t* totp_status_response_domain_2 = totp_status_response_domain_parseFromJSON(jsontotp_status_response_domain_1);
	cJSON* jsontotp_status_response_domain_2 = totp_status_response_domain_convertToJSON(totp_status_response_domain_2);
	printf("repeating totp_status_response_domain:\n%s\n", cJSON_Print(jsontotp_status_response_domain_2));
}

int main() {
  test_totp_status_response_domain(1);
  test_totp_status_response_domain(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_status_response_domain_MAIN
#endif // totp_status_response_domain_TEST
