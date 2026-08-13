#ifndef snapshot_status_schema_TEST
#define snapshot_status_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_status_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_status_schema.h"
snapshot_status_schema_t* instantiate_snapshot_status_schema(int include_optional);



snapshot_status_schema_t* instantiate_snapshot_status_schema(int include_optional) {
  snapshot_status_schema_t* snapshot_status_schema = NULL;
  if (include_optional) {
    snapshot_status_schema = snapshot_status_schema_create(
      "0",
      1
    );
  } else {
    snapshot_status_schema = snapshot_status_schema_create(
      "0",
      1
    );
  }

  return snapshot_status_schema;
}


#ifdef snapshot_status_schema_MAIN

void test_snapshot_status_schema(int include_optional) {
    snapshot_status_schema_t* snapshot_status_schema_1 = instantiate_snapshot_status_schema(include_optional);

	cJSON* jsonsnapshot_status_schema_1 = snapshot_status_schema_convertToJSON(snapshot_status_schema_1);
	printf("snapshot_status_schema :\n%s\n", cJSON_Print(jsonsnapshot_status_schema_1));
	snapshot_status_schema_t* snapshot_status_schema_2 = snapshot_status_schema_parseFromJSON(jsonsnapshot_status_schema_1);
	cJSON* jsonsnapshot_status_schema_2 = snapshot_status_schema_convertToJSON(snapshot_status_schema_2);
	printf("repeating snapshot_status_schema:\n%s\n", cJSON_Print(jsonsnapshot_status_schema_2));
}

int main() {
  test_snapshot_status_schema(1);
  test_snapshot_status_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_status_schema_MAIN
#endif // snapshot_status_schema_TEST
