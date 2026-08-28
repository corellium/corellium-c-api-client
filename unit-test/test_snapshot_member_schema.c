#ifndef snapshot_member_schema_TEST
#define snapshot_member_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_member_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_member_schema.h"
snapshot_member_schema_t* instantiate_snapshot_member_schema(int include_optional);



snapshot_member_schema_t* instantiate_snapshot_member_schema(int include_optional) {
  snapshot_member_schema_t* snapshot_member_schema = NULL;
  if (include_optional) {
    snapshot_member_schema = snapshot_member_schema_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  } else {
    snapshot_member_schema = snapshot_member_schema_create(
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  }

  return snapshot_member_schema;
}


#ifdef snapshot_member_schema_MAIN

void test_snapshot_member_schema(int include_optional) {
    snapshot_member_schema_t* snapshot_member_schema_1 = instantiate_snapshot_member_schema(include_optional);

	cJSON* jsonsnapshot_member_schema_1 = snapshot_member_schema_convertToJSON(snapshot_member_schema_1);
	printf("snapshot_member_schema :\n%s\n", cJSON_Print(jsonsnapshot_member_schema_1));
	snapshot_member_schema_t* snapshot_member_schema_2 = snapshot_member_schema_parseFromJSON(jsonsnapshot_member_schema_1);
	cJSON* jsonsnapshot_member_schema_2 = snapshot_member_schema_convertToJSON(snapshot_member_schema_2);
	printf("repeating snapshot_member_schema:\n%s\n", cJSON_Print(jsonsnapshot_member_schema_2));
}

int main() {
  test_snapshot_member_schema(1);
  test_snapshot_member_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_member_schema_MAIN
#endif // snapshot_member_schema_TEST
