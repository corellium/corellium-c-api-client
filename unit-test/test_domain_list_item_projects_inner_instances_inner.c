#ifndef domain_list_item_projects_inner_instances_inner_TEST
#define domain_list_item_projects_inner_instances_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_projects_inner_instances_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_projects_inner_instances_inner.h"
domain_list_item_projects_inner_instances_inner_t* instantiate_domain_list_item_projects_inner_instances_inner(int include_optional);

#include "test_domain_list_item_projects_inner_instances_inner_usage.c"


domain_list_item_projects_inner_instances_inner_t* instantiate_domain_list_item_projects_inner_instances_inner(int include_optional) {
  domain_list_item_projects_inner_instances_inner_t* domain_list_item_projects_inner_instances_inner = NULL;
  if (include_optional) {
    domain_list_item_projects_inner_instances_inner = domain_list_item_projects_inner_instances_inner_create(
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "iPhone 6s Test Device",
      "ACTIVE",
      "Failed to allocate device slot.",
      "none",
      "reboot",
      "14.5.1",
      "18E212",
      "iphone6s",
      "iPhone 6s",
      "10.0.0.5:6666",
      "10.0.1.2",
      "10.0.2.2",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_domain_list_item_projects_inner_instances_inner_usage(0)
    );
  } else {
    domain_list_item_projects_inner_instances_inner = domain_list_item_projects_inner_instances_inner_create(
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "iPhone 6s Test Device",
      "ACTIVE",
      "Failed to allocate device slot.",
      "none",
      "reboot",
      "14.5.1",
      "18E212",
      "iphone6s",
      "iPhone 6s",
      "10.0.0.5:6666",
      "10.0.1.2",
      "10.0.2.2",
      list_createList(),
      NULL
    );
  }

  return domain_list_item_projects_inner_instances_inner;
}


#ifdef domain_list_item_projects_inner_instances_inner_MAIN

void test_domain_list_item_projects_inner_instances_inner(int include_optional) {
    domain_list_item_projects_inner_instances_inner_t* domain_list_item_projects_inner_instances_inner_1 = instantiate_domain_list_item_projects_inner_instances_inner(include_optional);

	cJSON* jsondomain_list_item_projects_inner_instances_inner_1 = domain_list_item_projects_inner_instances_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_1);
	printf("domain_list_item_projects_inner_instances_inner :\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_instances_inner_1));
	domain_list_item_projects_inner_instances_inner_t* domain_list_item_projects_inner_instances_inner_2 = domain_list_item_projects_inner_instances_inner_parseFromJSON(jsondomain_list_item_projects_inner_instances_inner_1);
	cJSON* jsondomain_list_item_projects_inner_instances_inner_2 = domain_list_item_projects_inner_instances_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_2);
	printf("repeating domain_list_item_projects_inner_instances_inner:\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_instances_inner_2));
}

int main() {
  test_domain_list_item_projects_inner_instances_inner(1);
  test_domain_list_item_projects_inner_instances_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_projects_inner_instances_inner_MAIN
#endif // domain_list_item_projects_inner_instances_inner_TEST
