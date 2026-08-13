#ifndef trial_request_detail_organization_TEST
#define trial_request_detail_organization_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define trial_request_detail_organization_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/trial_request_detail_organization.h"
trial_request_detail_organization_t* instantiate_trial_request_detail_organization(int include_optional);



trial_request_detail_organization_t* instantiate_trial_request_detail_organization(int include_optional) {
  trial_request_detail_organization_t* trial_request_detail_organization = NULL;
  if (include_optional) {
    trial_request_detail_organization = trial_request_detail_organization_create(
      "0",
      "0"
    );
  } else {
    trial_request_detail_organization = trial_request_detail_organization_create(
      "0",
      "0"
    );
  }

  return trial_request_detail_organization;
}


#ifdef trial_request_detail_organization_MAIN

void test_trial_request_detail_organization(int include_optional) {
    trial_request_detail_organization_t* trial_request_detail_organization_1 = instantiate_trial_request_detail_organization(include_optional);

	cJSON* jsontrial_request_detail_organization_1 = trial_request_detail_organization_convertToJSON(trial_request_detail_organization_1);
	printf("trial_request_detail_organization :\n%s\n", cJSON_Print(jsontrial_request_detail_organization_1));
	trial_request_detail_organization_t* trial_request_detail_organization_2 = trial_request_detail_organization_parseFromJSON(jsontrial_request_detail_organization_1);
	cJSON* jsontrial_request_detail_organization_2 = trial_request_detail_organization_convertToJSON(trial_request_detail_organization_2);
	printf("repeating trial_request_detail_organization:\n%s\n", cJSON_Print(jsontrial_request_detail_organization_2));
}

int main() {
  test_trial_request_detail_organization(1);
  test_trial_request_detail_organization(0);

  printf("Hello world \n");
  return 0;
}

#endif // trial_request_detail_organization_MAIN
#endif // trial_request_detail_organization_TEST
