#ifndef snapshot_sharing_v1_TEST
#define snapshot_sharing_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_sharing_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_sharing_v1.h"
snapshot_sharing_v1_t* instantiate_snapshot_sharing_v1(int include_optional);

#include "test_snapshot_owner_v1.c"


snapshot_sharing_v1_t* instantiate_snapshot_sharing_v1(int include_optional) {
  snapshot_sharing_v1_t* snapshot_sharing_v1 = NULL;
  if (include_optional) {
    snapshot_sharing_v1 = snapshot_sharing_v1_create(
      corellium_api_snapshot_sharing_v1_SHARINGTYPE_publicLink,
       // false, not to have infinite recursion
      instantiate_snapshot_owner_v1(0),
      list_createList()
    );
  } else {
    snapshot_sharing_v1 = snapshot_sharing_v1_create(
      corellium_api_snapshot_sharing_v1_SHARINGTYPE_publicLink,
      NULL,
      list_createList()
    );
  }

  return snapshot_sharing_v1;
}


#ifdef snapshot_sharing_v1_MAIN

void test_snapshot_sharing_v1(int include_optional) {
    snapshot_sharing_v1_t* snapshot_sharing_v1_1 = instantiate_snapshot_sharing_v1(include_optional);

	cJSON* jsonsnapshot_sharing_v1_1 = snapshot_sharing_v1_convertToJSON(snapshot_sharing_v1_1);
	printf("snapshot_sharing_v1 :\n%s\n", cJSON_Print(jsonsnapshot_sharing_v1_1));
	snapshot_sharing_v1_t* snapshot_sharing_v1_2 = snapshot_sharing_v1_parseFromJSON(jsonsnapshot_sharing_v1_1);
	cJSON* jsonsnapshot_sharing_v1_2 = snapshot_sharing_v1_convertToJSON(snapshot_sharing_v1_2);
	printf("repeating snapshot_sharing_v1:\n%s\n", cJSON_Print(jsonsnapshot_sharing_v1_2));
}

int main() {
  test_snapshot_sharing_v1(1);
  test_snapshot_sharing_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_sharing_v1_MAIN
#endif // snapshot_sharing_v1_TEST
