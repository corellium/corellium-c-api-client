#ifndef domain_list_item_projects_inner_instances_inner_images_inner_TEST
#define domain_list_item_projects_inner_instances_inner_images_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_item_projects_inner_instances_inner_images_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list_item_projects_inner_instances_inner_images_inner.h"
domain_list_item_projects_inner_instances_inner_images_inner_t* instantiate_domain_list_item_projects_inner_instances_inner_images_inner(int include_optional);



domain_list_item_projects_inner_instances_inner_images_inner_t* instantiate_domain_list_item_projects_inner_instances_inner_images_inner(int include_optional) {
  domain_list_item_projects_inner_instances_inner_images_inner_t* domain_list_item_projects_inner_instances_inner_images_inner = NULL;
  if (include_optional) {
    domain_list_item_projects_inner_instances_inner_images_inner = domain_list_item_projects_inner_instances_inner_images_inner_create(
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "fw",
      "iPhone_16.5_20F66_Restore.ipsw",
      239380613
    );
  } else {
    domain_list_item_projects_inner_instances_inner_images_inner = domain_list_item_projects_inner_instances_inner_images_inner_create(
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "fw",
      "iPhone_16.5_20F66_Restore.ipsw",
      239380613
    );
  }

  return domain_list_item_projects_inner_instances_inner_images_inner;
}


#ifdef domain_list_item_projects_inner_instances_inner_images_inner_MAIN

void test_domain_list_item_projects_inner_instances_inner_images_inner(int include_optional) {
    domain_list_item_projects_inner_instances_inner_images_inner_t* domain_list_item_projects_inner_instances_inner_images_inner_1 = instantiate_domain_list_item_projects_inner_instances_inner_images_inner(include_optional);

	cJSON* jsondomain_list_item_projects_inner_instances_inner_images_inner_1 = domain_list_item_projects_inner_instances_inner_images_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_images_inner_1);
	printf("domain_list_item_projects_inner_instances_inner_images_inner :\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_instances_inner_images_inner_1));
	domain_list_item_projects_inner_instances_inner_images_inner_t* domain_list_item_projects_inner_instances_inner_images_inner_2 = domain_list_item_projects_inner_instances_inner_images_inner_parseFromJSON(jsondomain_list_item_projects_inner_instances_inner_images_inner_1);
	cJSON* jsondomain_list_item_projects_inner_instances_inner_images_inner_2 = domain_list_item_projects_inner_instances_inner_images_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_images_inner_2);
	printf("repeating domain_list_item_projects_inner_instances_inner_images_inner:\n%s\n", cJSON_Print(jsondomain_list_item_projects_inner_instances_inner_images_inner_2));
}

int main() {
  test_domain_list_item_projects_inner_instances_inner_images_inner(1);
  test_domain_list_item_projects_inner_instances_inner_images_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_item_projects_inner_instances_inner_images_inner_MAIN
#endif // domain_list_item_projects_inner_instances_inner_images_inner_TEST
