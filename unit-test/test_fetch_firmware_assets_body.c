#ifndef fetch_firmware_assets_body_TEST
#define fetch_firmware_assets_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define fetch_firmware_assets_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/fetch_firmware_assets_body.h"
fetch_firmware_assets_body_t* instantiate_fetch_firmware_assets_body(int include_optional);



fetch_firmware_assets_body_t* instantiate_fetch_firmware_assets_body(int include_optional) {
  fetch_firmware_assets_body_t* fetch_firmware_assets_body = NULL;
  if (include_optional) {
    fetch_firmware_assets_body = fetch_firmware_assets_body_create(
      list_createList()
    );
  } else {
    fetch_firmware_assets_body = fetch_firmware_assets_body_create(
      list_createList()
    );
  }

  return fetch_firmware_assets_body;
}


#ifdef fetch_firmware_assets_body_MAIN

void test_fetch_firmware_assets_body(int include_optional) {
    fetch_firmware_assets_body_t* fetch_firmware_assets_body_1 = instantiate_fetch_firmware_assets_body(include_optional);

	cJSON* jsonfetch_firmware_assets_body_1 = fetch_firmware_assets_body_convertToJSON(fetch_firmware_assets_body_1);
	printf("fetch_firmware_assets_body :\n%s\n", cJSON_Print(jsonfetch_firmware_assets_body_1));
	fetch_firmware_assets_body_t* fetch_firmware_assets_body_2 = fetch_firmware_assets_body_parseFromJSON(jsonfetch_firmware_assets_body_1);
	cJSON* jsonfetch_firmware_assets_body_2 = fetch_firmware_assets_body_convertToJSON(fetch_firmware_assets_body_2);
	printf("repeating fetch_firmware_assets_body:\n%s\n", cJSON_Print(jsonfetch_firmware_assets_body_2));
}

int main() {
  test_fetch_firmware_assets_body(1);
  test_fetch_firmware_assets_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // fetch_firmware_assets_body_MAIN
#endif // fetch_firmware_assets_body_TEST
