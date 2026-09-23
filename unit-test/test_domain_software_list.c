#ifndef domain_software_list_TEST
#define domain_software_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_software_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_software_list.h"
domain_software_list_t* instantiate_domain_software_list(int include_optional);



domain_software_list_t* instantiate_domain_software_list(int include_optional) {
  domain_software_list_t* domain_software_list = NULL;
  if (include_optional) {
    domain_software_list = domain_software_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    domain_software_list = domain_software_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return domain_software_list;
}


#ifdef domain_software_list_MAIN

void test_domain_software_list(int include_optional) {
    domain_software_list_t* domain_software_list_1 = instantiate_domain_software_list(include_optional);

	cJSON* jsondomain_software_list_1 = domain_software_list_convertToJSON(domain_software_list_1);
	printf("domain_software_list :\n%s\n", cJSON_Print(jsondomain_software_list_1));
	domain_software_list_t* domain_software_list_2 = domain_software_list_parseFromJSON(jsondomain_software_list_1);
	cJSON* jsondomain_software_list_2 = domain_software_list_convertToJSON(domain_software_list_2);
	printf("repeating domain_software_list:\n%s\n", cJSON_Print(jsondomain_software_list_2));
}

int main() {
  test_domain_software_list(1);
  test_domain_software_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_software_list_MAIN
#endif // domain_software_list_TEST
