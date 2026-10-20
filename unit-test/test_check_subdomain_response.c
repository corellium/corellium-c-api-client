#ifndef check_subdomain_response_TEST
#define check_subdomain_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define check_subdomain_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/check_subdomain_response.h"
check_subdomain_response_t* instantiate_check_subdomain_response(int include_optional);



check_subdomain_response_t* instantiate_check_subdomain_response(int include_optional) {
  check_subdomain_response_t* check_subdomain_response = NULL;
  if (include_optional) {
    check_subdomain_response = check_subdomain_response_create(
      true
    );
  } else {
    check_subdomain_response = check_subdomain_response_create(
      true
    );
  }

  return check_subdomain_response;
}


#ifdef check_subdomain_response_MAIN

void test_check_subdomain_response(int include_optional) {
    check_subdomain_response_t* check_subdomain_response_1 = instantiate_check_subdomain_response(include_optional);

	cJSON* jsoncheck_subdomain_response_1 = check_subdomain_response_convertToJSON(check_subdomain_response_1);
	printf("check_subdomain_response :\n%s\n", cJSON_Print(jsoncheck_subdomain_response_1));
	check_subdomain_response_t* check_subdomain_response_2 = check_subdomain_response_parseFromJSON(jsoncheck_subdomain_response_1);
	cJSON* jsoncheck_subdomain_response_2 = check_subdomain_response_convertToJSON(check_subdomain_response_2);
	printf("repeating check_subdomain_response:\n%s\n", cJSON_Print(jsoncheck_subdomain_response_2));
}

int main() {
  test_check_subdomain_response(1);
  test_check_subdomain_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // check_subdomain_response_MAIN
#endif // check_subdomain_response_TEST
