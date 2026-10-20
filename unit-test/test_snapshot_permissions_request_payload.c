#ifndef snapshot_permissions_request_payload_TEST
#define snapshot_permissions_request_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_permissions_request_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_permissions_request_payload.h"
snapshot_permissions_request_payload_t* instantiate_snapshot_permissions_request_payload(int include_optional);



snapshot_permissions_request_payload_t* instantiate_snapshot_permissions_request_payload(int include_optional) {
  snapshot_permissions_request_payload_t* snapshot_permissions_request_payload = NULL;
  if (include_optional) {
    snapshot_permissions_request_payload = snapshot_permissions_request_payload_create(
      list_createList()
    );
  } else {
    snapshot_permissions_request_payload = snapshot_permissions_request_payload_create(
      list_createList()
    );
  }

  return snapshot_permissions_request_payload;
}


#ifdef snapshot_permissions_request_payload_MAIN

void test_snapshot_permissions_request_payload(int include_optional) {
    snapshot_permissions_request_payload_t* snapshot_permissions_request_payload_1 = instantiate_snapshot_permissions_request_payload(include_optional);

	cJSON* jsonsnapshot_permissions_request_payload_1 = snapshot_permissions_request_payload_convertToJSON(snapshot_permissions_request_payload_1);
	printf("snapshot_permissions_request_payload :\n%s\n", cJSON_Print(jsonsnapshot_permissions_request_payload_1));
	snapshot_permissions_request_payload_t* snapshot_permissions_request_payload_2 = snapshot_permissions_request_payload_parseFromJSON(jsonsnapshot_permissions_request_payload_1);
	cJSON* jsonsnapshot_permissions_request_payload_2 = snapshot_permissions_request_payload_convertToJSON(snapshot_permissions_request_payload_2);
	printf("repeating snapshot_permissions_request_payload:\n%s\n", cJSON_Print(jsonsnapshot_permissions_request_payload_2));
}

int main() {
  test_snapshot_permissions_request_payload(1);
  test_snapshot_permissions_request_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_permissions_request_payload_MAIN
#endif // snapshot_permissions_request_payload_TEST
