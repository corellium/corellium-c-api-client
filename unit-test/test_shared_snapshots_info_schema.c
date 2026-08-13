#ifndef shared_snapshots_info_schema_TEST
#define shared_snapshots_info_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shared_snapshots_info_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shared_snapshots_info_schema.h"
shared_snapshots_info_schema_t* instantiate_shared_snapshots_info_schema(int include_optional);

#include "test_snapshot_owner_schema.c"
#include "test_snapshot_status_schema.c"
#include "test_snapshot_sharing.c"


shared_snapshots_info_schema_t* instantiate_shared_snapshots_info_schema(int include_optional) {
  shared_snapshots_info_schema_t* shared_snapshots_info_schema = NULL;
  if (include_optional) {
    shared_snapshots_info_schema = shared_snapshots_info_schema_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      corellium_api_shared_snapshots_info_schema_SHARINGTYPE_publicLink,
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
    shared_snapshots_info_schema = shared_snapshots_info_schema_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      corellium_api_shared_snapshots_info_schema_SHARINGTYPE_publicLink,
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

  return shared_snapshots_info_schema;
}


#ifdef shared_snapshots_info_schema_MAIN

void test_shared_snapshots_info_schema(int include_optional) {
    shared_snapshots_info_schema_t* shared_snapshots_info_schema_1 = instantiate_shared_snapshots_info_schema(include_optional);

	cJSON* jsonshared_snapshots_info_schema_1 = shared_snapshots_info_schema_convertToJSON(shared_snapshots_info_schema_1);
	printf("shared_snapshots_info_schema :\n%s\n", cJSON_Print(jsonshared_snapshots_info_schema_1));
	shared_snapshots_info_schema_t* shared_snapshots_info_schema_2 = shared_snapshots_info_schema_parseFromJSON(jsonshared_snapshots_info_schema_1);
	cJSON* jsonshared_snapshots_info_schema_2 = shared_snapshots_info_schema_convertToJSON(shared_snapshots_info_schema_2);
	printf("repeating shared_snapshots_info_schema:\n%s\n", cJSON_Print(jsonshared_snapshots_info_schema_2));
}

int main() {
  test_shared_snapshots_info_schema(1);
  test_shared_snapshots_info_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // shared_snapshots_info_schema_MAIN
#endif // shared_snapshots_info_schema_TEST
