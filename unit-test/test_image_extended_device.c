#ifndef image_extended_device_TEST
#define image_extended_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_extended_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_extended_device.h"
image_extended_device_t* instantiate_image_extended_device(int include_optional);



image_extended_device_t* instantiate_image_extended_device(int include_optional) {
  image_extended_device_t* image_extended_device = NULL;
  if (include_optional) {
    image_extended_device = image_extended_device_create(
      "0",
      list_createList()
    );
  } else {
    image_extended_device = image_extended_device_create(
      "0",
      list_createList()
    );
  }

  return image_extended_device;
}


#ifdef image_extended_device_MAIN

void test_image_extended_device(int include_optional) {
    image_extended_device_t* image_extended_device_1 = instantiate_image_extended_device(include_optional);

	cJSON* jsonimage_extended_device_1 = image_extended_device_convertToJSON(image_extended_device_1);
	printf("image_extended_device :\n%s\n", cJSON_Print(jsonimage_extended_device_1));
	image_extended_device_t* image_extended_device_2 = image_extended_device_parseFromJSON(jsonimage_extended_device_1);
	cJSON* jsonimage_extended_device_2 = image_extended_device_convertToJSON(image_extended_device_2);
	printf("repeating image_extended_device:\n%s\n", cJSON_Print(jsonimage_extended_device_2));
}

int main() {
  test_image_extended_device(1);
  test_image_extended_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_extended_device_MAIN
#endif // image_extended_device_TEST
