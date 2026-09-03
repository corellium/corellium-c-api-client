#ifndef media_play_by_url_TEST
#define media_play_by_url_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define media_play_by_url_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/media_play_by_url.h"
media_play_by_url_t* instantiate_media_play_by_url(int include_optional);



media_play_by_url_t* instantiate_media_play_by_url(int include_optional) {
  media_play_by_url_t* media_play_by_url = NULL;
  if (include_optional) {
    media_play_by_url = media_play_by_url_create(
      "0"
    );
  } else {
    media_play_by_url = media_play_by_url_create(
      "0"
    );
  }

  return media_play_by_url;
}


#ifdef media_play_by_url_MAIN

void test_media_play_by_url(int include_optional) {
    media_play_by_url_t* media_play_by_url_1 = instantiate_media_play_by_url(include_optional);

	cJSON* jsonmedia_play_by_url_1 = media_play_by_url_convertToJSON(media_play_by_url_1);
	printf("media_play_by_url :\n%s\n", cJSON_Print(jsonmedia_play_by_url_1));
	media_play_by_url_t* media_play_by_url_2 = media_play_by_url_parseFromJSON(jsonmedia_play_by_url_1);
	cJSON* jsonmedia_play_by_url_2 = media_play_by_url_convertToJSON(media_play_by_url_2);
	printf("repeating media_play_by_url:\n%s\n", cJSON_Print(jsonmedia_play_by_url_2));
}

int main() {
  test_media_play_by_url(1);
  test_media_play_by_url(0);

  printf("Hello world \n");
  return 0;
}

#endif // media_play_by_url_MAIN
#endif // media_play_by_url_TEST
