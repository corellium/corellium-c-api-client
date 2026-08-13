#ifndef extension_flavor_TEST
#define extension_flavor_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extension_flavor_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extension_flavor.h"
extension_flavor_t* instantiate_extension_flavor(int include_optional);



extension_flavor_t* instantiate_extension_flavor(int include_optional) {
  extension_flavor_t* extension_flavor = NULL;
  if (include_optional) {
    extension_flavor = extension_flavor_create(
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      1,
      1,
      1
    );
  } else {
    extension_flavor = extension_flavor_create(
      "0",
      "0",
      "0",
      "0",
      1.337,
      1.337,
      1,
      1,
      1
    );
  }

  return extension_flavor;
}


#ifdef extension_flavor_MAIN

void test_extension_flavor(int include_optional) {
    extension_flavor_t* extension_flavor_1 = instantiate_extension_flavor(include_optional);

	cJSON* jsonextension_flavor_1 = extension_flavor_convertToJSON(extension_flavor_1);
	printf("extension_flavor :\n%s\n", cJSON_Print(jsonextension_flavor_1));
	extension_flavor_t* extension_flavor_2 = extension_flavor_parseFromJSON(jsonextension_flavor_1);
	cJSON* jsonextension_flavor_2 = extension_flavor_convertToJSON(extension_flavor_2);
	printf("repeating extension_flavor:\n%s\n", cJSON_Print(jsonextension_flavor_2));
}

int main() {
  test_extension_flavor(1);
  test_extension_flavor(0);

  printf("Hello world \n");
  return 0;
}

#endif // extension_flavor_MAIN
#endif // extension_flavor_TEST
