#ifndef get_reset_link_info_body_TEST
#define get_reset_link_info_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define get_reset_link_info_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/get_reset_link_info_body.h"
get_reset_link_info_body_t* instantiate_get_reset_link_info_body(int include_optional);



get_reset_link_info_body_t* instantiate_get_reset_link_info_body(int include_optional) {
  get_reset_link_info_body_t* get_reset_link_info_body = NULL;
  if (include_optional) {
    get_reset_link_info_body = get_reset_link_info_body_create(
      "<token>"
    );
  } else {
    get_reset_link_info_body = get_reset_link_info_body_create(
      "<token>"
    );
  }

  return get_reset_link_info_body;
}


#ifdef get_reset_link_info_body_MAIN

void test_get_reset_link_info_body(int include_optional) {
    get_reset_link_info_body_t* get_reset_link_info_body_1 = instantiate_get_reset_link_info_body(include_optional);

	cJSON* jsonget_reset_link_info_body_1 = get_reset_link_info_body_convertToJSON(get_reset_link_info_body_1);
	printf("get_reset_link_info_body :\n%s\n", cJSON_Print(jsonget_reset_link_info_body_1));
	get_reset_link_info_body_t* get_reset_link_info_body_2 = get_reset_link_info_body_parseFromJSON(jsonget_reset_link_info_body_1);
	cJSON* jsonget_reset_link_info_body_2 = get_reset_link_info_body_convertToJSON(get_reset_link_info_body_2);
	printf("repeating get_reset_link_info_body:\n%s\n", cJSON_Print(jsonget_reset_link_info_body_2));
}

int main() {
  test_get_reset_link_info_body(1);
  test_get_reset_link_info_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // get_reset_link_info_body_MAIN
#endif // get_reset_link_info_body_TEST
