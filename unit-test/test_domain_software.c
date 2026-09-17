#ifndef domain_software_TEST
#define domain_software_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_software_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_software.h"
domain_software_t* instantiate_domain_software(int include_optional);



domain_software_t* instantiate_domain_software(int include_optional) {
  domain_software_t* domain_software = NULL;
  if (include_optional) {
    domain_software = domain_software_create(
      "0",
      "iphone17a",
      "iPhone Air",
      "iPhone18,4",
      "0",
      1,
      "0",
      "0",
      "0",
      1.337,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  } else {
    domain_software = domain_software_create(
      "0",
      "iphone17a",
      "iPhone Air",
      "iPhone18,4",
      "0",
      1,
      "0",
      "0",
      "0",
      1.337,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  }

  return domain_software;
}


#ifdef domain_software_MAIN

void test_domain_software(int include_optional) {
    domain_software_t* domain_software_1 = instantiate_domain_software(include_optional);

	cJSON* jsondomain_software_1 = domain_software_convertToJSON(domain_software_1);
	printf("domain_software :\n%s\n", cJSON_Print(jsondomain_software_1));
	domain_software_t* domain_software_2 = domain_software_parseFromJSON(jsondomain_software_1);
	cJSON* jsondomain_software_2 = domain_software_convertToJSON(domain_software_2);
	printf("repeating domain_software:\n%s\n", cJSON_Print(jsondomain_software_2));
}

int main() {
  test_domain_software(1);
  test_domain_software(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_software_MAIN
#endif // domain_software_TEST
