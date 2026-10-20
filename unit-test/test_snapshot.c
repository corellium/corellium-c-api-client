#ifndef snapshot_TEST
#define snapshot_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot.h"
snapshot_t* instantiate_snapshot(int include_optional);

#include "test_snapshot_status.c"
#include "test_snapshot_sharing.c"


snapshot_t* instantiate_snapshot(int include_optional) {
  snapshot_t* snapshot = NULL;
  if (include_optional) {
    snapshot = snapshot_create(
      "c67af9c0-26cd-4233-9782-436c842b60db",
      "Clean boot",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
       // false, not to have infinite recursion
      instantiate_snapshot_status(0),
      1773479567000,
      true,
      false,
      true,
      "iPhone 13 Pro",
       // false, not to have infinite recursion
      instantiate_snapshot_sharing(0)
    );
  } else {
    snapshot = snapshot_create(
      "c67af9c0-26cd-4233-9782-436c842b60db",
      "Clean boot",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      NULL,
      1773479567000,
      true,
      false,
      true,
      "iPhone 13 Pro",
      NULL
    );
  }

  return snapshot;
}


#ifdef snapshot_MAIN

void test_snapshot(int include_optional) {
    snapshot_t* snapshot_1 = instantiate_snapshot(include_optional);

	cJSON* jsonsnapshot_1 = snapshot_convertToJSON(snapshot_1);
	printf("snapshot :\n%s\n", cJSON_Print(jsonsnapshot_1));
	snapshot_t* snapshot_2 = snapshot_parseFromJSON(jsonsnapshot_1);
	cJSON* jsonsnapshot_2 = snapshot_convertToJSON(snapshot_2);
	printf("repeating snapshot:\n%s\n", cJSON_Print(jsonsnapshot_2));
}

int main() {
  test_snapshot(1);
  test_snapshot(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_MAIN
#endif // snapshot_TEST
