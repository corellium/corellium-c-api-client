#ifndef ipsw_filter_v3_version_TEST
#define ipsw_filter_v3_version_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipsw_filter_v3_version_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipsw_filter_v3_version.h"
ipsw_filter_v3_version_t* instantiate_ipsw_filter_v3_version(int include_optional);



ipsw_filter_v3_version_t* instantiate_ipsw_filter_v3_version(int include_optional) {
  ipsw_filter_v3_version_t* ipsw_filter_v3_version = NULL;
  if (include_optional) {
    ipsw_filter_v3_version = ipsw_filter_v3_version_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    ipsw_filter_v3_version = ipsw_filter_v3_version_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return ipsw_filter_v3_version;
}


#ifdef ipsw_filter_v3_version_MAIN

void test_ipsw_filter_v3_version(int include_optional) {
    ipsw_filter_v3_version_t* ipsw_filter_v3_version_1 = instantiate_ipsw_filter_v3_version(include_optional);

	cJSON* jsonipsw_filter_v3_version_1 = ipsw_filter_v3_version_convertToJSON(ipsw_filter_v3_version_1);
	printf("ipsw_filter_v3_version :\n%s\n", cJSON_Print(jsonipsw_filter_v3_version_1));
	ipsw_filter_v3_version_t* ipsw_filter_v3_version_2 = ipsw_filter_v3_version_parseFromJSON(jsonipsw_filter_v3_version_1);
	cJSON* jsonipsw_filter_v3_version_2 = ipsw_filter_v3_version_convertToJSON(ipsw_filter_v3_version_2);
	printf("repeating ipsw_filter_v3_version:\n%s\n", cJSON_Print(jsonipsw_filter_v3_version_2));
}

int main() {
  test_ipsw_filter_v3_version(1);
  test_ipsw_filter_v3_version(0);

  printf("Hello world \n");
  return 0;
}

#endif // ipsw_filter_v3_version_MAIN
#endif // ipsw_filter_v3_version_TEST
