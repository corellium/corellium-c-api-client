#ifndef shared_snapshots_info_TEST
#define shared_snapshots_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shared_snapshots_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shared_snapshots_info.h"
shared_snapshots_info_t* instantiate_shared_snapshots_info(int include_optional);

#include "test_snapshot_owner.c"


shared_snapshots_info_t* instantiate_shared_snapshots_info(int include_optional) {
  shared_snapshots_info_t* shared_snapshots_info = NULL;
  if (include_optional) {
    shared_snapshots_info = shared_snapshots_info_create(
      "0",
      "0",
      "0",
      1.337,
      "0",
       // false, not to have infinite recursion
      instantiate_snapshot_owner(0)
    );
  } else {
    shared_snapshots_info = shared_snapshots_info_create(
      "0",
      "0",
      "0",
      1.337,
      "0",
      NULL
    );
  }

  return shared_snapshots_info;
}


#ifdef shared_snapshots_info_MAIN

void test_shared_snapshots_info(int include_optional) {
    shared_snapshots_info_t* shared_snapshots_info_1 = instantiate_shared_snapshots_info(include_optional);

	cJSON* jsonshared_snapshots_info_1 = shared_snapshots_info_convertToJSON(shared_snapshots_info_1);
	printf("shared_snapshots_info :\n%s\n", cJSON_Print(jsonshared_snapshots_info_1));
	shared_snapshots_info_t* shared_snapshots_info_2 = shared_snapshots_info_parseFromJSON(jsonshared_snapshots_info_1);
	cJSON* jsonshared_snapshots_info_2 = shared_snapshots_info_convertToJSON(shared_snapshots_info_2);
	printf("repeating shared_snapshots_info:\n%s\n", cJSON_Print(jsonshared_snapshots_info_2));
}

int main() {
  test_shared_snapshots_info(1);
  test_shared_snapshots_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // shared_snapshots_info_MAIN
#endif // shared_snapshots_info_TEST
