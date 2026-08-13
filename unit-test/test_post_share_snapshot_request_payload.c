#ifndef post_share_snapshot_request_payload_TEST
#define post_share_snapshot_request_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define post_share_snapshot_request_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/post_share_snapshot_request_payload.h"
post_share_snapshot_request_payload_t* instantiate_post_share_snapshot_request_payload(int include_optional);



post_share_snapshot_request_payload_t* instantiate_post_share_snapshot_request_payload(int include_optional) {
  post_share_snapshot_request_payload_t* post_share_snapshot_request_payload = NULL;
  if (include_optional) {
    post_share_snapshot_request_payload = post_share_snapshot_request_payload_create(
      "0",
      "0"
    );
  } else {
    post_share_snapshot_request_payload = post_share_snapshot_request_payload_create(
      "0",
      "0"
    );
  }

  return post_share_snapshot_request_payload;
}


#ifdef post_share_snapshot_request_payload_MAIN

void test_post_share_snapshot_request_payload(int include_optional) {
    post_share_snapshot_request_payload_t* post_share_snapshot_request_payload_1 = instantiate_post_share_snapshot_request_payload(include_optional);

	cJSON* jsonpost_share_snapshot_request_payload_1 = post_share_snapshot_request_payload_convertToJSON(post_share_snapshot_request_payload_1);
	printf("post_share_snapshot_request_payload :\n%s\n", cJSON_Print(jsonpost_share_snapshot_request_payload_1));
	post_share_snapshot_request_payload_t* post_share_snapshot_request_payload_2 = post_share_snapshot_request_payload_parseFromJSON(jsonpost_share_snapshot_request_payload_1);
	cJSON* jsonpost_share_snapshot_request_payload_2 = post_share_snapshot_request_payload_convertToJSON(post_share_snapshot_request_payload_2);
	printf("repeating post_share_snapshot_request_payload:\n%s\n", cJSON_Print(jsonpost_share_snapshot_request_payload_2));
}

int main() {
  test_post_share_snapshot_request_payload(1);
  test_post_share_snapshot_request_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // post_share_snapshot_request_payload_MAIN
#endif // post_share_snapshot_request_payload_TEST
