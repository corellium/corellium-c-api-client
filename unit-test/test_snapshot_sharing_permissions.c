#ifndef snapshot_sharing_permissions_TEST
#define snapshot_sharing_permissions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_sharing_permissions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_sharing_permissions.h"
snapshot_sharing_permissions_t* instantiate_snapshot_sharing_permissions(int include_optional);



snapshot_sharing_permissions_t* instantiate_snapshot_sharing_permissions(int include_optional) {
  snapshot_sharing_permissions_t* snapshot_sharing_permissions = NULL;
  if (include_optional) {
    snapshot_sharing_permissions = snapshot_sharing_permissions_create(
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    snapshot_sharing_permissions = snapshot_sharing_permissions_create(
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return snapshot_sharing_permissions;
}


#ifdef snapshot_sharing_permissions_MAIN

void test_snapshot_sharing_permissions(int include_optional) {
    snapshot_sharing_permissions_t* snapshot_sharing_permissions_1 = instantiate_snapshot_sharing_permissions(include_optional);

	cJSON* jsonsnapshot_sharing_permissions_1 = snapshot_sharing_permissions_convertToJSON(snapshot_sharing_permissions_1);
	printf("snapshot_sharing_permissions :\n%s\n", cJSON_Print(jsonsnapshot_sharing_permissions_1));
	snapshot_sharing_permissions_t* snapshot_sharing_permissions_2 = snapshot_sharing_permissions_parseFromJSON(jsonsnapshot_sharing_permissions_1);
	cJSON* jsonsnapshot_sharing_permissions_2 = snapshot_sharing_permissions_convertToJSON(snapshot_sharing_permissions_2);
	printf("repeating snapshot_sharing_permissions:\n%s\n", cJSON_Print(jsonsnapshot_sharing_permissions_2));
}

int main() {
  test_snapshot_sharing_permissions(1);
  test_snapshot_sharing_permissions(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_sharing_permissions_MAIN
#endif // snapshot_sharing_permissions_TEST
