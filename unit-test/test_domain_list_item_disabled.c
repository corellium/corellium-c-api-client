#ifndef domain_list_item_disabled_TEST
#define domain_list_item_disabled_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_disabled_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_disabled.h"
domain_list_item_disabled_t* instantiate_domain_list_item_disabled(int include_optional);



domain_list_item_disabled_t* instantiate_domain_list_item_disabled(int include_optional) {
  domain_list_item_disabled_t* domain_list_item_disabled = NULL;
  if (include_optional) {
    domain_list_item_disabled = domain_list_item_disabled_create(
      corellium_api_domain_list_item_disabled_TYPE_SubscriptionCanceled
    );
  } else {
    domain_list_item_disabled = domain_list_item_disabled_create(
      corellium_api_domain_list_item_disabled_TYPE_SubscriptionCanceled
    );
  }

  return domain_list_item_disabled;
}


#ifdef domain_list_item_disabled_MAIN

void test_domain_list_item_disabled(int include_optional) {
    domain_list_item_disabled_t* domain_list_item_disabled_1 = instantiate_domain_list_item_disabled(include_optional);

	cJSON* jsondomain_list_item_disabled_1 = domain_list_item_disabled_convertToJSON(domain_list_item_disabled_1);
	printf("domain_list_item_disabled :\n%s\n", cJSON_Print(jsondomain_list_item_disabled_1));
	domain_list_item_disabled_t* domain_list_item_disabled_2 = domain_list_item_disabled_parseFromJSON(jsondomain_list_item_disabled_1);
	cJSON* jsondomain_list_item_disabled_2 = domain_list_item_disabled_convertToJSON(domain_list_item_disabled_2);
	printf("repeating domain_list_item_disabled:\n%s\n", cJSON_Print(jsondomain_list_item_disabled_2));
}

int main() {
  test_domain_list_item_disabled(1);
  test_domain_list_item_disabled(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_disabled_MAIN
#endif // domain_list_item_disabled_TEST
