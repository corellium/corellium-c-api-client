#ifndef domain_list_item_subscription_TEST
#define domain_list_item_subscription_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_subscription_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_subscription.h"
domain_list_item_subscription_t* instantiate_domain_list_item_subscription(int include_optional);



domain_list_item_subscription_t* instantiate_domain_list_item_subscription(int include_optional) {
  domain_list_item_subscription_t* domain_list_item_subscription = NULL;
  if (include_optional) {
    domain_list_item_subscription = domain_list_item_subscription_create(
      0,
      "0",
      corellium_api_domain_list_item_subscription_BILLINGTYPE_prepaid,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      1,
      "2013-10-20T19:20:30+01:00",
      1.337,
      1.337,
      1.337,
      1,
      1.337,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    domain_list_item_subscription = domain_list_item_subscription_create(
      0,
      "0",
      corellium_api_domain_list_item_subscription_BILLINGTYPE_prepaid,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      1,
      "2013-10-20T19:20:30+01:00",
      1.337,
      1.337,
      1.337,
      1,
      1.337,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return domain_list_item_subscription;
}


#ifdef domain_list_item_subscription_MAIN

void test_domain_list_item_subscription(int include_optional) {
    domain_list_item_subscription_t* domain_list_item_subscription_1 = instantiate_domain_list_item_subscription(include_optional);

	cJSON* jsondomain_list_item_subscription_1 = domain_list_item_subscription_convertToJSON(domain_list_item_subscription_1);
	printf("domain_list_item_subscription :\n%s\n", cJSON_Print(jsondomain_list_item_subscription_1));
	domain_list_item_subscription_t* domain_list_item_subscription_2 = domain_list_item_subscription_parseFromJSON(jsondomain_list_item_subscription_1);
	cJSON* jsondomain_list_item_subscription_2 = domain_list_item_subscription_convertToJSON(domain_list_item_subscription_2);
	printf("repeating domain_list_item_subscription:\n%s\n", cJSON_Print(jsondomain_list_item_subscription_2));
}

int main() {
  test_domain_list_item_subscription(1);
  test_domain_list_item_subscription(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_subscription_MAIN
#endif // domain_list_item_subscription_TEST
