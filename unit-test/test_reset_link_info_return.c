#ifndef reset_link_info_return_TEST
#define reset_link_info_return_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reset_link_info_return_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reset_link_info_return.h"
reset_link_info_return_t* instantiate_reset_link_info_return(int include_optional);



reset_link_info_return_t* instantiate_reset_link_info_return(int include_optional) {
  reset_link_info_return_t* reset_link_info_return = NULL;
  if (include_optional) {
    reset_link_info_return = reset_link_info_return_create(
      "0",
      "0",
      "0"
    );
  } else {
    reset_link_info_return = reset_link_info_return_create(
      "0",
      "0",
      "0"
    );
  }

  return reset_link_info_return;
}


#ifdef reset_link_info_return_MAIN

void test_reset_link_info_return(int include_optional) {
    reset_link_info_return_t* reset_link_info_return_1 = instantiate_reset_link_info_return(include_optional);

	cJSON* jsonreset_link_info_return_1 = reset_link_info_return_convertToJSON(reset_link_info_return_1);
	printf("reset_link_info_return :\n%s\n", cJSON_Print(jsonreset_link_info_return_1));
	reset_link_info_return_t* reset_link_info_return_2 = reset_link_info_return_parseFromJSON(jsonreset_link_info_return_1);
	cJSON* jsonreset_link_info_return_2 = reset_link_info_return_convertToJSON(reset_link_info_return_2);
	printf("repeating reset_link_info_return:\n%s\n", cJSON_Print(jsonreset_link_info_return_2));
}

int main() {
  test_reset_link_info_return(1);
  test_reset_link_info_return(0);

  printf("Hello world \n");
  return 0;
}

#endif // reset_link_info_return_MAIN
#endif // reset_link_info_return_TEST
