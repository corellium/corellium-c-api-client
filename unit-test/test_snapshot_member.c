#ifndef snapshot_member_TEST
#define snapshot_member_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_member_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_member.h"
snapshot_member_t* instantiate_snapshot_member(int include_optional);



snapshot_member_t* instantiate_snapshot_member(int include_optional) {
  snapshot_member_t* snapshot_member = NULL;
  if (include_optional) {
    snapshot_member = snapshot_member_create(
      "jane.doe@example.com",
      "2026-03-16T08:22:19Z",
      "2026-03-16T08:22:19Z",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "Jane Doe"
    );
  } else {
    snapshot_member = snapshot_member_create(
      "jane.doe@example.com",
      "2026-03-16T08:22:19Z",
      "2026-03-16T08:22:19Z",
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "Jane Doe"
    );
  }

  return snapshot_member;
}


#ifdef snapshot_member_MAIN

void test_snapshot_member(int include_optional) {
    snapshot_member_t* snapshot_member_1 = instantiate_snapshot_member(include_optional);

	cJSON* jsonsnapshot_member_1 = snapshot_member_convertToJSON(snapshot_member_1);
	printf("snapshot_member :\n%s\n", cJSON_Print(jsonsnapshot_member_1));
	snapshot_member_t* snapshot_member_2 = snapshot_member_parseFromJSON(jsonsnapshot_member_1);
	cJSON* jsonsnapshot_member_2 = snapshot_member_convertToJSON(snapshot_member_2);
	printf("repeating snapshot_member:\n%s\n", cJSON_Print(jsonsnapshot_member_2));
}

int main() {
  test_snapshot_member(1);
  test_snapshot_member(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_member_MAIN
#endif // snapshot_member_TEST
