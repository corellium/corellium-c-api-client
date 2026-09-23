#ifndef image_list_TEST
#define image_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_list.h"
image_list_t* instantiate_image_list(int include_optional);



image_list_t* instantiate_image_list(int include_optional) {
  image_list_t* image_list = NULL;
  if (include_optional) {
    image_list = image_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    image_list = image_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return image_list;
}


#ifdef image_list_MAIN

void test_image_list(int include_optional) {
    image_list_t* image_list_1 = instantiate_image_list(include_optional);

	cJSON* jsonimage_list_1 = image_list_convertToJSON(image_list_1);
	printf("image_list :\n%s\n", cJSON_Print(jsonimage_list_1));
	image_list_t* image_list_2 = image_list_parseFromJSON(jsonimage_list_1);
	cJSON* jsonimage_list_2 = image_list_convertToJSON(image_list_2);
	printf("repeating image_list:\n%s\n", cJSON_Print(jsonimage_list_2));
}

int main() {
  test_image_list(1);
  test_image_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_list_MAIN
#endif // image_list_TEST
