#ifndef metered_subscription_usage_v1_TEST
#define metered_subscription_usage_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define metered_subscription_usage_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/metered_subscription_usage_v1.h"
metered_subscription_usage_v1_t* instantiate_metered_subscription_usage_v1(int include_optional);



metered_subscription_usage_v1_t* instantiate_metered_subscription_usage_v1(int include_optional) {
  metered_subscription_usage_v1_t* metered_subscription_usage_v1 = NULL;
  if (include_optional) {
    metered_subscription_usage_v1 = metered_subscription_usage_v1_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    metered_subscription_usage_v1 = metered_subscription_usage_v1_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return metered_subscription_usage_v1;
}


#ifdef metered_subscription_usage_v1_MAIN

void test_metered_subscription_usage_v1(int include_optional) {
    metered_subscription_usage_v1_t* metered_subscription_usage_v1_1 = instantiate_metered_subscription_usage_v1(include_optional);

	cJSON* jsonmetered_subscription_usage_v1_1 = metered_subscription_usage_v1_convertToJSON(metered_subscription_usage_v1_1);
	printf("metered_subscription_usage_v1 :\n%s\n", cJSON_Print(jsonmetered_subscription_usage_v1_1));
	metered_subscription_usage_v1_t* metered_subscription_usage_v1_2 = metered_subscription_usage_v1_parseFromJSON(jsonmetered_subscription_usage_v1_1);
	cJSON* jsonmetered_subscription_usage_v1_2 = metered_subscription_usage_v1_convertToJSON(metered_subscription_usage_v1_2);
	printf("repeating metered_subscription_usage_v1:\n%s\n", cJSON_Print(jsonmetered_subscription_usage_v1_2));
}

int main() {
  test_metered_subscription_usage_v1(1);
  test_metered_subscription_usage_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // metered_subscription_usage_v1_MAIN
#endif // metered_subscription_usage_v1_TEST
