#ifndef open_vpn_config_v1_TEST
#define open_vpn_config_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define open_vpn_config_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/open_vpn_config_v1.h"
open_vpn_config_v1_t* instantiate_open_vpn_config_v1(int include_optional);



open_vpn_config_v1_t* instantiate_open_vpn_config_v1(int include_optional) {
  open_vpn_config_v1_t* open_vpn_config_v1 = NULL;
  if (include_optional) {
    open_vpn_config_v1 = open_vpn_config_v1_create(
      "0",
      "0",
      "0"
    );
  } else {
    open_vpn_config_v1 = open_vpn_config_v1_create(
      "0",
      "0",
      "0"
    );
  }

  return open_vpn_config_v1;
}


#ifdef open_vpn_config_v1_MAIN

void test_open_vpn_config_v1(int include_optional) {
    open_vpn_config_v1_t* open_vpn_config_v1_1 = instantiate_open_vpn_config_v1(include_optional);

	cJSON* jsonopen_vpn_config_v1_1 = open_vpn_config_v1_convertToJSON(open_vpn_config_v1_1);
	printf("open_vpn_config_v1 :\n%s\n", cJSON_Print(jsonopen_vpn_config_v1_1));
	open_vpn_config_v1_t* open_vpn_config_v1_2 = open_vpn_config_v1_parseFromJSON(jsonopen_vpn_config_v1_1);
	cJSON* jsonopen_vpn_config_v1_2 = open_vpn_config_v1_convertToJSON(open_vpn_config_v1_2);
	printf("repeating open_vpn_config_v1:\n%s\n", cJSON_Print(jsonopen_vpn_config_v1_2));
}

int main() {
  test_open_vpn_config_v1(1);
  test_open_vpn_config_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // open_vpn_config_v1_MAIN
#endif // open_vpn_config_v1_TEST
