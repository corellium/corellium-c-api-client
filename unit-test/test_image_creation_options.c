#ifndef image_creation_options_TEST
#define image_creation_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_creation_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_creation_options.h"
image_creation_options_t* instantiate_image_creation_options(int include_optional);



image_creation_options_t* instantiate_image_creation_options(int include_optional) {
  image_creation_options_t* image_creation_options = NULL;
  if (include_optional) {
    image_creation_options = image_creation_options_create(
      "0",
      corellium_api_image_creation_options_ENCODING_plain,
      1,
      "0",
      "0",
      "0",
      "0",
      instantiate_binary_t("blah", 5)
    );
  } else {
    image_creation_options = image_creation_options_create(
      "0",
      corellium_api_image_creation_options_ENCODING_plain,
      1,
      "0",
      "0",
      "0",
      "0",
      instantiate_binary_t("blah", 5)
    );
  }

  return image_creation_options;
}


#ifdef image_creation_options_MAIN

void test_image_creation_options(int include_optional) {
    image_creation_options_t* image_creation_options_1 = instantiate_image_creation_options(include_optional);

	cJSON* jsonimage_creation_options_1 = image_creation_options_convertToJSON(image_creation_options_1);
	printf("image_creation_options :\n%s\n", cJSON_Print(jsonimage_creation_options_1));
	image_creation_options_t* image_creation_options_2 = image_creation_options_parseFromJSON(jsonimage_creation_options_1);
	cJSON* jsonimage_creation_options_2 = image_creation_options_convertToJSON(image_creation_options_2);
	printf("repeating image_creation_options:\n%s\n", cJSON_Print(jsonimage_creation_options_2));
}

int main() {
  test_image_creation_options(1);
  test_image_creation_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_creation_options_MAIN
#endif // image_creation_options_TEST
