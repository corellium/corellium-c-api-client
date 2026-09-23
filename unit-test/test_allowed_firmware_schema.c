#ifndef allowed_firmware_schema_TEST
#define allowed_firmware_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define allowed_firmware_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/allowed_firmware_schema.h"
allowed_firmware_schema_t* instantiate_allowed_firmware_schema(int include_optional);



allowed_firmware_schema_t* instantiate_allowed_firmware_schema(int include_optional) {
  allowed_firmware_schema_t* allowed_firmware_schema = NULL;
  if (include_optional) {
    allowed_firmware_schema = allowed_firmware_schema_create(
      "17.4.1",
      "21E236"
    );
  } else {
    allowed_firmware_schema = allowed_firmware_schema_create(
      "17.4.1",
      "21E236"
    );
  }

  return allowed_firmware_schema;
}


#ifdef allowed_firmware_schema_MAIN

void test_allowed_firmware_schema(int include_optional) {
    allowed_firmware_schema_t* allowed_firmware_schema_1 = instantiate_allowed_firmware_schema(include_optional);

	cJSON* jsonallowed_firmware_schema_1 = allowed_firmware_schema_convertToJSON(allowed_firmware_schema_1);
	printf("allowed_firmware_schema :\n%s\n", cJSON_Print(jsonallowed_firmware_schema_1));
	allowed_firmware_schema_t* allowed_firmware_schema_2 = allowed_firmware_schema_parseFromJSON(jsonallowed_firmware_schema_1);
	cJSON* jsonallowed_firmware_schema_2 = allowed_firmware_schema_convertToJSON(allowed_firmware_schema_2);
	printf("repeating allowed_firmware_schema:\n%s\n", cJSON_Print(jsonallowed_firmware_schema_2));
}

int main() {
  test_allowed_firmware_schema(1);
  test_allowed_firmware_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // allowed_firmware_schema_MAIN
#endif // allowed_firmware_schema_TEST
