#ifndef snapshot_sharing_type_TEST
#define snapshot_sharing_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_sharing_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_sharing_type.h"
snapshot_sharing_type_t* instantiate_snapshot_sharing_type(int include_optional);



snapshot_sharing_type_t* instantiate_snapshot_sharing_type(int include_optional) {
  snapshot_sharing_type_t* snapshot_sharing_type = NULL;
  if (include_optional) {
    snapshot_sharing_type = snapshot_sharing_type_create(
    );
  } else {
    snapshot_sharing_type = snapshot_sharing_type_create(
    );
  }

  return snapshot_sharing_type;
}


#ifdef snapshot_sharing_type_MAIN

void test_snapshot_sharing_type(int include_optional) {
    snapshot_sharing_type_t* snapshot_sharing_type_1 = instantiate_snapshot_sharing_type(include_optional);

	cJSON* jsonsnapshot_sharing_type_1 = snapshot_sharing_type_convertToJSON(snapshot_sharing_type_1);
	printf("snapshot_sharing_type :\n%s\n", cJSON_Print(jsonsnapshot_sharing_type_1));
	snapshot_sharing_type_t* snapshot_sharing_type_2 = snapshot_sharing_type_parseFromJSON(jsonsnapshot_sharing_type_1);
	cJSON* jsonsnapshot_sharing_type_2 = snapshot_sharing_type_convertToJSON(snapshot_sharing_type_2);
	printf("repeating snapshot_sharing_type:\n%s\n", cJSON_Print(jsonsnapshot_sharing_type_2));
}

int main() {
  test_snapshot_sharing_type(1);
  test_snapshot_sharing_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_sharing_type_MAIN
#endif // snapshot_sharing_type_TEST
