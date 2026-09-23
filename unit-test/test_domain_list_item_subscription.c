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
      {"action":"cancel"},
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      corellium_api_domain_list_item_subscription_BILLINGTYPE_prepaid,
      "stripe",
      "sub_1ExampleSubscriptionId",
      "2027-01-15T00:00Z",
      false,
      "2026-03-16T08:22:19Z",
      49900,
      7,
      5,
      false,
      1,
      "2026-03-16T08:22:19Z",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    domain_list_item_subscription = domain_list_item_subscription_create(
      {"action":"cancel"},
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      corellium_api_domain_list_item_subscription_BILLINGTYPE_prepaid,
      "stripe",
      "sub_1ExampleSubscriptionId",
      "2027-01-15T00:00Z",
      false,
      "2026-03-16T08:22:19Z",
      49900,
      7,
      5,
      false,
      1,
      "2026-03-16T08:22:19Z",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
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
