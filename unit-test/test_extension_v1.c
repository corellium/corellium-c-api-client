#ifndef extension_v1_TEST
#define extension_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extension_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extension_v1.h"
extension_v1_t* instantiate_extension_v1(int include_optional);



extension_v1_t* instantiate_extension_v1(int include_optional) {
  extension_v1_t* extension_v1 = NULL;
  if (include_optional) {
    extension_v1 = extension_v1_create(
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    extension_v1 = extension_v1_create(
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return extension_v1;
}


#ifdef extension_v1_MAIN

void test_extension_v1(int include_optional) {
    extension_v1_t* extension_v1_1 = instantiate_extension_v1(include_optional);

	cJSON* jsonextension_v1_1 = extension_v1_convertToJSON(extension_v1_1);
	printf("extension_v1 :\n%s\n", cJSON_Print(jsonextension_v1_1));
	extension_v1_t* extension_v1_2 = extension_v1_parseFromJSON(jsonextension_v1_1);
	cJSON* jsonextension_v1_2 = extension_v1_convertToJSON(extension_v1_2);
	printf("repeating extension_v1:\n%s\n", cJSON_Print(jsonextension_v1_2));
}

int main() {
  test_extension_v1(1);
  test_extension_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // extension_v1_MAIN
#endif // extension_v1_TEST
