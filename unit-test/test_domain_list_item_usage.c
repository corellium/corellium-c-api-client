#ifndef domain_list_item_usage_TEST
#define domain_list_item_usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_usage.h"
domain_list_item_usage_t* instantiate_domain_list_item_usage(int include_optional);



domain_list_item_usage_t* instantiate_domain_list_item_usage(int include_optional) {
  domain_list_item_usage_t* domain_list_item_usage = NULL;
  if (include_optional) {
    domain_list_item_usage = domain_list_item_usage_create(
      56,
      1.337,
      56,
      56,
      56,
      56,
      56
    );
  } else {
    domain_list_item_usage = domain_list_item_usage_create(
      56,
      1.337,
      56,
      56,
      56,
      56,
      56
    );
  }

  return domain_list_item_usage;
}


#ifdef domain_list_item_usage_MAIN

void test_domain_list_item_usage(int include_optional) {
    domain_list_item_usage_t* domain_list_item_usage_1 = instantiate_domain_list_item_usage(include_optional);

	cJSON* jsondomain_list_item_usage_1 = domain_list_item_usage_convertToJSON(domain_list_item_usage_1);
	printf("domain_list_item_usage :\n%s\n", cJSON_Print(jsondomain_list_item_usage_1));
	domain_list_item_usage_t* domain_list_item_usage_2 = domain_list_item_usage_parseFromJSON(jsondomain_list_item_usage_1);
	cJSON* jsondomain_list_item_usage_2 = domain_list_item_usage_convertToJSON(domain_list_item_usage_2);
	printf("repeating domain_list_item_usage:\n%s\n", cJSON_Print(jsondomain_list_item_usage_2));
}

int main() {
  test_domain_list_item_usage(1);
  test_domain_list_item_usage(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_usage_MAIN
#endif // domain_list_item_usage_TEST
