#ifndef snapshot_owner_schema_TEST
#define snapshot_owner_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_owner_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_owner_schema.h"
snapshot_owner_schema_t* instantiate_snapshot_owner_schema(int include_optional);



snapshot_owner_schema_t* instantiate_snapshot_owner_schema(int include_optional) {
  snapshot_owner_schema_t* snapshot_owner_schema = NULL;
  if (include_optional) {
    snapshot_owner_schema = snapshot_owner_schema_create(
      "0",
      "0"
    );
  } else {
    snapshot_owner_schema = snapshot_owner_schema_create(
      "0",
      "0"
    );
  }

  return snapshot_owner_schema;
}


#ifdef snapshot_owner_schema_MAIN

void test_snapshot_owner_schema(int include_optional) {
    snapshot_owner_schema_t* snapshot_owner_schema_1 = instantiate_snapshot_owner_schema(include_optional);

	cJSON* jsonsnapshot_owner_schema_1 = snapshot_owner_schema_convertToJSON(snapshot_owner_schema_1);
	printf("snapshot_owner_schema :\n%s\n", cJSON_Print(jsonsnapshot_owner_schema_1));
	snapshot_owner_schema_t* snapshot_owner_schema_2 = snapshot_owner_schema_parseFromJSON(jsonsnapshot_owner_schema_1);
	cJSON* jsonsnapshot_owner_schema_2 = snapshot_owner_schema_convertToJSON(snapshot_owner_schema_2);
	printf("repeating snapshot_owner_schema:\n%s\n", cJSON_Print(jsonsnapshot_owner_schema_2));
}

int main() {
  test_snapshot_owner_schema(1);
  test_snapshot_owner_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_owner_schema_MAIN
#endif // snapshot_owner_schema_TEST
