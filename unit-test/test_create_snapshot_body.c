#ifndef create_snapshot_body_TEST
#define create_snapshot_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_snapshot_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_snapshot_body.h"
create_snapshot_body_t* instantiate_create_snapshot_body(int include_optional);



create_snapshot_body_t* instantiate_create_snapshot_body(int include_optional) {
  create_snapshot_body_t* create_snapshot_body = NULL;
  if (include_optional) {
    create_snapshot_body = create_snapshot_body_create(
      "before-update"
    );
  } else {
    create_snapshot_body = create_snapshot_body_create(
      "before-update"
    );
  }

  return create_snapshot_body;
}


#ifdef create_snapshot_body_MAIN

void test_create_snapshot_body(int include_optional) {
    create_snapshot_body_t* create_snapshot_body_1 = instantiate_create_snapshot_body(include_optional);

	cJSON* jsoncreate_snapshot_body_1 = create_snapshot_body_convertToJSON(create_snapshot_body_1);
	printf("create_snapshot_body :\n%s\n", cJSON_Print(jsoncreate_snapshot_body_1));
	create_snapshot_body_t* create_snapshot_body_2 = create_snapshot_body_parseFromJSON(jsoncreate_snapshot_body_1);
	cJSON* jsoncreate_snapshot_body_2 = create_snapshot_body_convertToJSON(create_snapshot_body_2);
	printf("repeating create_snapshot_body:\n%s\n", cJSON_Print(jsoncreate_snapshot_body_2));
}

int main() {
  test_create_snapshot_body(1);
  test_create_snapshot_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_snapshot_body_MAIN
#endif // create_snapshot_body_TEST
