#ifndef create_activity_export_body_TEST
#define create_activity_export_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_activity_export_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_activity_export_body.h"
create_activity_export_body_t* instantiate_create_activity_export_body(int include_optional);



create_activity_export_body_t* instantiate_create_activity_export_body(int include_optional) {
  create_activity_export_body_t* create_activity_export_body = NULL;
  if (include_optional) {
    create_activity_export_body = create_activity_export_body_create(
      0,
      0,
      "-createdAt",
      "0",
      "0",
      "0",
      "0",
      "2026-05-22T13:58:34Z",
      "2026-05-22T00:00Z"
    );
  } else {
    create_activity_export_body = create_activity_export_body_create(
      0,
      0,
      "-createdAt",
      "0",
      "0",
      "0",
      "0",
      "2026-05-22T13:58:34Z",
      "2026-05-22T00:00Z"
    );
  }

  return create_activity_export_body;
}


#ifdef create_activity_export_body_MAIN

void test_create_activity_export_body(int include_optional) {
    create_activity_export_body_t* create_activity_export_body_1 = instantiate_create_activity_export_body(include_optional);

	cJSON* jsoncreate_activity_export_body_1 = create_activity_export_body_convertToJSON(create_activity_export_body_1);
	printf("create_activity_export_body :\n%s\n", cJSON_Print(jsoncreate_activity_export_body_1));
	create_activity_export_body_t* create_activity_export_body_2 = create_activity_export_body_parseFromJSON(jsoncreate_activity_export_body_1);
	cJSON* jsoncreate_activity_export_body_2 = create_activity_export_body_convertToJSON(create_activity_export_body_2);
	printf("repeating create_activity_export_body:\n%s\n", cJSON_Print(jsoncreate_activity_export_body_2));
}

int main() {
  test_create_activity_export_body(1);
  test_create_activity_export_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_activity_export_body_MAIN
#endif // create_activity_export_body_TEST
