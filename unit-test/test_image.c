#ifndef image_TEST
#define image_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define image_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/image.h"
image_t* instantiate_image(int include_optional);



image_t* instantiate_image(int include_optional) {
  image_t* image = NULL;
  if (include_optional) {
    image = image_create(
      "active",
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "firmware.ipsw",
      corellium_api_image__fwbinary,
      2147483648,
      "9e107d9d372bb6826bd81d3542a419d6",
      "sha256$1048576$e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
      corellium_api_image__plain,
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    image = image_create(
      "active",
      "3e1354a3-fb10-46c0-8b05-56e28edbde69",
      "firmware.ipsw",
      corellium_api_image__fwbinary,
      2147483648,
      "9e107d9d372bb6826bd81d3542a419d6",
      "sha256$1048576$e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
      corellium_api_image__plain,
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return image;
}


#ifdef image_MAIN

void test_image(int include_optional) {
    image_t* image_1 = instantiate_image(include_optional);

	cJSON* jsonimage_1 = image_convertToJSON(image_1);
	printf("image :\n%s\n", cJSON_Print(jsonimage_1));
	image_t* image_2 = image_parseFromJSON(jsonimage_1);
	cJSON* jsonimage_2 = image_convertToJSON(image_2);
	printf("repeating image:\n%s\n", cJSON_Print(jsonimage_2));
}

int main() {
  test_image(1);
  test_image(0);

  printf("Hello world \n");
  return 0;
}

#endif // image_MAIN
#endif // image_TEST
