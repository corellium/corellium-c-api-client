#ifndef domain_list_item_users_info_inner_TEST
#define domain_list_item_users_info_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_users_info_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_users_info_inner.h"
domain_list_item_users_info_inner_t* instantiate_domain_list_item_users_info_inner(int include_optional);



domain_list_item_users_info_inner_t* instantiate_domain_list_item_users_info_inner(int include_optional) {
  domain_list_item_users_info_inner_t* domain_list_item_users_info_inner = NULL;
  if (include_optional) {
    domain_list_item_users_info_inner = domain_list_item_users_info_inner_create(
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      "2013-10-20T19:20:30+01:00",
      56
    );
  } else {
    domain_list_item_users_info_inner = domain_list_item_users_info_inner_create(
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      "2013-10-20T19:20:30+01:00",
      56
    );
  }

  return domain_list_item_users_info_inner;
}


#ifdef domain_list_item_users_info_inner_MAIN

void test_domain_list_item_users_info_inner(int include_optional) {
    domain_list_item_users_info_inner_t* domain_list_item_users_info_inner_1 = instantiate_domain_list_item_users_info_inner(include_optional);

	cJSON* jsondomain_list_item_users_info_inner_1 = domain_list_item_users_info_inner_convertToJSON(domain_list_item_users_info_inner_1);
	printf("domain_list_item_users_info_inner :\n%s\n", cJSON_Print(jsondomain_list_item_users_info_inner_1));
	domain_list_item_users_info_inner_t* domain_list_item_users_info_inner_2 = domain_list_item_users_info_inner_parseFromJSON(jsondomain_list_item_users_info_inner_1);
	cJSON* jsondomain_list_item_users_info_inner_2 = domain_list_item_users_info_inner_convertToJSON(domain_list_item_users_info_inner_2);
	printf("repeating domain_list_item_users_info_inner:\n%s\n", cJSON_Print(jsondomain_list_item_users_info_inner_2));
}

int main() {
  test_domain_list_item_users_info_inner(1);
  test_domain_list_item_users_info_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_users_info_inner_MAIN
#endif // domain_list_item_users_info_inner_TEST
