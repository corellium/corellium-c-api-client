#ifndef create_interconnect_response_schema_TEST
#define create_interconnect_response_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_interconnect_response_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_interconnect_response_schema.h"
create_interconnect_response_schema_t* instantiate_create_interconnect_response_schema(int include_optional);



create_interconnect_response_schema_t* instantiate_create_interconnect_response_schema(int include_optional) {
  create_interconnect_response_schema_t* create_interconnect_response_schema = NULL;
  if (include_optional) {
    create_interconnect_response_schema = create_interconnect_response_schema_create(
      "0",
      "0",
      corellium_api_create_interconnect_response_schema_TYPE_hub,
      "0",
      list_createList(),
      "0",
      corellium_api_create_interconnect_response_schema_STATUS_attached,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    create_interconnect_response_schema = create_interconnect_response_schema_create(
      "0",
      "0",
      corellium_api_create_interconnect_response_schema_TYPE_hub,
      "0",
      list_createList(),
      "0",
      corellium_api_create_interconnect_response_schema_STATUS_attached,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return create_interconnect_response_schema;
}


#ifdef create_interconnect_response_schema_MAIN

void test_create_interconnect_response_schema(int include_optional) {
    create_interconnect_response_schema_t* create_interconnect_response_schema_1 = instantiate_create_interconnect_response_schema(include_optional);

	cJSON* jsoncreate_interconnect_response_schema_1 = create_interconnect_response_schema_convertToJSON(create_interconnect_response_schema_1);
	printf("create_interconnect_response_schema :\n%s\n", cJSON_Print(jsoncreate_interconnect_response_schema_1));
	create_interconnect_response_schema_t* create_interconnect_response_schema_2 = create_interconnect_response_schema_parseFromJSON(jsoncreate_interconnect_response_schema_1);
	cJSON* jsoncreate_interconnect_response_schema_2 = create_interconnect_response_schema_convertToJSON(create_interconnect_response_schema_2);
	printf("repeating create_interconnect_response_schema:\n%s\n", cJSON_Print(jsoncreate_interconnect_response_schema_2));
}

int main() {
  test_create_interconnect_response_schema(1);
  test_create_interconnect_response_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_interconnect_response_schema_MAIN
#endif // create_interconnect_response_schema_TEST
