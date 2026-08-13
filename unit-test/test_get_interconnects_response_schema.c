#ifndef get_interconnects_response_schema_TEST
#define get_interconnects_response_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_interconnects_response_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_interconnects_response_schema.h"
get_interconnects_response_schema_t* instantiate_get_interconnects_response_schema(int include_optional);



get_interconnects_response_schema_t* instantiate_get_interconnects_response_schema(int include_optional) {
  get_interconnects_response_schema_t* get_interconnects_response_schema = NULL;
  if (include_optional) {
    get_interconnects_response_schema = get_interconnects_response_schema_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    get_interconnects_response_schema = get_interconnects_response_schema_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return get_interconnects_response_schema;
}


#ifdef get_interconnects_response_schema_MAIN

void test_get_interconnects_response_schema(int include_optional) {
    get_interconnects_response_schema_t* get_interconnects_response_schema_1 = instantiate_get_interconnects_response_schema(include_optional);

	cJSON* jsonget_interconnects_response_schema_1 = get_interconnects_response_schema_convertToJSON(get_interconnects_response_schema_1);
	printf("get_interconnects_response_schema :\n%s\n", cJSON_Print(jsonget_interconnects_response_schema_1));
	get_interconnects_response_schema_t* get_interconnects_response_schema_2 = get_interconnects_response_schema_parseFromJSON(jsonget_interconnects_response_schema_1);
	cJSON* jsonget_interconnects_response_schema_2 = get_interconnects_response_schema_convertToJSON(get_interconnects_response_schema_2);
	printf("repeating get_interconnects_response_schema:\n%s\n", cJSON_Print(jsonget_interconnects_response_schema_2));
}

int main() {
  test_get_interconnects_response_schema(1);
  test_get_interconnects_response_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_interconnects_response_schema_MAIN
#endif // get_interconnects_response_schema_TEST
