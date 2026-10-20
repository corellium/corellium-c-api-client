#ifndef create_interconnect_body_TEST
#define create_interconnect_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_interconnect_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_interconnect_body.h"
create_interconnect_body_t* instantiate_create_interconnect_body(int include_optional);



create_interconnect_body_t* instantiate_create_interconnect_body(int include_optional) {
  create_interconnect_body_t* create_interconnect_body = NULL;
  if (include_optional) {
    create_interconnect_body = create_interconnect_body_create(
      "0",
      "0",
      corellium_api_create_interconnect_body_TYPE_hub,
      "0",
      list_createList()
    );
  } else {
    create_interconnect_body = create_interconnect_body_create(
      "0",
      "0",
      corellium_api_create_interconnect_body_TYPE_hub,
      "0",
      list_createList()
    );
  }

  return create_interconnect_body;
}


#ifdef create_interconnect_body_MAIN

void test_create_interconnect_body(int include_optional) {
    create_interconnect_body_t* create_interconnect_body_1 = instantiate_create_interconnect_body(include_optional);

	cJSON* jsoncreate_interconnect_body_1 = create_interconnect_body_convertToJSON(create_interconnect_body_1);
	printf("create_interconnect_body :\n%s\n", cJSON_Print(jsoncreate_interconnect_body_1));
	create_interconnect_body_t* create_interconnect_body_2 = create_interconnect_body_parseFromJSON(jsoncreate_interconnect_body_1);
	cJSON* jsoncreate_interconnect_body_2 = create_interconnect_body_convertToJSON(create_interconnect_body_2);
	printf("repeating create_interconnect_body:\n%s\n", cJSON_Print(jsoncreate_interconnect_body_2));
}

int main() {
  test_create_interconnect_body(1);
  test_create_interconnect_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_interconnect_body_MAIN
#endif // create_interconnect_body_TEST
