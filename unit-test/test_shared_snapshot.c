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

#include "test_snapshot_owner_schema.c"
#include "test_snapshot_status_schema.c"
#include "test_snapshot_sharing.c"


shared_snapshot_t* instantiate_shared_snapshot(int include_optional) {
  shared_snapshot_t* shared_snapshot = NULL;
  if (include_optional) {
    shared_snapshot = shared_snapshot_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      corellium_api_shared_snapshot_SHARINGTYPE_publicLink,
       // false, not to have infinite recursion
      instantiate_snapshot_owner_schema(0),
      "0",
      1.337,
      1.337,
      "0",
      1,
      1,
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_snapshot_status_schema(0),
      1,
       // false, not to have infinite recursion
      instantiate_snapshot_sharing(0)
    );
  } else {
    shared_snapshot = shared_snapshot_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      corellium_api_shared_snapshot_SHARINGTYPE_publicLink,
      NULL,
      "0",
      1.337,
      1.337,
      "0",
      1,
      1,
      "0",
      "0",
      "0",
      NULL,
      1,
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
