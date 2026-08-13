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
      "0",
      0,
       // false, not to have infinite recursion
      instantiate_trial_request_detail_organization(0),
      list_createList(),
      list_createList(),
      "0",
      "0",
      corellium_api_trial_request_detail_BILLINGTYPE_prepaid,
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      "0",
      "0",
      corellium_api_trial_request_detail_ORGANIZATIONTYPE_individual,
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      corellium_api_trial_request_detail_GRANTMETHOD_sales,
      56,
      1.337,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    trial_request_detail = trial_request_detail_create(
      "0",
      0,
      NULL,
      list_createList(),
      list_createList(),
      "0",
      "0",
      corellium_api_trial_request_detail_BILLINGTYPE_prepaid,
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      "0",
      "0",
      corellium_api_trial_request_detail_ORGANIZATIONTYPE_individual,
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      corellium_api_trial_request_detail_GRANTMETHOD_sales,
      56,
      1.337,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
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
