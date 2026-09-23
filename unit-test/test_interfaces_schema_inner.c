#ifndef interfaces_schema_inner_TEST
#define interfaces_schema_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define interfaces_schema_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/interfaces_schema_inner.h"
interfaces_schema_inner_t* instantiate_interfaces_schema_inner(int include_optional);



interfaces_schema_inner_t* instantiate_interfaces_schema_inner(int include_optional) {
  interfaces_schema_inner_t* interfaces_schema_inner = NULL;
  if (include_optional) {
    interfaces_schema_inner = interfaces_schema_inner_create(
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "eth0:1/2"
    );
  } else {
    interfaces_schema_inner = interfaces_schema_inner_create(
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "eth0:1/2"
    );
  }

  return interfaces_schema_inner;
}


#ifdef interfaces_schema_inner_MAIN

void test_interfaces_schema_inner(int include_optional) {
    interfaces_schema_inner_t* interfaces_schema_inner_1 = instantiate_interfaces_schema_inner(include_optional);

	cJSON* jsoninterfaces_schema_inner_1 = interfaces_schema_inner_convertToJSON(interfaces_schema_inner_1);
	printf("interfaces_schema_inner :\n%s\n", cJSON_Print(jsoninterfaces_schema_inner_1));
	interfaces_schema_inner_t* interfaces_schema_inner_2 = interfaces_schema_inner_parseFromJSON(jsoninterfaces_schema_inner_1);
	cJSON* jsoninterfaces_schema_inner_2 = interfaces_schema_inner_convertToJSON(interfaces_schema_inner_2);
	printf("repeating interfaces_schema_inner:\n%s\n", cJSON_Print(jsoninterfaces_schema_inner_2));
}

int main() {
  test_interfaces_schema_inner(1);
  test_interfaces_schema_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // interfaces_schema_inner_MAIN
#endif // interfaces_schema_inner_TEST
