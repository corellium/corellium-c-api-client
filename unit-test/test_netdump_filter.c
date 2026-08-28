#ifndef netdump_filter_TEST
#define netdump_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define netdump_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/netdump_filter.h"
netdump_filter_t* instantiate_netdump_filter(int include_optional);



netdump_filter_t* instantiate_netdump_filter(int include_optional) {
  netdump_filter_t* netdump_filter = NULL;
  if (include_optional) {
    netdump_filter = netdump_filter_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList()
    );
  } else {
    netdump_filter = netdump_filter_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList()
    );
  }

  return netdump_filter;
}


#ifdef netdump_filter_MAIN

void test_netdump_filter(int include_optional) {
    netdump_filter_t* netdump_filter_1 = instantiate_netdump_filter(include_optional);

	cJSON* jsonnetdump_filter_1 = netdump_filter_convertToJSON(netdump_filter_1);
	printf("netdump_filter :\n%s\n", cJSON_Print(jsonnetdump_filter_1));
	netdump_filter_t* netdump_filter_2 = netdump_filter_parseFromJSON(jsonnetdump_filter_1);
	cJSON* jsonnetdump_filter_2 = netdump_filter_convertToJSON(netdump_filter_2);
	printf("repeating netdump_filter:\n%s\n", cJSON_Print(jsonnetdump_filter_2));
}

int main() {
  test_netdump_filter(1);
  test_netdump_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // netdump_filter_MAIN
#endif // netdump_filter_TEST
