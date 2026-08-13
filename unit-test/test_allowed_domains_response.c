#ifndef allowed_domains_response_TEST
#define allowed_domains_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define allowed_domains_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/allowed_domains_response.h"
allowed_domains_response_t* instantiate_allowed_domains_response(int include_optional);



allowed_domains_response_t* instantiate_allowed_domains_response(int include_optional) {
  allowed_domains_response_t* allowed_domains_response = NULL;
  if (include_optional) {
    allowed_domains_response = allowed_domains_response_create(
      list_createList()
    );
  } else {
    allowed_domains_response = allowed_domains_response_create(
      list_createList()
    );
  }

  return allowed_domains_response;
}


#ifdef allowed_domains_response_MAIN

void test_allowed_domains_response(int include_optional) {
    allowed_domains_response_t* allowed_domains_response_1 = instantiate_allowed_domains_response(include_optional);

	cJSON* jsonallowed_domains_response_1 = allowed_domains_response_convertToJSON(allowed_domains_response_1);
	printf("allowed_domains_response :\n%s\n", cJSON_Print(jsonallowed_domains_response_1));
	allowed_domains_response_t* allowed_domains_response_2 = allowed_domains_response_parseFromJSON(jsonallowed_domains_response_1);
	cJSON* jsonallowed_domains_response_2 = allowed_domains_response_convertToJSON(allowed_domains_response_2);
	printf("repeating allowed_domains_response:\n%s\n", cJSON_Print(jsonallowed_domains_response_2));
}

int main() {
  test_allowed_domains_response(1);
  test_allowed_domains_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // allowed_domains_response_MAIN
#endif // allowed_domains_response_TEST
