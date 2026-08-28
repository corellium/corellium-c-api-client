#ifndef get_firmware_info_body_TEST
#define get_firmware_info_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_firmware_info_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_firmware_info_body.h"
get_firmware_info_body_t* instantiate_get_firmware_info_body(int include_optional);



get_firmware_info_body_t* instantiate_get_firmware_info_body(int include_optional) {
  get_firmware_info_body_t* get_firmware_info_body = NULL;
  if (include_optional) {
    get_firmware_info_body = get_firmware_info_body_create(
      "0",
      1
    );
  } else {
    get_firmware_info_body = get_firmware_info_body_create(
      "0",
      1
    );
  }

  return get_firmware_info_body;
}


#ifdef get_firmware_info_body_MAIN

void test_get_firmware_info_body(int include_optional) {
    get_firmware_info_body_t* get_firmware_info_body_1 = instantiate_get_firmware_info_body(include_optional);

	cJSON* jsonget_firmware_info_body_1 = get_firmware_info_body_convertToJSON(get_firmware_info_body_1);
	printf("get_firmware_info_body :\n%s\n", cJSON_Print(jsonget_firmware_info_body_1));
	get_firmware_info_body_t* get_firmware_info_body_2 = get_firmware_info_body_parseFromJSON(jsonget_firmware_info_body_1);
	cJSON* jsonget_firmware_info_body_2 = get_firmware_info_body_convertToJSON(get_firmware_info_body_2);
	printf("repeating get_firmware_info_body:\n%s\n", cJSON_Print(jsonget_firmware_info_body_2));
}

int main() {
  test_get_firmware_info_body(1);
  test_get_firmware_info_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_firmware_info_body_MAIN
#endif // get_firmware_info_body_TEST
