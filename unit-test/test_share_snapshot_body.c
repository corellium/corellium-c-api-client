#ifndef share_snapshot_body_TEST
#define share_snapshot_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define share_snapshot_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/share_snapshot_body.h"
share_snapshot_body_t* instantiate_share_snapshot_body(int include_optional);



share_snapshot_body_t* instantiate_share_snapshot_body(int include_optional) {
  share_snapshot_body_t* share_snapshot_body = NULL;
  if (include_optional) {
    share_snapshot_body = share_snapshot_body_create(
      corellium_api_share_snapshot_body__publicLink,
      "0"
    );
  } else {
    share_snapshot_body = share_snapshot_body_create(
      corellium_api_share_snapshot_body__publicLink,
      "0"
    );
  }

  return share_snapshot_body;
}


#ifdef share_snapshot_body_MAIN

void test_share_snapshot_body(int include_optional) {
    share_snapshot_body_t* share_snapshot_body_1 = instantiate_share_snapshot_body(include_optional);

	cJSON* jsonshare_snapshot_body_1 = share_snapshot_body_convertToJSON(share_snapshot_body_1);
	printf("share_snapshot_body :\n%s\n", cJSON_Print(jsonshare_snapshot_body_1));
	share_snapshot_body_t* share_snapshot_body_2 = share_snapshot_body_parseFromJSON(jsonshare_snapshot_body_1);
	cJSON* jsonshare_snapshot_body_2 = share_snapshot_body_convertToJSON(share_snapshot_body_2);
	printf("repeating share_snapshot_body:\n%s\n", cJSON_Print(jsonshare_snapshot_body_2));
}

int main() {
  test_share_snapshot_body(1);
  test_share_snapshot_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // share_snapshot_body_MAIN
#endif // share_snapshot_body_TEST
