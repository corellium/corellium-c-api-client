#ifndef trial_request_detail_TEST
#define trial_request_detail_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trial_request_detail_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trial_request_detail.h"
trial_request_detail_t* instantiate_trial_request_detail(int include_optional);

#include "test_trial_request_detail_organization.c"


trial_request_detail_t* instantiate_trial_request_detail(int include_optional) {
  trial_request_detail_t* trial_request_detail = NULL;
  if (include_optional) {
    trial_request_detail = trial_request_detail_create(
      "a1e77521-9267-4e6d-8888-180f3a83ea3a",
      {"name":"Jane Doe","company":"Acme Corp","malware":true,"pentest":true},
       // false, not to have infinite recursion
      instantiate_trial_request_detail_organization(0),
      [{"ios":"iOS"}],
      [{"malware":"Malware Research"}],
      "jane.doe@example.com",
      "Jane Doe",
      corellium_api_trial_request_detail_BILLINGTYPE_prepaid,
      "stripe",
      "cus_Qabc123XyZ",
      "prod_ExampleProductId",
      "LAUNCH2026",
      true,
      true,
      "+1-555-123-4567",
      "US",
      corellium_api_trial_request_detail_ORGANIZATIONTYPE_individual,
      "Software",
      "Security Engineer",
      "Mobile App Security Testing",
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "2026-03-16T08:22:19Z",
      "2026-03-14T09:12:47Z",
      "2026-03-18T16:05:33Z",
      "Enterprise Trial",
      "2027-01-15T00:00Z",
      corellium_api_trial_request_detail_GRANTMETHOD_sales,
      14,
      24,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    trial_request_detail = trial_request_detail_create(
      "a1e77521-9267-4e6d-8888-180f3a83ea3a",
      {"name":"Jane Doe","company":"Acme Corp","malware":true,"pentest":true},
      NULL,
      [{"ios":"iOS"}],
      [{"malware":"Malware Research"}],
      "jane.doe@example.com",
      "Jane Doe",
      corellium_api_trial_request_detail_BILLINGTYPE_prepaid,
      "stripe",
      "cus_Qabc123XyZ",
      "prod_ExampleProductId",
      "LAUNCH2026",
      true,
      true,
      "+1-555-123-4567",
      "US",
      corellium_api_trial_request_detail_ORGANIZATIONTYPE_individual,
      "Software",
      "Security Engineer",
      "Mobile App Security Testing",
      "c29762d1-45d7-489d-a3a2-9dadc43978ba",
      "2026-03-16T08:22:19Z",
      "2026-03-14T09:12:47Z",
      "2026-03-18T16:05:33Z",
      "Enterprise Trial",
      "2027-01-15T00:00Z",
      corellium_api_trial_request_detail_GRANTMETHOD_sales,
      14,
      24,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return trial_request_detail;
}


#ifdef trial_request_detail_MAIN

void test_trial_request_detail(int include_optional) {
    trial_request_detail_t* trial_request_detail_1 = instantiate_trial_request_detail(include_optional);

	cJSON* jsontrial_request_detail_1 = trial_request_detail_convertToJSON(trial_request_detail_1);
	printf("trial_request_detail :\n%s\n", cJSON_Print(jsontrial_request_detail_1));
	trial_request_detail_t* trial_request_detail_2 = trial_request_detail_parseFromJSON(jsontrial_request_detail_1);
	cJSON* jsontrial_request_detail_2 = trial_request_detail_convertToJSON(trial_request_detail_2);
	printf("repeating trial_request_detail:\n%s\n", cJSON_Print(jsontrial_request_detail_2));
}

int main() {
  test_trial_request_detail(1);
  test_trial_request_detail(0);

  printf("Hello world \n");
  return 0;
}

#endif // trial_request_detail_MAIN
#endif // trial_request_detail_TEST
