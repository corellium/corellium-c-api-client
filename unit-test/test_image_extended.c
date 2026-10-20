#ifndef image_extended_TEST
#define image_extended_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_extended_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_extended.h"
image_extended_t* instantiate_image_extended(int include_optional);

#include "test_image_extended_device.c"


image_extended_t* instantiate_image_extended(int include_optional) {
  image_extended_t* image_extended = NULL;
  if (include_optional) {
    image_extended = image_extended_create(
      "0",
      "0",
      "0",
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_image_extended_device(0)
    );
  } else {
    image_extended = image_extended_create(
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      NULL
    );
  }

  return image_extended;
}


#ifdef image_extended_MAIN

void test_image_extended(int include_optional) {
    image_extended_t* image_extended_1 = instantiate_image_extended(include_optional);

	cJSON* jsonimage_extended_1 = image_extended_convertToJSON(image_extended_1);
	printf("image_extended :\n%s\n", cJSON_Print(jsonimage_extended_1));
	image_extended_t* image_extended_2 = image_extended_parseFromJSON(jsonimage_extended_1);
	cJSON* jsonimage_extended_2 = image_extended_convertToJSON(image_extended_2);
	printf("repeating image_extended:\n%s\n", cJSON_Print(jsonimage_extended_2));
}

int main() {
  test_image_extended(1);
  test_image_extended(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_extended_MAIN
#endif // image_extended_TEST
