#ifndef accept_snapshot_request_payload_TEST
#define accept_snapshot_request_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accept_snapshot_request_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accept_snapshot_request_payload.h"
accept_snapshot_request_payload_t* instantiate_accept_snapshot_request_payload(int include_optional);



accept_snapshot_request_payload_t* instantiate_accept_snapshot_request_payload(int include_optional) {
  accept_snapshot_request_payload_t* accept_snapshot_request_payload = NULL;
  if (include_optional) {
    accept_snapshot_request_payload = accept_snapshot_request_payload_create(
      "0",
      "0"
    );
  } else {
    accept_snapshot_request_payload = accept_snapshot_request_payload_create(
      "0",
      "0"
    );
  }

  return accept_snapshot_request_payload;
}


#ifdef accept_snapshot_request_payload_MAIN

void test_accept_snapshot_request_payload(int include_optional) {
    accept_snapshot_request_payload_t* accept_snapshot_request_payload_1 = instantiate_accept_snapshot_request_payload(include_optional);

	cJSON* jsonaccept_snapshot_request_payload_1 = accept_snapshot_request_payload_convertToJSON(accept_snapshot_request_payload_1);
	printf("accept_snapshot_request_payload :\n%s\n", cJSON_Print(jsonaccept_snapshot_request_payload_1));
	accept_snapshot_request_payload_t* accept_snapshot_request_payload_2 = accept_snapshot_request_payload_parseFromJSON(jsonaccept_snapshot_request_payload_1);
	cJSON* jsonaccept_snapshot_request_payload_2 = accept_snapshot_request_payload_convertToJSON(accept_snapshot_request_payload_2);
	printf("repeating accept_snapshot_request_payload:\n%s\n", cJSON_Print(jsonaccept_snapshot_request_payload_2));
}

int main() {
  test_accept_snapshot_request_payload(1);
  test_accept_snapshot_request_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // accept_snapshot_request_payload_MAIN
#endif // accept_snapshot_request_payload_TEST
