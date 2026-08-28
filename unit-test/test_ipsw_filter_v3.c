#ifndef ipsw_filter_v3_TEST
#define ipsw_filter_v3_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipsw_filter_v3_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipsw_filter_v3.h"
ipsw_filter_v3_t* instantiate_ipsw_filter_v3(int include_optional);

#include "test_ipsw_filter_v3_version.c"
#include "test_ipsw_filter_v3_device.c"


ipsw_filter_v3_t* instantiate_ipsw_filter_v3(int include_optional) {
  ipsw_filter_v3_t* ipsw_filter_v3 = NULL;
  if (include_optional) {
    ipsw_filter_v3 = ipsw_filter_v3_create(
       // false, not to have infinite recursion
      instantiate_ipsw_filter_v3_version(0),
       // false, not to have infinite recursion
      instantiate_ipsw_filter_v3_device(0),
      1,
      1
    );
  } else {
    ipsw_filter_v3 = ipsw_filter_v3_create(
      NULL,
      NULL,
      1,
      1
    );
  }

  return ipsw_filter_v3;
}


#ifdef ipsw_filter_v3_MAIN

void test_ipsw_filter_v3(int include_optional) {
    ipsw_filter_v3_t* ipsw_filter_v3_1 = instantiate_ipsw_filter_v3(include_optional);

	cJSON* jsonipsw_filter_v3_1 = ipsw_filter_v3_convertToJSON(ipsw_filter_v3_1);
	printf("ipsw_filter_v3 :\n%s\n", cJSON_Print(jsonipsw_filter_v3_1));
	ipsw_filter_v3_t* ipsw_filter_v3_2 = ipsw_filter_v3_parseFromJSON(jsonipsw_filter_v3_1);
	cJSON* jsonipsw_filter_v3_2 = ipsw_filter_v3_convertToJSON(ipsw_filter_v3_2);
	printf("repeating ipsw_filter_v3:\n%s\n", cJSON_Print(jsonipsw_filter_v3_2));
}

int main() {
  test_ipsw_filter_v3(1);
  test_ipsw_filter_v3(0);

  printf("Hello world \n");
  return 0;
}

#endif // ipsw_filter_v3_MAIN
#endif // ipsw_filter_v3_TEST
