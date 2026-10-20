#ifndef sys_info_schema_TEST
#define sys_info_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sys_info_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sys_info_schema.h"
sys_info_schema_t* instantiate_sys_info_schema(int include_optional);



sys_info_schema_t* instantiate_sys_info_schema(int include_optional) {
  sys_info_schema_t* sys_info_schema = NULL;
  if (include_optional) {
    sys_info_schema = sys_info_schema_create(
      2,
      0,
      0,
      24,
      8,
      262144,
      65536,
      8,
      5,
      2,
      1,
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      64,
      24,
      4096
    );
  } else {
    sys_info_schema = sys_info_schema_create(
      2,
      0,
      0,
      24,
      8,
      262144,
      65536,
      8,
      5,
      2,
      1,
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      64,
      24,
      4096
    );
  }

  return sys_info_schema;
}


#ifdef sys_info_schema_MAIN

void test_sys_info_schema(int include_optional) {
    sys_info_schema_t* sys_info_schema_1 = instantiate_sys_info_schema(include_optional);

	cJSON* jsonsys_info_schema_1 = sys_info_schema_convertToJSON(sys_info_schema_1);
	printf("sys_info_schema :\n%s\n", cJSON_Print(jsonsys_info_schema_1));
	sys_info_schema_t* sys_info_schema_2 = sys_info_schema_parseFromJSON(jsonsys_info_schema_1);
	cJSON* jsonsys_info_schema_2 = sys_info_schema_convertToJSON(sys_info_schema_2);
	printf("repeating sys_info_schema:\n%s\n", cJSON_Print(jsonsys_info_schema_2));
}

int main() {
  test_sys_info_schema(1);
  test_sys_info_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // sys_info_schema_MAIN
#endif // sys_info_schema_TEST
