#ifndef snapshot_list_TEST
#define snapshot_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define snapshot_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/snapshot_list.h"
snapshot_list_t* instantiate_snapshot_list(int include_optional);



snapshot_list_t* instantiate_snapshot_list(int include_optional) {
  snapshot_list_t* snapshot_list = NULL;
  if (include_optional) {
    snapshot_list = snapshot_list_create(
      list_createList(),
      1.337,
      1.337,
      1.337
    );
  } else {
    snapshot_list = snapshot_list_create(
      list_createList(),
      1.337,
      1.337,
      1.337
    );
  }

  return snapshot_list;
}


#ifdef snapshot_list_MAIN

void test_snapshot_list(int include_optional) {
    snapshot_list_t* snapshot_list_1 = instantiate_snapshot_list(include_optional);

	cJSON* jsonsnapshot_list_1 = snapshot_list_convertToJSON(snapshot_list_1);
	printf("snapshot_list :\n%s\n", cJSON_Print(jsonsnapshot_list_1));
	snapshot_list_t* snapshot_list_2 = snapshot_list_parseFromJSON(jsonsnapshot_list_1);
	cJSON* jsonsnapshot_list_2 = snapshot_list_convertToJSON(snapshot_list_2);
	printf("repeating snapshot_list:\n%s\n", cJSON_Print(jsonsnapshot_list_2));
}

int main() {
  test_snapshot_list(1);
  test_snapshot_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // snapshot_list_MAIN
#endif // snapshot_list_TEST
