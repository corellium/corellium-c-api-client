#ifndef ipsw_filter_TEST
#define ipsw_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipsw_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipsw_filter.h"
ipsw_filter_t* instantiate_ipsw_filter(int include_optional);

#include "test_ipsw_version_constraint.c"
#include "test_ipsw_device_constraint.c"


ipsw_filter_t* instantiate_ipsw_filter(int include_optional) {
  ipsw_filter_t* ipsw_filter = NULL;
  if (include_optional) {
    ipsw_filter = ipsw_filter_create(
       // false, not to have infinite recursion
      instantiate_ipsw_version_constraint(0),
       // false, not to have infinite recursion
      instantiate_ipsw_device_constraint(0),
      1,
      1
    );
  } else {
    ipsw_filter = ipsw_filter_create(
      NULL,
      NULL,
      1,
      1
    );
  }

  return ipsw_filter;
}


#ifdef ipsw_filter_MAIN

void test_ipsw_filter(int include_optional) {
    ipsw_filter_t* ipsw_filter_1 = instantiate_ipsw_filter(include_optional);

	cJSON* jsonipsw_filter_1 = ipsw_filter_convertToJSON(ipsw_filter_1);
	printf("ipsw_filter :\n%s\n", cJSON_Print(jsonipsw_filter_1));
	ipsw_filter_t* ipsw_filter_2 = ipsw_filter_parseFromJSON(jsonipsw_filter_1);
	cJSON* jsonipsw_filter_2 = ipsw_filter_convertToJSON(ipsw_filter_2);
	printf("repeating ipsw_filter:\n%s\n", cJSON_Print(jsonipsw_filter_2));
}

int main() {
  test_ipsw_filter(1);
  test_ipsw_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // ipsw_filter_MAIN
#endif // ipsw_filter_TEST
