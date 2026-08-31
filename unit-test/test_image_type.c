#ifndef image_type_TEST
#define image_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_type.h"
image_type_t* instantiate_image_type(int include_optional);



image_type_t* instantiate_image_type(int include_optional) {
  image_type_t* image_type = NULL;
  if (include_optional) {
    image_type = image_type_create(
    );
  } else {
    image_type = image_type_create(
    );
  }

  return image_type;
}


#ifdef image_type_MAIN

void test_image_type(int include_optional) {
    image_type_t* image_type_1 = instantiate_image_type(include_optional);

	cJSON* jsonimage_type_1 = image_type_convertToJSON(image_type_1);
	printf("image_type :\n%s\n", cJSON_Print(jsonimage_type_1));
	image_type_t* image_type_2 = image_type_parseFromJSON(jsonimage_type_1);
	cJSON* jsonimage_type_2 = image_type_convertToJSON(image_type_2);
	printf("repeating image_type:\n%s\n", cJSON_Print(jsonimage_type_2));
}

int main() {
  test_image_type(1);
  test_image_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_type_MAIN
#endif // image_type_TEST
