#ifndef image_firmware_TEST
#define image_firmware_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_firmware_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_firmware.h"
image_firmware_t* instantiate_image_firmware(int include_optional);



image_firmware_t* instantiate_image_firmware(int include_optional) {
  image_firmware_t* image_firmware = NULL;
  if (include_optional) {
    image_firmware = image_firmware_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    image_firmware = image_firmware_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return image_firmware;
}


#ifdef image_firmware_MAIN

void test_image_firmware(int include_optional) {
    image_firmware_t* image_firmware_1 = instantiate_image_firmware(include_optional);

	cJSON* jsonimage_firmware_1 = image_firmware_convertToJSON(image_firmware_1);
	printf("image_firmware :\n%s\n", cJSON_Print(jsonimage_firmware_1));
	image_firmware_t* image_firmware_2 = image_firmware_parseFromJSON(jsonimage_firmware_1);
	cJSON* jsonimage_firmware_2 = image_firmware_convertToJSON(image_firmware_2);
	printf("repeating image_firmware:\n%s\n", cJSON_Print(jsonimage_firmware_2));
}

int main() {
  test_image_firmware(1);
  test_image_firmware(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_firmware_MAIN
#endif // image_firmware_TEST
