#ifndef metered_subscription_usage_TEST
#define metered_subscription_usage_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define metered_subscription_usage_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/metered_subscription_usage.h"
metered_subscription_usage_t* instantiate_metered_subscription_usage(int include_optional);



metered_subscription_usage_t* instantiate_metered_subscription_usage(int include_optional) {
  metered_subscription_usage_t* metered_subscription_usage = NULL;
  if (include_optional) {
    metered_subscription_usage = metered_subscription_usage_create(
      800,
      100,
      99500,
      29600,
      37,
      9600,
      12,
      138700,
      149
    );
  } else {
    metered_subscription_usage = metered_subscription_usage_create(
      800,
      100,
      99500,
      29600,
      37,
      9600,
      12,
      138700,
      149
    );
  }

  return metered_subscription_usage;
}


#ifdef metered_subscription_usage_MAIN

void test_metered_subscription_usage(int include_optional) {
    metered_subscription_usage_t* metered_subscription_usage_1 = instantiate_metered_subscription_usage(include_optional);

	cJSON* jsonmetered_subscription_usage_1 = metered_subscription_usage_convertToJSON(metered_subscription_usage_1);
	printf("metered_subscription_usage :\n%s\n", cJSON_Print(jsonmetered_subscription_usage_1));
	metered_subscription_usage_t* metered_subscription_usage_2 = metered_subscription_usage_parseFromJSON(jsonmetered_subscription_usage_1);
	cJSON* jsonmetered_subscription_usage_2 = metered_subscription_usage_convertToJSON(metered_subscription_usage_2);
	printf("repeating metered_subscription_usage:\n%s\n", cJSON_Print(jsonmetered_subscription_usage_2));
}

int main() {
  test_metered_subscription_usage(1);
  test_metered_subscription_usage(0);

  printf("Hello world \n");
  return 0;
}

#endif // metered_subscription_usage_MAIN
#endif // metered_subscription_usage_TEST
