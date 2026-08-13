#ifndef domain_list_item_subscription_history_inner_administrator_TEST
#define domain_list_item_subscription_history_inner_administrator_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_subscription_history_inner_administrator_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_subscription_history_inner_administrator.h"
domain_list_item_subscription_history_inner_administrator_t* instantiate_domain_list_item_subscription_history_inner_administrator(int include_optional);



domain_list_item_subscription_history_inner_administrator_t* instantiate_domain_list_item_subscription_history_inner_administrator(int include_optional) {
  domain_list_item_subscription_history_inner_administrator_t* domain_list_item_subscription_history_inner_administrator = NULL;
  if (include_optional) {
    domain_list_item_subscription_history_inner_administrator = domain_list_item_subscription_history_inner_administrator_create(
      "0",
      "0"
    );
  } else {
    domain_list_item_subscription_history_inner_administrator = domain_list_item_subscription_history_inner_administrator_create(
      "0",
      "0"
    );
  }

  return domain_list_item_subscription_history_inner_administrator;
}


#ifdef domain_list_item_subscription_history_inner_administrator_MAIN

void test_domain_list_item_subscription_history_inner_administrator(int include_optional) {
    domain_list_item_subscription_history_inner_administrator_t* domain_list_item_subscription_history_inner_administrator_1 = instantiate_domain_list_item_subscription_history_inner_administrator(include_optional);

	cJSON* jsondomain_list_item_subscription_history_inner_administrator_1 = domain_list_item_subscription_history_inner_administrator_convertToJSON(domain_list_item_subscription_history_inner_administrator_1);
	printf("domain_list_item_subscription_history_inner_administrator :\n%s\n", cJSON_Print(jsondomain_list_item_subscription_history_inner_administrator_1));
	domain_list_item_subscription_history_inner_administrator_t* domain_list_item_subscription_history_inner_administrator_2 = domain_list_item_subscription_history_inner_administrator_parseFromJSON(jsondomain_list_item_subscription_history_inner_administrator_1);
	cJSON* jsondomain_list_item_subscription_history_inner_administrator_2 = domain_list_item_subscription_history_inner_administrator_convertToJSON(domain_list_item_subscription_history_inner_administrator_2);
	printf("repeating domain_list_item_subscription_history_inner_administrator:\n%s\n", cJSON_Print(jsondomain_list_item_subscription_history_inner_administrator_2));
}

int main() {
  test_domain_list_item_subscription_history_inner_administrator(1);
  test_domain_list_item_subscription_history_inner_administrator(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_subscription_history_inner_administrator_MAIN
#endif // domain_list_item_subscription_history_inner_administrator_TEST
