#ifndef domain_info_domain_info_TEST
#define domain_info_domain_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_info_domain_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_info_domain_info.h"
domain_info_domain_info_t* instantiate_domain_info_domain_info(int include_optional);

#include "test_domain_list_item_disabled.c"
#include "test_domain_config.c"
#include "test_domain_list_item_quotas.c"
#include "test_domain_list_item_usage.c"
#include "test_domain_list_item_subscription.c"


domain_info_domain_info_t* instantiate_domain_info_domain_info(int include_optional) {
  domain_info_domain_info_t* domain_info_domain_info = NULL;
  if (include_optional) {
    domain_info_domain_info = domain_info_domain_info_create(
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      list_createList(),
      2,
      list_createList(),
      "acme.corellium.com",
      "acme",
       // false, not to have infinite recursion
      instantiate_domain_list_item_disabled(0),
       // false, not to have infinite recursion
      instantiate_domain_config(0),
       // false, not to have infinite recursion
      instantiate_domain_list_item_quotas(0),
       // false, not to have infinite recursion
      instantiate_domain_list_item_usage(0),
      1773479567000,
       // false, not to have infinite recursion
      instantiate_domain_list_item_subscription(0),
      list_createList(),
      "Enterprise Annual",
      list_createList()
    );
  } else {
    domain_info_domain_info = domain_info_domain_info_create(
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      list_createList(),
      2,
      list_createList(),
      "acme.corellium.com",
      "acme",
      NULL,
      NULL,
      NULL,
      NULL,
      1773479567000,
      NULL,
      list_createList(),
      "Enterprise Annual",
      list_createList()
    );
  }

  return domain_info_domain_info;
}


#ifdef domain_info_domain_info_MAIN

void test_domain_info_domain_info(int include_optional) {
    domain_info_domain_info_t* domain_info_domain_info_1 = instantiate_domain_info_domain_info(include_optional);

	cJSON* jsondomain_info_domain_info_1 = domain_info_domain_info_convertToJSON(domain_info_domain_info_1);
	printf("domain_info_domain_info :\n%s\n", cJSON_Print(jsondomain_info_domain_info_1));
	domain_info_domain_info_t* domain_info_domain_info_2 = domain_info_domain_info_parseFromJSON(jsondomain_info_domain_info_1);
	cJSON* jsondomain_info_domain_info_2 = domain_info_domain_info_convertToJSON(domain_info_domain_info_2);
	printf("repeating domain_info_domain_info:\n%s\n", cJSON_Print(jsondomain_info_domain_info_2));
}

int main() {
  test_domain_info_domain_info(1);
  test_domain_info_domain_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_info_domain_info_MAIN
#endif // domain_info_domain_info_TEST
