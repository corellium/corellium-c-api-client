#ifndef snapshot_sharing_TEST
#define snapshot_sharing_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_sharing_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_sharing.h"
snapshot_sharing_t* instantiate_snapshot_sharing(int include_optional);

#include "test_snapshot_owner_schema.c"


snapshot_sharing_t* instantiate_snapshot_sharing(int include_optional) {
  snapshot_sharing_t* snapshot_sharing = NULL;
  if (include_optional) {
    snapshot_sharing = snapshot_sharing_create(
      corellium_api_snapshot_sharing__publicLink,
      "0",
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_snapshot_owner_schema(0),
      list_createList()
    );
  } else {
    snapshot_sharing = snapshot_sharing_create(
      corellium_api_snapshot_sharing__publicLink,
      "0",
      "2013-10-20T19:20:30+01:00",
      NULL,
      list_createList()
    );
  }

  return snapshot_sharing;
}


#ifdef snapshot_sharing_MAIN

void test_snapshot_sharing(int include_optional) {
    snapshot_sharing_t* snapshot_sharing_1 = instantiate_snapshot_sharing(include_optional);

	cJSON* jsonsnapshot_sharing_1 = snapshot_sharing_convertToJSON(snapshot_sharing_1);
	printf("snapshot_sharing :\n%s\n", cJSON_Print(jsonsnapshot_sharing_1));
	snapshot_sharing_t* snapshot_sharing_2 = snapshot_sharing_parseFromJSON(jsonsnapshot_sharing_1);
	cJSON* jsonsnapshot_sharing_2 = snapshot_sharing_convertToJSON(snapshot_sharing_2);
	printf("repeating snapshot_sharing:\n%s\n", cJSON_Print(jsonsnapshot_sharing_2));
}

int main() {
  test_snapshot_sharing(1);
  test_snapshot_sharing(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_sharing_MAIN
#endif // snapshot_sharing_TEST
