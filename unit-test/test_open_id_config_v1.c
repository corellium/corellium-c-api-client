#ifndef open_id_config_v1_TEST
#define open_id_config_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define open_id_config_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/open_id_config_v1.h"
open_id_config_v1_t* instantiate_open_id_config_v1(int include_optional);



open_id_config_v1_t* instantiate_open_id_config_v1(int include_optional) {
  open_id_config_v1_t* open_id_config_v1 = NULL;
  if (include_optional) {
    open_id_config_v1 = open_id_config_v1_create(
      "0",
      "0",
      "0",
      1
    );
  } else {
    open_id_config_v1 = open_id_config_v1_create(
      "0",
      "0",
      "0",
      1
    );
  }

  return open_id_config_v1;
}


#ifdef open_id_config_v1_MAIN

void test_open_id_config_v1(int include_optional) {
    open_id_config_v1_t* open_id_config_v1_1 = instantiate_open_id_config_v1(include_optional);

	cJSON* jsonopen_id_config_v1_1 = open_id_config_v1_convertToJSON(open_id_config_v1_1);
	printf("open_id_config_v1 :\n%s\n", cJSON_Print(jsonopen_id_config_v1_1));
	open_id_config_v1_t* open_id_config_v1_2 = open_id_config_v1_parseFromJSON(jsonopen_id_config_v1_1);
	cJSON* jsonopen_id_config_v1_2 = open_id_config_v1_convertToJSON(open_id_config_v1_2);
	printf("repeating open_id_config_v1:\n%s\n", cJSON_Print(jsonopen_id_config_v1_2));
}

int main() {
  test_open_id_config_v1(1);
  test_open_id_config_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // open_id_config_v1_MAIN
#endif // open_id_config_v1_TEST
