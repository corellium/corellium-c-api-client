#ifndef image_firmware_info_TEST
#define image_firmware_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_firmware_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_firmware_info.h"
image_firmware_info_t* instantiate_image_firmware_info(int include_optional);

#include "test_image_firmware_info_boot_args.c"
#include "test_firmware_info_device.c"


image_firmware_info_t* instantiate_image_firmware_info(int include_optional) {
  image_firmware_info_t* image_firmware_info = NULL;
  if (include_optional) {
    image_firmware_info = image_firmware_info_create(
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      1.337,
      1.337,
      "0",
       // false, not to have infinite recursion
      instantiate_image_firmware_info_boot_args(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_firmware_info_device(0)
    );
  } else {
    image_firmware_info = image_firmware_info_create(
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      1.337,
      1.337,
      "0",
      NULL,
      list_createList(),
      NULL
    );
  }

  return image_firmware_info;
}


#ifdef image_firmware_info_MAIN

void test_image_firmware_info(int include_optional) {
    image_firmware_info_t* image_firmware_info_1 = instantiate_image_firmware_info(include_optional);

	cJSON* jsonimage_firmware_info_1 = image_firmware_info_convertToJSON(image_firmware_info_1);
	printf("image_firmware_info :\n%s\n", cJSON_Print(jsonimage_firmware_info_1));
	image_firmware_info_t* image_firmware_info_2 = image_firmware_info_parseFromJSON(jsonimage_firmware_info_1);
	cJSON* jsonimage_firmware_info_2 = image_firmware_info_convertToJSON(image_firmware_info_2);
	printf("repeating image_firmware_info:\n%s\n", cJSON_Print(jsonimage_firmware_info_2));
}

int main() {
  test_image_firmware_info(1);
  test_image_firmware_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_firmware_info_MAIN
#endif // image_firmware_info_TEST
