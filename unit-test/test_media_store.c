#ifndef media_store_TEST
#define media_store_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define media_store_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/media_store.h"
media_store_t* instantiate_media_store(int include_optional);



media_store_t* instantiate_media_store(int include_optional) {
  media_store_t* media_store = NULL;
  if (include_optional) {
    media_store = media_store_create(
      "73357171-23a0-4a3e-8661-216dbfbdd7ab",
      "/dev/sdb1",
      "ext4",
      "4a3f2e1d-8c7b-4a19-9e2f-6d5c4b3a2190",
      "EXTERNAL_SSD",
      "0123456789ABCDEF",
      "SanDisk",
      "Ultra USB 3.0",
      corellium_api_media_store_MOUNTPOLICY_RO,
      corellium_api_media_store_STATUS_mounted,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    media_store = media_store_create(
      "73357171-23a0-4a3e-8661-216dbfbdd7ab",
      "/dev/sdb1",
      "ext4",
      "4a3f2e1d-8c7b-4a19-9e2f-6d5c4b3a2190",
      "EXTERNAL_SSD",
      "0123456789ABCDEF",
      "SanDisk",
      "Ultra USB 3.0",
      corellium_api_media_store_MOUNTPOLICY_RO,
      corellium_api_media_store_STATUS_mounted,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return media_store;
}


#ifdef media_store_MAIN

void test_media_store(int include_optional) {
    media_store_t* media_store_1 = instantiate_media_store(include_optional);

	cJSON* jsonmedia_store_1 = media_store_convertToJSON(media_store_1);
	printf("media_store :\n%s\n", cJSON_Print(jsonmedia_store_1));
	media_store_t* media_store_2 = media_store_parseFromJSON(jsonmedia_store_1);
	cJSON* jsonmedia_store_2 = media_store_convertToJSON(media_store_2);
	printf("repeating media_store:\n%s\n", cJSON_Print(jsonmedia_store_2));
}

int main() {
  test_media_store(1);
  test_media_store(0);

  printf("Hello world \n");
  return 0;
}

#endif // media_store_MAIN
#endif // media_store_TEST
