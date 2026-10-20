#ifndef allowed_devices_filter_schema_TEST
#define allowed_devices_filter_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define allowed_devices_filter_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/allowed_devices_filter_schema.h"
allowed_devices_filter_schema_t* instantiate_allowed_devices_filter_schema(int include_optional);



allowed_devices_filter_schema_t* instantiate_allowed_devices_filter_schema(int include_optional) {
  allowed_devices_filter_schema_t* allowed_devices_filter_schema = NULL;
  if (include_optional) {
    allowed_devices_filter_schema = allowed_devices_filter_schema_create(
      "iphone15",
      list_createList()
    );
  } else {
    allowed_devices_filter_schema = allowed_devices_filter_schema_create(
      "iphone15",
      list_createList()
    );
  }

  return allowed_devices_filter_schema;
}


#ifdef allowed_devices_filter_schema_MAIN

void test_allowed_devices_filter_schema(int include_optional) {
    allowed_devices_filter_schema_t* allowed_devices_filter_schema_1 = instantiate_allowed_devices_filter_schema(include_optional);

	cJSON* jsonallowed_devices_filter_schema_1 = allowed_devices_filter_schema_convertToJSON(allowed_devices_filter_schema_1);
	printf("allowed_devices_filter_schema :\n%s\n", cJSON_Print(jsonallowed_devices_filter_schema_1));
	allowed_devices_filter_schema_t* allowed_devices_filter_schema_2 = allowed_devices_filter_schema_parseFromJSON(jsonallowed_devices_filter_schema_1);
	cJSON* jsonallowed_devices_filter_schema_2 = allowed_devices_filter_schema_convertToJSON(allowed_devices_filter_schema_2);
	printf("repeating allowed_devices_filter_schema:\n%s\n", cJSON_Print(jsonallowed_devices_filter_schema_2));
}

int main() {
  test_allowed_devices_filter_schema(1);
  test_allowed_devices_filter_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // allowed_devices_filter_schema_MAIN
#endif // allowed_devices_filter_schema_TEST
