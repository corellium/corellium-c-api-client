#ifndef domain_list_item_projects_inner_quotas_TEST
#define domain_list_item_projects_inner_quotas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_projects_inner_quotas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_projects_inner_quotas.h"
domain_list_item_projects_inner_quotas_t* instantiate_domain_list_item_projects_inner_quotas(int include_optional);



domain_list_item_projects_inner_quotas_t* instantiate_domain_list_item_projects_inner_quotas(int include_optional) {
  domain_list_item_projects_inner_quotas_t* domain_list_item_projects_inner_quotas = NULL;
  if (include_optional) {
    domain_list_item_projects_inner_quotas = domain_list_item_projects_inner_quotas_create(
      12,
      30,
      73728
    );
  } else {
    domain_list_item_projects_inner_quotas = domain_list_item_projects_inner_quotas_create(
      12,
      30,
      73728
    );
  }

  return domain_list_item_projects_inner_quotas;
}


#ifdef domain_list_item_projects_inner_quotas_MAIN

void test_domain_list_item_projects_inner_quotas(int include_optional) {
    domain_list_item_projects_inner_quotas_t* domain_list_item_projects_inner_quotas_1 = instantiate_domain_list_item_projects_inner_quotas(include_optional);

	cJSON* jsondomain_list_item_projects_inner_quotas_1 = domain_list_item_projects_inner_quotas_convertToJSON(domain_list_item_projects_inner_quotas_1);
	printf("domain_list_item_projects_inner_quotas :\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_quotas_1));
	domain_list_item_projects_inner_quotas_t* domain_list_item_projects_inner_quotas_2 = domain_list_item_projects_inner_quotas_parseFromJSON(jsondomain_list_item_projects_inner_quotas_1);
	cJSON* jsondomain_list_item_projects_inner_quotas_2 = domain_list_item_projects_inner_quotas_convertToJSON(domain_list_item_projects_inner_quotas_2);
	printf("repeating domain_list_item_projects_inner_quotas:\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_quotas_2));
}

int main() {
  test_domain_list_item_projects_inner_quotas(1);
  test_domain_list_item_projects_inner_quotas(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_projects_inner_quotas_MAIN
#endif // domain_list_item_projects_inner_quotas_TEST
