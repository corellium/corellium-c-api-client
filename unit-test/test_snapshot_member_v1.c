#ifndef snapshot_member_v1_TEST
#define snapshot_member_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_member_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_member_v1.h"
snapshot_member_v1_t* instantiate_snapshot_member_v1(int include_optional);



snapshot_member_v1_t* instantiate_snapshot_member_v1(int include_optional) {
  snapshot_member_v1_t* snapshot_member_v1 = NULL;
  if (include_optional) {
    snapshot_member_v1 = snapshot_member_v1_create(
      "0",
      1.337,
      1.337,
      "0",
      "0"
    );
  } else {
    snapshot_member_v1 = snapshot_member_v1_create(
      "0",
      1.337,
      1.337,
      "0",
      "0"
    );
  }

  return snapshot_member_v1;
}


#ifdef snapshot_member_v1_MAIN

void test_snapshot_member_v1(int include_optional) {
    snapshot_member_v1_t* snapshot_member_v1_1 = instantiate_snapshot_member_v1(include_optional);

	cJSON* jsonsnapshot_member_v1_1 = snapshot_member_v1_convertToJSON(snapshot_member_v1_1);
	printf("snapshot_member_v1 :\n%s\n", cJSON_Print(jsonsnapshot_member_v1_1));
	snapshot_member_v1_t* snapshot_member_v1_2 = snapshot_member_v1_parseFromJSON(jsonsnapshot_member_v1_1);
	cJSON* jsonsnapshot_member_v1_2 = snapshot_member_v1_convertToJSON(snapshot_member_v1_2);
	printf("repeating snapshot_member_v1:\n%s\n", cJSON_Print(jsonsnapshot_member_v1_2));
}

int main() {
  test_snapshot_member_v1(1);
  test_snapshot_member_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_member_v1_MAIN
#endif // snapshot_member_v1_TEST
