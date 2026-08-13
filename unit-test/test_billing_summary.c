#ifndef billing_summary_TEST
#define billing_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define billing_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/billing_summary.h"
billing_summary_t* instantiate_billing_summary(int include_optional);

#include "test_billing_summary_pending_usage_based.c"


billing_summary_t* instantiate_billing_summary(int include_optional) {
  billing_summary_t* billing_summary = NULL;
  if (include_optional) {
    billing_summary = billing_summary_create(
       // false, not to have infinite recursion
      instantiate_billing_summary_pending_usage_based(0)
    );
  } else {
    billing_summary = billing_summary_create(
      NULL
    );
  }

  return billing_summary;
}


#ifdef billing_summary_MAIN

void test_billing_summary(int include_optional) {
    billing_summary_t* billing_summary_1 = instantiate_billing_summary(include_optional);

	cJSON* jsonbilling_summary_1 = billing_summary_convertToJSON(billing_summary_1);
	printf("billing_summary :\n%s\n", cJSON_Print(jsonbilling_summary_1));
	billing_summary_t* billing_summary_2 = billing_summary_parseFromJSON(jsonbilling_summary_1);
	cJSON* jsonbilling_summary_2 = billing_summary_convertToJSON(billing_summary_2);
	printf("repeating billing_summary:\n%s\n", cJSON_Print(jsonbilling_summary_2));
}

int main() {
  test_billing_summary(1);
  test_billing_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // billing_summary_MAIN
#endif // billing_summary_TEST
