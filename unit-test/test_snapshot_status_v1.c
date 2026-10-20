#ifndef snapshot_status_v1_TEST
#define snapshot_status_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_status_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_status_v1.h"
snapshot_status_v1_t* instantiate_snapshot_status_v1(int include_optional);



snapshot_status_v1_t* instantiate_snapshot_status_v1(int include_optional) {
  snapshot_status_v1_t* snapshot_status_v1 = NULL;
  if (include_optional) {
    snapshot_status_v1 = snapshot_status_v1_create(
      "0",
      1
    );
  } else {
    snapshot_status_v1 = snapshot_status_v1_create(
      "0",
      1
    );
  }

  return snapshot_status_v1;
}


#ifdef snapshot_status_v1_MAIN

void test_snapshot_status_v1(int include_optional) {
    snapshot_status_v1_t* snapshot_status_v1_1 = instantiate_snapshot_status_v1(include_optional);

	cJSON* jsonsnapshot_status_v1_1 = snapshot_status_v1_convertToJSON(snapshot_status_v1_1);
	printf("snapshot_status_v1 :\n%s\n", cJSON_Print(jsonsnapshot_status_v1_1));
	snapshot_status_v1_t* snapshot_status_v1_2 = snapshot_status_v1_parseFromJSON(jsonsnapshot_status_v1_1);
	cJSON* jsonsnapshot_status_v1_2 = snapshot_status_v1_convertToJSON(snapshot_status_v1_2);
	printf("repeating snapshot_status_v1:\n%s\n", cJSON_Print(jsonsnapshot_status_v1_2));
}

int main() {
  test_snapshot_status_v1(1);
  test_snapshot_status_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_status_v1_MAIN
#endif // snapshot_status_v1_TEST
