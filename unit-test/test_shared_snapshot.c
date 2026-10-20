#ifndef shared_snapshot_TEST
#define shared_snapshot_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shared_snapshot_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shared_snapshot.h"
shared_snapshot_t* instantiate_shared_snapshot(int include_optional);

#include "test_snapshot_owner.c"
#include "test_snapshot_status.c"
#include "test_snapshot_sharing.c"


shared_snapshot_t* instantiate_shared_snapshot(int include_optional) {
  shared_snapshot_t* shared_snapshot = NULL;
  if (include_optional) {
    shared_snapshot = shared_snapshot_create(
      "2026-03-16T08:22:19Z",
      "jane.doe@example.com",
      corellium_api_shared_snapshot__publicLink,
       // false, not to have infinite recursion
      instantiate_snapshot_owner(0),
      "c67af9c0-26cd-4233-9782-436c842b60db",
      1773479567000,
      1,
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      false,
      true,
      "0",
      "ios",
      "Clean boot",
       // false, not to have infinite recursion
      instantiate_snapshot_status(0),
      true,
       // false, not to have infinite recursion
      instantiate_snapshot_sharing(0)
    );
  } else {
    shared_snapshot = shared_snapshot_create(
      "2026-03-16T08:22:19Z",
      "jane.doe@example.com",
      corellium_api_shared_snapshot__publicLink,
      NULL,
      "c67af9c0-26cd-4233-9782-436c842b60db",
      1773479567000,
      1,
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      false,
      true,
      "0",
      "ios",
      "Clean boot",
      NULL,
      true,
      NULL
    );
  }

  return shared_snapshot;
}


#ifdef shared_snapshot_MAIN

void test_shared_snapshot(int include_optional) {
    shared_snapshot_t* shared_snapshot_1 = instantiate_shared_snapshot(include_optional);

	cJSON* jsonshared_snapshot_1 = shared_snapshot_convertToJSON(shared_snapshot_1);
	printf("shared_snapshot :\n%s\n", cJSON_Print(jsonshared_snapshot_1));
	shared_snapshot_t* shared_snapshot_2 = shared_snapshot_parseFromJSON(jsonshared_snapshot_1);
	cJSON* jsonshared_snapshot_2 = shared_snapshot_convertToJSON(shared_snapshot_2);
	printf("repeating shared_snapshot:\n%s\n", cJSON_Print(jsonshared_snapshot_2));
}

int main() {
  test_shared_snapshot(1);
  test_shared_snapshot(0);

  printf("Hello world \n");
  return 0;
}

#endif // shared_snapshot_MAIN
#endif // shared_snapshot_TEST
