#ifndef fetch_firmware_assets_response_failed_inner_TEST
#define fetch_firmware_assets_response_failed_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define fetch_firmware_assets_response_failed_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/fetch_firmware_assets_response_failed_inner.h"
fetch_firmware_assets_response_failed_inner_t* instantiate_fetch_firmware_assets_response_failed_inner(int include_optional);



fetch_firmware_assets_response_failed_inner_t* instantiate_fetch_firmware_assets_response_failed_inner(int include_optional) {
  fetch_firmware_assets_response_failed_inner_t* fetch_firmware_assets_response_failed_inner = NULL;
  if (include_optional) {
    fetch_firmware_assets_response_failed_inner = fetch_firmware_assets_response_failed_inner_create(
      "https://example.com/firmware/asset.ipsw",
      "404 Not Found"
    );
  } else {
    fetch_firmware_assets_response_failed_inner = fetch_firmware_assets_response_failed_inner_create(
      "https://example.com/firmware/asset.ipsw",
      "404 Not Found"
    );
  }

  return fetch_firmware_assets_response_failed_inner;
}


#ifdef fetch_firmware_assets_response_failed_inner_MAIN

void test_fetch_firmware_assets_response_failed_inner(int include_optional) {
    fetch_firmware_assets_response_failed_inner_t* fetch_firmware_assets_response_failed_inner_1 = instantiate_fetch_firmware_assets_response_failed_inner(include_optional);

	cJSON* jsonfetch_firmware_assets_response_failed_inner_1 = fetch_firmware_assets_response_failed_inner_convertToJSON(fetch_firmware_assets_response_failed_inner_1);
	printf("fetch_firmware_assets_response_failed_inner :\n%s\n", cJSON_Print(jsonfetch_firmware_assets_response_failed_inner_1));
	fetch_firmware_assets_response_failed_inner_t* fetch_firmware_assets_response_failed_inner_2 = fetch_firmware_assets_response_failed_inner_parseFromJSON(jsonfetch_firmware_assets_response_failed_inner_1);
	cJSON* jsonfetch_firmware_assets_response_failed_inner_2 = fetch_firmware_assets_response_failed_inner_convertToJSON(fetch_firmware_assets_response_failed_inner_2);
	printf("repeating fetch_firmware_assets_response_failed_inner:\n%s\n", cJSON_Print(jsonfetch_firmware_assets_response_failed_inner_2));
}

int main() {
  test_fetch_firmware_assets_response_failed_inner(1);
  test_fetch_firmware_assets_response_failed_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // fetch_firmware_assets_response_failed_inner_MAIN
#endif // fetch_firmware_assets_response_failed_inner_TEST
