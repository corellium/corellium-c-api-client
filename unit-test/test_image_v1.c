#ifndef image_v1_TEST
#define image_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_v1.h"
image_v1_t* instantiate_image_v1(int include_optional);

#include "test_image_extended.c"


image_v1_t* instantiate_image_v1(int include_optional) {
  image_v1_t* image_v1 = NULL;
  if (include_optional) {
    image_v1 = image_v1_create(
      "0",
      "0",
      "0",
      "0",
      corellium_api_image_v1_TYPE_fwbinary,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_image_extended(0)
    );
  } else {
    image_v1 = image_v1_create(
      "0",
      "0",
      "0",
      "0",
      corellium_api_image_v1_TYPE_fwbinary,
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      NULL
    );
  }

  return image_v1;
}


#ifdef image_v1_MAIN

void test_image_v1(int include_optional) {
    image_v1_t* image_v1_1 = instantiate_image_v1(include_optional);

	cJSON* jsonimage_v1_1 = image_v1_convertToJSON(image_v1_1);
	printf("image_v1 :\n%s\n", cJSON_Print(jsonimage_v1_1));
	image_v1_t* image_v1_2 = image_v1_parseFromJSON(jsonimage_v1_1);
	cJSON* jsonimage_v1_2 = image_v1_convertToJSON(image_v1_2);
	printf("repeating image_v1:\n%s\n", cJSON_Print(jsonimage_v1_2));
}

int main() {
  test_image_v1(1);
  test_image_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_v1_MAIN
#endif // image_v1_TEST
