#ifndef update_interconnect_v3_body_TEST
#define update_interconnect_v3_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_interconnect_v3_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_interconnect_v3_body.h"
update_interconnect_v3_body_t* instantiate_update_interconnect_v3_body(int include_optional);



update_interconnect_v3_body_t* instantiate_update_interconnect_v3_body(int include_optional) {
  update_interconnect_v3_body_t* update_interconnect_v3_body = NULL;
  if (include_optional) {
    update_interconnect_v3_body = update_interconnect_v3_body_create(
      "0",
      list_createList(),
      corellium_api_update_interconnect_v3_body_TYPE_hub,
      "0",
      corellium_api_update_interconnect_v3_body__can
    );
  } else {
    update_interconnect_v3_body = update_interconnect_v3_body_create(
      "0",
      list_createList(),
      corellium_api_update_interconnect_v3_body_TYPE_hub,
      "0",
      corellium_api_update_interconnect_v3_body__can
    );
  }

  return update_interconnect_v3_body;
}


#ifdef update_interconnect_v3_body_MAIN

void test_update_interconnect_v3_body(int include_optional) {
    update_interconnect_v3_body_t* update_interconnect_v3_body_1 = instantiate_update_interconnect_v3_body(include_optional);

	cJSON* jsonupdate_interconnect_v3_body_1 = update_interconnect_v3_body_convertToJSON(update_interconnect_v3_body_1);
	printf("update_interconnect_v3_body :\n%s\n", cJSON_Print(jsonupdate_interconnect_v3_body_1));
	update_interconnect_v3_body_t* update_interconnect_v3_body_2 = update_interconnect_v3_body_parseFromJSON(jsonupdate_interconnect_v3_body_1);
	cJSON* jsonupdate_interconnect_v3_body_2 = update_interconnect_v3_body_convertToJSON(update_interconnect_v3_body_2);
	printf("repeating update_interconnect_v3_body:\n%s\n", cJSON_Print(jsonupdate_interconnect_v3_body_2));
}

int main() {
  test_update_interconnect_v3_body(1);
  test_update_interconnect_v3_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_interconnect_v3_body_MAIN
#endif // update_interconnect_v3_body_TEST
