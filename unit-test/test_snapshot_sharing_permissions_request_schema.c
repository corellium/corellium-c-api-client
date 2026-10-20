#ifndef snapshot_sharing_permissions_request_schema_TEST
#define snapshot_sharing_permissions_request_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_sharing_permissions_request_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_sharing_permissions_request_schema.h"
snapshot_sharing_permissions_request_schema_t* instantiate_snapshot_sharing_permissions_request_schema(int include_optional);



snapshot_sharing_permissions_request_schema_t* instantiate_snapshot_sharing_permissions_request_schema(int include_optional) {
  snapshot_sharing_permissions_request_schema_t* snapshot_sharing_permissions_request_schema = NULL;
  if (include_optional) {
    snapshot_sharing_permissions_request_schema = snapshot_sharing_permissions_request_schema_create(
      true,
      1,
      1,
      1,
      1
    );
  } else {
    snapshot_sharing_permissions_request_schema = snapshot_sharing_permissions_request_schema_create(
      true,
      1,
      1,
      1,
      1
    );
  }

  return snapshot_sharing_permissions_request_schema;
}


#ifdef snapshot_sharing_permissions_request_schema_MAIN

void test_snapshot_sharing_permissions_request_schema(int include_optional) {
    snapshot_sharing_permissions_request_schema_t* snapshot_sharing_permissions_request_schema_1 = instantiate_snapshot_sharing_permissions_request_schema(include_optional);

	cJSON* jsonsnapshot_sharing_permissions_request_schema_1 = snapshot_sharing_permissions_request_schema_convertToJSON(snapshot_sharing_permissions_request_schema_1);
	printf("snapshot_sharing_permissions_request_schema :\n%s\n", cJSON_Print(jsonsnapshot_sharing_permissions_request_schema_1));
	snapshot_sharing_permissions_request_schema_t* snapshot_sharing_permissions_request_schema_2 = snapshot_sharing_permissions_request_schema_parseFromJSON(jsonsnapshot_sharing_permissions_request_schema_1);
	cJSON* jsonsnapshot_sharing_permissions_request_schema_2 = snapshot_sharing_permissions_request_schema_convertToJSON(snapshot_sharing_permissions_request_schema_2);
	printf("repeating snapshot_sharing_permissions_request_schema:\n%s\n", cJSON_Print(jsonsnapshot_sharing_permissions_request_schema_2));
}

int main() {
  test_snapshot_sharing_permissions_request_schema(1);
  test_snapshot_sharing_permissions_request_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_sharing_permissions_request_schema_MAIN
#endif // snapshot_sharing_permissions_request_schema_TEST
