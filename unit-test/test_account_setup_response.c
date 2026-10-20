#ifndef account_setup_response_TEST
#define account_setup_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define account_setup_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/account_setup_response.h"
account_setup_response_t* instantiate_account_setup_response(int include_optional);



account_setup_response_t* instantiate_account_setup_response(int include_optional) {
  account_setup_response_t* account_setup_response = NULL;
  if (include_optional) {
    account_setup_response = account_setup_response_create(
      true
    );
  } else {
    account_setup_response = account_setup_response_create(
      true
    );
  }

  return account_setup_response;
}


#ifdef account_setup_response_MAIN

void test_account_setup_response(int include_optional) {
    account_setup_response_t* account_setup_response_1 = instantiate_account_setup_response(include_optional);

	cJSON* jsonaccount_setup_response_1 = account_setup_response_convertToJSON(account_setup_response_1);
	printf("account_setup_response :\n%s\n", cJSON_Print(jsonaccount_setup_response_1));
	account_setup_response_t* account_setup_response_2 = account_setup_response_parseFromJSON(jsonaccount_setup_response_1);
	cJSON* jsonaccount_setup_response_2 = account_setup_response_convertToJSON(account_setup_response_2);
	printf("repeating account_setup_response:\n%s\n", cJSON_Print(jsonaccount_setup_response_2));
}

int main() {
  test_account_setup_response(1);
  test_account_setup_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // account_setup_response_MAIN
#endif // account_setup_response_TEST
