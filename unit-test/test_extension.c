#ifndef extension_TEST
#define extension_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extension_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extension.h"
extension_t* instantiate_extension(int include_optional);



extension_t* instantiate_extension(int include_optional) {
  extension_t* extension = NULL;
  if (include_optional) {
    extension = extension_create(
      "rpi4b",
      true,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "deleting",
      list_createList()
    );
  } else {
    extension = extension_create(
      "rpi4b",
      true,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z",
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "deleting",
      list_createList()
    );
  }

  return extension;
}


#ifdef extension_MAIN

void test_extension(int include_optional) {
    extension_t* extension_1 = instantiate_extension(include_optional);

	cJSON* jsonextension_1 = extension_convertToJSON(extension_1);
	printf("extension :\n%s\n", cJSON_Print(jsonextension_1));
	extension_t* extension_2 = extension_parseFromJSON(jsonextension_1);
	cJSON* jsonextension_2 = extension_convertToJSON(extension_2);
	printf("repeating extension:\n%s\n", cJSON_Print(jsonextension_2));
}

int main() {
  test_extension(1);
  test_extension(0);

  printf("Hello world \n");
  return 0;
}

#endif // extension_MAIN
#endif // extension_TEST
