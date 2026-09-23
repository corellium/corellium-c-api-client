#ifndef fetch_firmware_assets_response_TEST
#define fetch_firmware_assets_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define fetch_firmware_assets_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/fetch_firmware_assets_response.h"
fetch_firmware_assets_response_t* instantiate_fetch_firmware_assets_response(int include_optional);



fetch_firmware_assets_response_t* instantiate_fetch_firmware_assets_response(int include_optional) {
  fetch_firmware_assets_response_t* fetch_firmware_assets_response = NULL;
  if (include_optional) {
    fetch_firmware_assets_response = fetch_firmware_assets_response_create(
      ["https://example.com/firmware/asset.ipsw"],
      ["https://example.com/firmware/asset.ipsw"],
      list_createList()
    );
  } else {
    fetch_firmware_assets_response = fetch_firmware_assets_response_create(
      ["https://example.com/firmware/asset.ipsw"],
      ["https://example.com/firmware/asset.ipsw"],
      list_createList()
    );
  }

  return fetch_firmware_assets_response;
}


#ifdef fetch_firmware_assets_response_MAIN

void test_fetch_firmware_assets_response(int include_optional) {
    fetch_firmware_assets_response_t* fetch_firmware_assets_response_1 = instantiate_fetch_firmware_assets_response(include_optional);

	cJSON* jsonfetch_firmware_assets_response_1 = fetch_firmware_assets_response_convertToJSON(fetch_firmware_assets_response_1);
	printf("fetch_firmware_assets_response :\n%s\n", cJSON_Print(jsonfetch_firmware_assets_response_1));
	fetch_firmware_assets_response_t* fetch_firmware_assets_response_2 = fetch_firmware_assets_response_parseFromJSON(jsonfetch_firmware_assets_response_1);
	cJSON* jsonfetch_firmware_assets_response_2 = fetch_firmware_assets_response_convertToJSON(fetch_firmware_assets_response_2);
	printf("repeating fetch_firmware_assets_response:\n%s\n", cJSON_Print(jsonfetch_firmware_assets_response_2));
}

int main() {
  test_fetch_firmware_assets_response(1);
  test_fetch_firmware_assets_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // fetch_firmware_assets_response_MAIN
#endif // fetch_firmware_assets_response_TEST
