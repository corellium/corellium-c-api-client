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
      "vpn-gateway",
      corellium_api_interconnect_TYPE_hub,
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      list_createList(),
      "56494514-33f7-4fc2-9fdc-865e3957e6d3",
      "eth",
      corellium_api_interconnect_STATUS_attached,
      2,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    interconnect = interconnect_create(
      "vpn-gateway",
      corellium_api_interconnect_TYPE_hub,
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      list_createList(),
      "56494514-33f7-4fc2-9fdc-865e3957e6d3",
      "eth",
      corellium_api_interconnect_STATUS_attached,
      2,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
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
