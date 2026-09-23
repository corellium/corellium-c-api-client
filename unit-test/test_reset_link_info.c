#ifndef reset_link_info_TEST
#define reset_link_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reset_link_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reset_link_info.h"
reset_link_info_t* instantiate_reset_link_info(int include_optional);



reset_link_info_t* instantiate_reset_link_info(int include_optional) {
  reset_link_info_t* reset_link_info = NULL;
  if (include_optional) {
    reset_link_info = reset_link_info_create(
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "jane.doe",
      "acme"
    );
  } else {
    reset_link_info = reset_link_info_create(
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "jane.doe",
      "acme"
    );
  }

  return reset_link_info;
}


#ifdef reset_link_info_MAIN

void test_reset_link_info(int include_optional) {
    reset_link_info_t* reset_link_info_1 = instantiate_reset_link_info(include_optional);

	cJSON* jsonreset_link_info_1 = reset_link_info_convertToJSON(reset_link_info_1);
	printf("reset_link_info :\n%s\n", cJSON_Print(jsonreset_link_info_1));
	reset_link_info_t* reset_link_info_2 = reset_link_info_parseFromJSON(jsonreset_link_info_1);
	cJSON* jsonreset_link_info_2 = reset_link_info_convertToJSON(reset_link_info_2);
	printf("repeating reset_link_info:\n%s\n", cJSON_Print(jsonreset_link_info_2));
}

int main() {
  test_reset_link_info(1);
  test_reset_link_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // reset_link_info_MAIN
#endif // reset_link_info_TEST
