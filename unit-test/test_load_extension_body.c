#ifndef load_extension_body_TEST
#define load_extension_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define load_extension_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/load_extension_body.h"
load_extension_body_t* instantiate_load_extension_body(int include_optional);



load_extension_body_t* instantiate_load_extension_body(int include_optional) {
  load_extension_body_t* load_extension_body = NULL;
  if (include_optional) {
    load_extension_body = load_extension_body_create(
      "0"
    );
  } else {
    load_extension_body = load_extension_body_create(
      "0"
    );
  }

  return load_extension_body;
}


#ifdef load_extension_body_MAIN

void test_load_extension_body(int include_optional) {
    load_extension_body_t* load_extension_body_1 = instantiate_load_extension_body(include_optional);

	cJSON* jsonload_extension_body_1 = load_extension_body_convertToJSON(load_extension_body_1);
	printf("load_extension_body :\n%s\n", cJSON_Print(jsonload_extension_body_1));
	load_extension_body_t* load_extension_body_2 = load_extension_body_parseFromJSON(jsonload_extension_body_1);
	cJSON* jsonload_extension_body_2 = load_extension_body_convertToJSON(load_extension_body_2);
	printf("repeating load_extension_body:\n%s\n", cJSON_Print(jsonload_extension_body_2));
}

int main() {
  test_load_extension_body(1);
  test_load_extension_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // load_extension_body_MAIN
#endif // load_extension_body_TEST
