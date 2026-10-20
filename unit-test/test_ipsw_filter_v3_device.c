#ifndef ipsw_filter_v3_device_TEST
#define ipsw_filter_v3_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ipsw_filter_v3_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ipsw_filter_v3_device.h"
ipsw_filter_v3_device_t* instantiate_ipsw_filter_v3_device(int include_optional);



ipsw_filter_v3_device_t* instantiate_ipsw_filter_v3_device(int include_optional) {
  ipsw_filter_v3_device_t* ipsw_filter_v3_device = NULL;
  if (include_optional) {
    ipsw_filter_v3_device = ipsw_filter_v3_device_create(
      "iPhone16,.*"
    );
  } else {
    ipsw_filter_v3_device = ipsw_filter_v3_device_create(
      "iPhone16,.*"
    );
  }

  return ipsw_filter_v3_device;
}


#ifdef ipsw_filter_v3_device_MAIN

void test_ipsw_filter_v3_device(int include_optional) {
    ipsw_filter_v3_device_t* ipsw_filter_v3_device_1 = instantiate_ipsw_filter_v3_device(include_optional);

	cJSON* jsonipsw_filter_v3_device_1 = ipsw_filter_v3_device_convertToJSON(ipsw_filter_v3_device_1);
	printf("ipsw_filter_v3_device :\n%s\n", cJSON_Print(jsonipsw_filter_v3_device_1));
	ipsw_filter_v3_device_t* ipsw_filter_v3_device_2 = ipsw_filter_v3_device_parseFromJSON(jsonipsw_filter_v3_device_1);
	cJSON* jsonipsw_filter_v3_device_2 = ipsw_filter_v3_device_convertToJSON(ipsw_filter_v3_device_2);
	printf("repeating ipsw_filter_v3_device:\n%s\n", cJSON_Print(jsonipsw_filter_v3_device_2));
}

int main() {
  test_ipsw_filter_v3_device(1);
  test_ipsw_filter_v3_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // ipsw_filter_v3_device_MAIN
#endif // ipsw_filter_v3_device_TEST
