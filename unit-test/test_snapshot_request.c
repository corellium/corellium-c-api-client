#ifndef snapshot_request_TEST
#define snapshot_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_request.h"
snapshot_request_t* instantiate_snapshot_request(int include_optional);



snapshot_request_t* instantiate_snapshot_request(int include_optional) {
  snapshot_request_t* snapshot_request = NULL;
  if (include_optional) {
    snapshot_request = snapshot_request_create(
      1.337,
      1.337,
      1,
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    snapshot_request = snapshot_request_create(
      1.337,
      1.337,
      1,
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return snapshot_request;
}


#ifdef snapshot_request_MAIN

void test_snapshot_request(int include_optional) {
    snapshot_request_t* snapshot_request_1 = instantiate_snapshot_request(include_optional);

	cJSON* jsonsnapshot_request_1 = snapshot_request_convertToJSON(snapshot_request_1);
	printf("snapshot_request :\n%s\n", cJSON_Print(jsonsnapshot_request_1));
	snapshot_request_t* snapshot_request_2 = snapshot_request_parseFromJSON(jsonsnapshot_request_1);
	cJSON* jsonsnapshot_request_2 = snapshot_request_convertToJSON(snapshot_request_2);
	printf("repeating snapshot_request:\n%s\n", cJSON_Print(jsonsnapshot_request_2));
}

int main() {
  test_snapshot_request(1);
  test_snapshot_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_request_MAIN
#endif // snapshot_request_TEST
