#ifndef set_snapshot_permissions_body_TEST
#define set_snapshot_permissions_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define set_snapshot_permissions_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/set_snapshot_permissions_body.h"
set_snapshot_permissions_body_t* instantiate_set_snapshot_permissions_body(int include_optional);



set_snapshot_permissions_body_t* instantiate_set_snapshot_permissions_body(int include_optional) {
  set_snapshot_permissions_body_t* set_snapshot_permissions_body = NULL;
  if (include_optional) {
    set_snapshot_permissions_body = set_snapshot_permissions_body_create(
      ["jane.doe@example.com"]
    );
  } else {
    set_snapshot_permissions_body = set_snapshot_permissions_body_create(
      ["jane.doe@example.com"]
    );
  }

  return set_snapshot_permissions_body;
}


#ifdef set_snapshot_permissions_body_MAIN

void test_set_snapshot_permissions_body(int include_optional) {
    set_snapshot_permissions_body_t* set_snapshot_permissions_body_1 = instantiate_set_snapshot_permissions_body(include_optional);

	cJSON* jsonset_snapshot_permissions_body_1 = set_snapshot_permissions_body_convertToJSON(set_snapshot_permissions_body_1);
	printf("set_snapshot_permissions_body :\n%s\n", cJSON_Print(jsonset_snapshot_permissions_body_1));
	set_snapshot_permissions_body_t* set_snapshot_permissions_body_2 = set_snapshot_permissions_body_parseFromJSON(jsonset_snapshot_permissions_body_1);
	cJSON* jsonset_snapshot_permissions_body_2 = set_snapshot_permissions_body_convertToJSON(set_snapshot_permissions_body_2);
	printf("repeating set_snapshot_permissions_body:\n%s\n", cJSON_Print(jsonset_snapshot_permissions_body_2));
}

int main() {
  test_set_snapshot_permissions_body(1);
  test_set_snapshot_permissions_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // set_snapshot_permissions_body_MAIN
#endif // set_snapshot_permissions_body_TEST
