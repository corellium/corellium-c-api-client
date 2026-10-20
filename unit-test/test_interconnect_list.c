#ifndef interconnect_list_TEST
#define interconnect_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define interconnect_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/interconnect_list.h"
interconnect_list_t* instantiate_interconnect_list(int include_optional);



interconnect_list_t* instantiate_interconnect_list(int include_optional) {
  interconnect_list_t* interconnect_list = NULL;
  if (include_optional) {
    interconnect_list = interconnect_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    interconnect_list = interconnect_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return interconnect_list;
}


#ifdef interconnect_list_MAIN

void test_interconnect_list(int include_optional) {
    interconnect_list_t* interconnect_list_1 = instantiate_interconnect_list(include_optional);

	cJSON* jsoninterconnect_list_1 = interconnect_list_convertToJSON(interconnect_list_1);
	printf("interconnect_list :\n%s\n", cJSON_Print(jsoninterconnect_list_1));
	interconnect_list_t* interconnect_list_2 = interconnect_list_parseFromJSON(jsoninterconnect_list_1);
	cJSON* jsoninterconnect_list_2 = interconnect_list_convertToJSON(interconnect_list_2);
	printf("repeating interconnect_list:\n%s\n", cJSON_Print(jsoninterconnect_list_2));
}

int main() {
  test_interconnect_list(1);
  test_interconnect_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // interconnect_list_MAIN
#endif // interconnect_list_TEST
