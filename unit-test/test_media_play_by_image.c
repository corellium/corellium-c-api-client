#ifndef media_play_by_image_TEST
#define media_play_by_image_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define media_play_by_image_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/media_play_by_image.h"
media_play_by_image_t* instantiate_media_play_by_image(int include_optional);



media_play_by_image_t* instantiate_media_play_by_image(int include_optional) {
  media_play_by_image_t* media_play_by_image = NULL;
  if (include_optional) {
    media_play_by_image = media_play_by_image_create(
      "0"
    );
  } else {
    media_play_by_image = media_play_by_image_create(
      "0"
    );
  }

  return media_play_by_image;
}


#ifdef media_play_by_image_MAIN

void test_media_play_by_image(int include_optional) {
    media_play_by_image_t* media_play_by_image_1 = instantiate_media_play_by_image(include_optional);

	cJSON* jsonmedia_play_by_image_1 = media_play_by_image_convertToJSON(media_play_by_image_1);
	printf("media_play_by_image :\n%s\n", cJSON_Print(jsonmedia_play_by_image_1));
	media_play_by_image_t* media_play_by_image_2 = media_play_by_image_parseFromJSON(jsonmedia_play_by_image_1);
	cJSON* jsonmedia_play_by_image_2 = media_play_by_image_convertToJSON(media_play_by_image_2);
	printf("repeating media_play_by_image:\n%s\n", cJSON_Print(jsonmedia_play_by_image_2));
}

int main() {
  test_media_play_by_image(1);
  test_media_play_by_image(0);

  printf("Hello world \n");
  return 0;
}

#endif // media_play_by_image_MAIN
#endif // media_play_by_image_TEST
