#ifndef domain_list_item_projects_inner_TEST
#define domain_list_item_projects_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_projects_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_projects_inner.h"
domain_list_item_projects_inner_t* instantiate_domain_list_item_projects_inner(int include_optional);

#include "test_domain_list_item_projects_inner_quotas.c"
#include "test_domain_list_item_projects_inner_usage.c"


domain_list_item_projects_inner_t* instantiate_domain_list_item_projects_inner(int include_optional) {
  domain_list_item_projects_inner_t* domain_list_item_projects_inner = NULL;
  if (include_optional) {
    domain_list_item_projects_inner = domain_list_item_projects_inner_create(
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "Default Project",
       // false, not to have infinite recursion
      instantiate_domain_list_item_projects_inner_quotas(0),
       // false, not to have infinite recursion
      instantiate_domain_list_item_projects_inner_usage(0),
      list_createList(),
      list_createList()
    );
  } else {
    domain_list_item_projects_inner = domain_list_item_projects_inner_create(
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "Default Project",
      NULL,
      NULL,
      list_createList(),
      list_createList()
    );
  }

  return domain_list_item_projects_inner;
}


#ifdef domain_list_item_projects_inner_MAIN

void test_domain_list_item_projects_inner(int include_optional) {
    domain_list_item_projects_inner_t* domain_list_item_projects_inner_1 = instantiate_domain_list_item_projects_inner(include_optional);

	cJSON* jsondomain_list_item_projects_inner_1 = domain_list_item_projects_inner_convertToJSON(domain_list_item_projects_inner_1);
	printf("domain_list_item_projects_inner :\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_1));
	domain_list_item_projects_inner_t* domain_list_item_projects_inner_2 = domain_list_item_projects_inner_parseFromJSON(jsondomain_list_item_projects_inner_1);
	cJSON* jsondomain_list_item_projects_inner_2 = domain_list_item_projects_inner_convertToJSON(domain_list_item_projects_inner_2);
	printf("repeating domain_list_item_projects_inner:\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_2));
}

int main() {
  test_domain_list_item_projects_inner(1);
  test_domain_list_item_projects_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_projects_inner_MAIN
#endif // domain_list_item_projects_inner_TEST
