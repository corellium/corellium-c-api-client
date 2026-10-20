#ifndef media_play_body_v1_TEST
#define media_play_body_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define media_play_body_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/media_play_body_v1.h"
media_play_body_v1_t* instantiate_media_play_body_v1(int include_optional);



media_play_body_v1_t* instantiate_media_play_body_v1(int include_optional) {
  media_play_body_v1_t* media_play_body_v1 = NULL;
  if (include_optional) {
    media_play_body_v1 = media_play_body_v1_create(
      "0",
      "0"
    );
  } else {
    media_play_body_v1 = media_play_body_v1_create(
      "0",
      "0"
    );
  }

  return media_play_body_v1;
}


#ifdef media_play_body_v1_MAIN

void test_media_play_body_v1(int include_optional) {
    media_play_body_v1_t* media_play_body_v1_1 = instantiate_media_play_body_v1(include_optional);

	cJSON* jsonmedia_play_body_v1_1 = media_play_body_v1_convertToJSON(media_play_body_v1_1);
	printf("media_play_body_v1 :\n%s\n", cJSON_Print(jsonmedia_play_body_v1_1));
	media_play_body_v1_t* media_play_body_v1_2 = media_play_body_v1_parseFromJSON(jsonmedia_play_body_v1_1);
	cJSON* jsonmedia_play_body_v1_2 = media_play_body_v1_convertToJSON(media_play_body_v1_2);
	printf("repeating media_play_body_v1:\n%s\n", cJSON_Print(jsonmedia_play_body_v1_2));
}

int main() {
  test_media_play_body_v1(1);
  test_media_play_body_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // media_play_body_v1_MAIN
#endif // media_play_body_v1_TEST
