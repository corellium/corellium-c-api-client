#ifndef snapshot_v1_TEST
#define snapshot_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_v1.h"
snapshot_v1_t* instantiate_snapshot_v1(int include_optional);

#include "test_snapshot_status.c"
#include "test_snapshot_sharing_v1.c"


snapshot_v1_t* instantiate_snapshot_v1(int include_optional) {
  snapshot_v1_t* snapshot_v1 = NULL;
  if (include_optional) {
    snapshot_v1 = snapshot_v1_create(
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_snapshot_status(0),
      1.337,
      1,
      1,
      1,
      "0",
       // false, not to have infinite recursion
      instantiate_snapshot_sharing_v1(0)
    );
  } else {
    snapshot_v1 = snapshot_v1_create(
      "0",
      "0",
      "0",
      NULL,
      1.337,
      1,
      1,
      1,
      "0",
      NULL
    );
  }

  return snapshot_v1;
}


#ifdef snapshot_v1_MAIN

void test_snapshot_v1(int include_optional) {
    snapshot_v1_t* snapshot_v1_1 = instantiate_snapshot_v1(include_optional);

	cJSON* jsonsnapshot_v1_1 = snapshot_v1_convertToJSON(snapshot_v1_1);
	printf("snapshot_v1 :\n%s\n", cJSON_Print(jsonsnapshot_v1_1));
	snapshot_v1_t* snapshot_v1_2 = snapshot_v1_parseFromJSON(jsonsnapshot_v1_1);
	cJSON* jsonsnapshot_v1_2 = snapshot_v1_convertToJSON(snapshot_v1_2);
	printf("repeating snapshot_v1:\n%s\n", cJSON_Print(jsonsnapshot_v1_2));
}

int main() {
  test_snapshot_v1(1);
  test_snapshot_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_v1_MAIN
#endif // snapshot_v1_TEST
