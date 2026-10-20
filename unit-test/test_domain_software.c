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
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "iphone17a",
      "iPhone Air",
      "iPhone18,4",
      "t8101",
      true,
      "17.5",
      "21F79",
      "iPhone18,4_17.5_21F79_Restore.ipsw",
      7516192768,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "https://example.com/firmware/iPhone18,4_17.5_21F79_Restore.ipsw?signature=<signature>"
    );
  } else {
    domain_software = domain_software_create(
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "iphone17a",
      "iPhone Air",
      "iPhone18,4",
      "t8101",
      true,
      "17.5",
      "21F79",
      "iPhone18,4_17.5_21F79_Restore.ipsw",
      7516192768,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "https://example.com/firmware/iPhone18,4_17.5_21F79_Restore.ipsw?signature=<signature>"
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
