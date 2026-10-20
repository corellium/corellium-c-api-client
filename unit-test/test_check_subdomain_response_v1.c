#ifndef check_subdomain_response_v1_TEST
#define check_subdomain_response_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define check_subdomain_response_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/check_subdomain_response_v1.h"
check_subdomain_response_v1_t* instantiate_check_subdomain_response_v1(int include_optional);



check_subdomain_response_v1_t* instantiate_check_subdomain_response_v1(int include_optional) {
  check_subdomain_response_v1_t* check_subdomain_response_v1 = NULL;
  if (include_optional) {
    check_subdomain_response_v1 = check_subdomain_response_v1_create(
      1
    );
  } else {
    check_subdomain_response_v1 = check_subdomain_response_v1_create(
      1
    );
  }

  return check_subdomain_response_v1;
}


#ifdef check_subdomain_response_v1_MAIN

void test_check_subdomain_response_v1(int include_optional) {
    check_subdomain_response_v1_t* check_subdomain_response_v1_1 = instantiate_check_subdomain_response_v1(include_optional);

	cJSON* jsoncheck_subdomain_response_v1_1 = check_subdomain_response_v1_convertToJSON(check_subdomain_response_v1_1);
	printf("check_subdomain_response_v1 :\n%s\n", cJSON_Print(jsoncheck_subdomain_response_v1_1));
	check_subdomain_response_v1_t* check_subdomain_response_v1_2 = check_subdomain_response_v1_parseFromJSON(jsoncheck_subdomain_response_v1_1);
	cJSON* jsoncheck_subdomain_response_v1_2 = check_subdomain_response_v1_convertToJSON(check_subdomain_response_v1_2);
	printf("repeating check_subdomain_response_v1:\n%s\n", cJSON_Print(jsoncheck_subdomain_response_v1_2));
}

int main() {
  test_check_subdomain_response_v1(1);
  test_check_subdomain_response_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // check_subdomain_response_v1_MAIN
#endif // check_subdomain_response_v1_TEST
