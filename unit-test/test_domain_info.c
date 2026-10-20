#ifndef domain_info_TEST
#define domain_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_info.h"
domain_info_t* instantiate_domain_info(int include_optional);

#include "test_domain_info_domain_info.c"


domain_info_t* instantiate_domain_info(int include_optional) {
  domain_info_t* domain_info = NULL;
  if (include_optional) {
    domain_info = domain_info_create(
      null
    );
  } else {
    domain_info = domain_info_create(
      null
    );
  }

  return domain_info;
}


#ifdef domain_info_MAIN

void test_domain_info(int include_optional) {
    domain_info_t* domain_info_1 = instantiate_domain_info(include_optional);

	cJSON* jsondomain_info_1 = domain_info_convertToJSON(domain_info_1);
	printf("domain_info :\n%s\n", cJSON_Print(jsondomain_info_1));
	domain_info_t* domain_info_2 = domain_info_parseFromJSON(jsondomain_info_1);
	cJSON* jsondomain_info_2 = domain_info_convertToJSON(domain_info_2);
	printf("repeating domain_info:\n%s\n", cJSON_Print(jsondomain_info_2));
}

int main() {
  test_domain_info(1);
  test_domain_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_info_MAIN
#endif // domain_info_TEST
