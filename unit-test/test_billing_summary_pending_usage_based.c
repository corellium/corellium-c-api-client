#ifndef billing_summary_pending_usage_based_TEST
#define billing_summary_pending_usage_based_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define billing_summary_pending_usage_based_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/billing_summary_pending_usage_based.h"
billing_summary_pending_usage_based_t* instantiate_billing_summary_pending_usage_based(int include_optional);



billing_summary_pending_usage_based_t* instantiate_billing_summary_pending_usage_based(int include_optional) {
  billing_summary_pending_usage_based_t* billing_summary_pending_usage_based = NULL;
  if (include_optional) {
    billing_summary_pending_usage_based = billing_summary_pending_usage_based_create(
      1.337,
      1.337,
      1.337,
      "0",
      list_createList()
    );
  } else {
    billing_summary_pending_usage_based = billing_summary_pending_usage_based_create(
      1.337,
      1.337,
      1.337,
      "0",
      list_createList()
    );
  }

  return billing_summary_pending_usage_based;
}


#ifdef billing_summary_pending_usage_based_MAIN

void test_billing_summary_pending_usage_based(int include_optional) {
    billing_summary_pending_usage_based_t* billing_summary_pending_usage_based_1 = instantiate_billing_summary_pending_usage_based(include_optional);

	cJSON* jsonbilling_summary_pending_usage_based_1 = billing_summary_pending_usage_based_convertToJSON(billing_summary_pending_usage_based_1);
	printf("billing_summary_pending_usage_based :\n%s\n", cJSON_Print(jsonbilling_summary_pending_usage_based_1));
	billing_summary_pending_usage_based_t* billing_summary_pending_usage_based_2 = billing_summary_pending_usage_based_parseFromJSON(jsonbilling_summary_pending_usage_based_1);
	cJSON* jsonbilling_summary_pending_usage_based_2 = billing_summary_pending_usage_based_convertToJSON(billing_summary_pending_usage_based_2);
	printf("repeating billing_summary_pending_usage_based:\n%s\n", cJSON_Print(jsonbilling_summary_pending_usage_based_2));
}

int main() {
  test_billing_summary_pending_usage_based(1);
  test_billing_summary_pending_usage_based(0);

  printf("Hello world \n");
  return 0;
}

#endif // billing_summary_pending_usage_based_MAIN
#endif // billing_summary_pending_usage_based_TEST
