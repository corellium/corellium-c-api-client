#ifndef image_firmware_info_boot_args_TEST
#define image_firmware_info_boot_args_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_firmware_info_boot_args_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image_firmware_info_boot_args.h"
image_firmware_info_boot_args_t* instantiate_image_firmware_info_boot_args(int include_optional);



image_firmware_info_boot_args_t* instantiate_image_firmware_info_boot_args(int include_optional) {
  image_firmware_info_boot_args_t* image_firmware_info_boot_args = NULL;
  if (include_optional) {
    image_firmware_info_boot_args = image_firmware_info_boot_args_create(
      "rd=md0 -progress -no-battery nand-enable-reformat=1",
      "rd=md0 -restore -progress"
    );
  } else {
    image_firmware_info_boot_args = image_firmware_info_boot_args_create(
      "rd=md0 -progress -no-battery nand-enable-reformat=1",
      "rd=md0 -restore -progress"
    );
  }

  return image_firmware_info_boot_args;
}


#ifdef image_firmware_info_boot_args_MAIN

void test_image_firmware_info_boot_args(int include_optional) {
    image_firmware_info_boot_args_t* image_firmware_info_boot_args_1 = instantiate_image_firmware_info_boot_args(include_optional);

	cJSON* jsonimage_firmware_info_boot_args_1 = image_firmware_info_boot_args_convertToJSON(image_firmware_info_boot_args_1);
	printf("image_firmware_info_boot_args :\n%s\n", cJSON_Print(jsonimage_firmware_info_boot_args_1));
	image_firmware_info_boot_args_t* image_firmware_info_boot_args_2 = image_firmware_info_boot_args_parseFromJSON(jsonimage_firmware_info_boot_args_1);
	cJSON* jsonimage_firmware_info_boot_args_2 = image_firmware_info_boot_args_convertToJSON(image_firmware_info_boot_args_2);
	printf("repeating image_firmware_info_boot_args:\n%s\n", cJSON_Print(jsonimage_firmware_info_boot_args_2));
}

int main() {
  test_image_firmware_info_boot_args(1);
  test_image_firmware_info_boot_args(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_firmware_info_boot_args_MAIN
#endif // image_firmware_info_boot_args_TEST
