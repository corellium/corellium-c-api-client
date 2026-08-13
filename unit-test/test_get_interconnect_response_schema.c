#ifndef get_interconnect_response_schema_TEST
#define get_interconnect_response_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_interconnect_response_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_interconnect_response_schema.h"
get_interconnect_response_schema_t* instantiate_get_interconnect_response_schema(int include_optional);



get_interconnect_response_schema_t* instantiate_get_interconnect_response_schema(int include_optional) {
  get_interconnect_response_schema_t* get_interconnect_response_schema = NULL;
  if (include_optional) {
    get_interconnect_response_schema = get_interconnect_response_schema_create(
      "0",
      "0",
      corellium_api_get_interconnect_response_schema_TYPE_hub,
      "0",
      list_createList(),
      "0",
      corellium_api_get_interconnect_response_schema_STATUS_attached,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      0
    );
  } else {
    get_interconnect_response_schema = get_interconnect_response_schema_create(
      "0",
      "0",
      corellium_api_get_interconnect_response_schema_TYPE_hub,
      "0",
      list_createList(),
      "0",
      corellium_api_get_interconnect_response_schema_STATUS_attached,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      0
    );
  }

  return get_interconnect_response_schema;
}


#ifdef get_interconnect_response_schema_MAIN

void test_get_interconnect_response_schema(int include_optional) {
    get_interconnect_response_schema_t* get_interconnect_response_schema_1 = instantiate_get_interconnect_response_schema(include_optional);

	cJSON* jsonget_interconnect_response_schema_1 = get_interconnect_response_schema_convertToJSON(get_interconnect_response_schema_1);
	printf("get_interconnect_response_schema :\n%s\n", cJSON_Print(jsonget_interconnect_response_schema_1));
	get_interconnect_response_schema_t* get_interconnect_response_schema_2 = get_interconnect_response_schema_parseFromJSON(jsonget_interconnect_response_schema_1);
	cJSON* jsonget_interconnect_response_schema_2 = get_interconnect_response_schema_convertToJSON(get_interconnect_response_schema_2);
	printf("repeating get_interconnect_response_schema:\n%s\n", cJSON_Print(jsonget_interconnect_response_schema_2));
}

int main() {
  test_get_interconnect_response_schema(1);
  test_get_interconnect_response_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_interconnect_response_schema_MAIN
#endif // get_interconnect_response_schema_TEST
