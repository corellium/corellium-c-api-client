#ifndef interconnect_TEST
#define interconnect_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define interconnect_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/interconnect.h"
interconnect_t* instantiate_interconnect(int include_optional);



interconnect_t* instantiate_interconnect(int include_optional) {
  interconnect_t* interconnect = NULL;
  if (include_optional) {
    interconnect = interconnect_create(
      "0",
      corellium_api_interconnect_TYPE_hub,
      "0",
      list_createList(),
      "0",
      "0",
      corellium_api_interconnect_STATUS_attached,
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    interconnect = interconnect_create(
      "0",
      corellium_api_interconnect_TYPE_hub,
      "0",
      list_createList(),
      "0",
      "0",
      corellium_api_interconnect_STATUS_attached,
      0,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return interconnect;
}


#ifdef interconnect_MAIN

void test_interconnect(int include_optional) {
    interconnect_t* interconnect_1 = instantiate_interconnect(include_optional);

	cJSON* jsoninterconnect_1 = interconnect_convertToJSON(interconnect_1);
	printf("interconnect :\n%s\n", cJSON_Print(jsoninterconnect_1));
	interconnect_t* interconnect_2 = interconnect_parseFromJSON(jsoninterconnect_1);
	cJSON* jsoninterconnect_2 = interconnect_convertToJSON(interconnect_2);
	printf("repeating interconnect:\n%s\n", cJSON_Print(jsoninterconnect_2));
}

int main() {
  test_interconnect(1);
  test_interconnect(0);

  printf("Hello world \n");
  return 0;
}

#endif // interconnect_MAIN
#endif // interconnect_TEST
