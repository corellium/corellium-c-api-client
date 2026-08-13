#ifndef sharing_type_TEST
#define sharing_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sharing_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sharing_type.h"
sharing_type_t* instantiate_sharing_type(int include_optional);



sharing_type_t* instantiate_sharing_type(int include_optional) {
  sharing_type_t* sharing_type = NULL;
  if (include_optional) {
    sharing_type = sharing_type_create(
    );
  } else {
    sharing_type = sharing_type_create(
    );
  }

  return sharing_type;
}


#ifdef sharing_type_MAIN

void test_sharing_type(int include_optional) {
    sharing_type_t* sharing_type_1 = instantiate_sharing_type(include_optional);

	cJSON* jsonsharing_type_1 = sharing_type_convertToJSON(sharing_type_1);
	printf("sharing_type :\n%s\n", cJSON_Print(jsonsharing_type_1));
	sharing_type_t* sharing_type_2 = sharing_type_parseFromJSON(jsonsharing_type_1);
	cJSON* jsonsharing_type_2 = sharing_type_convertToJSON(sharing_type_2);
	printf("repeating sharing_type:\n%s\n", cJSON_Print(jsonsharing_type_2));
}

int main() {
  test_sharing_type(1);
  test_sharing_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // sharing_type_MAIN
#endif // sharing_type_TEST
