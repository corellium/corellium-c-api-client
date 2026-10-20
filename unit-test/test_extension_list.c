#ifndef extension_list_TEST
#define extension_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extension_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extension_list.h"
extension_list_t* instantiate_extension_list(int include_optional);



extension_list_t* instantiate_extension_list(int include_optional) {
  extension_list_t* extension_list = NULL;
  if (include_optional) {
    extension_list = extension_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    extension_list = extension_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return extension_list;
}


#ifdef extension_list_MAIN

void test_extension_list(int include_optional) {
    extension_list_t* extension_list_1 = instantiate_extension_list(include_optional);

	cJSON* jsonextension_list_1 = extension_list_convertToJSON(extension_list_1);
	printf("extension_list :\n%s\n", cJSON_Print(jsonextension_list_1));
	extension_list_t* extension_list_2 = extension_list_parseFromJSON(jsonextension_list_1);
	cJSON* jsonextension_list_2 = extension_list_convertToJSON(extension_list_2);
	printf("repeating extension_list:\n%s\n", cJSON_Print(jsonextension_list_2));
}

int main() {
  test_extension_list(1);
  test_extension_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // extension_list_MAIN
#endif // extension_list_TEST
