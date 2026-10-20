#ifndef image_encoding_TEST
#define image_encoding_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_encoding_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_encoding.h"
image_encoding_t* instantiate_image_encoding(int include_optional);



image_encoding_t* instantiate_image_encoding(int include_optional) {
  image_encoding_t* image_encoding = NULL;
  if (include_optional) {
    image_encoding = image_encoding_create(
    );
  } else {
    image_encoding = image_encoding_create(
    );
  }

  return image_encoding;
}


#ifdef image_encoding_MAIN

void test_image_encoding(int include_optional) {
    image_encoding_t* image_encoding_1 = instantiate_image_encoding(include_optional);

	cJSON* jsonimage_encoding_1 = image_encoding_convertToJSON(image_encoding_1);
	printf("image_encoding :\n%s\n", cJSON_Print(jsonimage_encoding_1));
	image_encoding_t* image_encoding_2 = image_encoding_parseFromJSON(jsonimage_encoding_1);
	cJSON* jsonimage_encoding_2 = image_encoding_convertToJSON(image_encoding_2);
	printf("repeating image_encoding:\n%s\n", cJSON_Print(jsonimage_encoding_2));
}

int main() {
  test_image_encoding(1);
  test_image_encoding(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_encoding_MAIN
#endif // image_encoding_TEST
