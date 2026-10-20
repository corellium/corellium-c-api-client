#ifndef snapshot_owner_TEST
#define snapshot_owner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_owner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_owner.h"
snapshot_owner_t* instantiate_snapshot_owner(int include_optional);



snapshot_owner_t* instantiate_snapshot_owner(int include_optional) {
  snapshot_owner_t* snapshot_owner = NULL;
  if (include_optional) {
    snapshot_owner = snapshot_owner_create(
      "Jane Doe",
      "jane.doe@example.com"
    );
  } else {
    snapshot_owner = snapshot_owner_create(
      "Jane Doe",
      "jane.doe@example.com"
    );
  }

  return snapshot_owner;
}


#ifdef snapshot_owner_MAIN

void test_snapshot_owner(int include_optional) {
    snapshot_owner_t* snapshot_owner_1 = instantiate_snapshot_owner(include_optional);

	cJSON* jsonsnapshot_owner_1 = snapshot_owner_convertToJSON(snapshot_owner_1);
	printf("snapshot_owner :\n%s\n", cJSON_Print(jsonsnapshot_owner_1));
	snapshot_owner_t* snapshot_owner_2 = snapshot_owner_parseFromJSON(jsonsnapshot_owner_1);
	cJSON* jsonsnapshot_owner_2 = snapshot_owner_convertToJSON(snapshot_owner_2);
	printf("repeating snapshot_owner:\n%s\n", cJSON_Print(jsonsnapshot_owner_2));
}

int main() {
  test_snapshot_owner(1);
  test_snapshot_owner(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_owner_MAIN
#endif // snapshot_owner_TEST
