#ifndef domain_list_TEST
#define domain_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_list.h"
domain_list_t* instantiate_domain_list(int include_optional);

#include "test_domain_list_usage.c"


domain_list_t* instantiate_domain_list(int include_optional) {
  domain_list_t* domain_list = NULL;
  if (include_optional) {
    domain_list = domain_list_create(
      56,
      56,
      56,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_domain_list_usage(0)
    );
  } else {
    domain_list = domain_list_create(
      56,
      56,
      56,
      list_createList(),
      NULL
    );
  }

  return domain_list;
}


#ifdef domain_list_MAIN

void test_domain_list(int include_optional) {
    domain_list_t* domain_list_1 = instantiate_domain_list(include_optional);

	cJSON* jsondomain_list_1 = domain_list_convertToJSON(domain_list_1);
	printf("domain_list :\n%s\n", cJSON_Print(jsondomain_list_1));
	domain_list_t* domain_list_2 = domain_list_parseFromJSON(jsondomain_list_1);
	cJSON* jsondomain_list_2 = domain_list_convertToJSON(domain_list_2);
	printf("repeating domain_list:\n%s\n", cJSON_Print(jsondomain_list_2));
}

int main() {
  test_domain_list(1);
  test_domain_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_list_MAIN
#endif // domain_list_TEST
