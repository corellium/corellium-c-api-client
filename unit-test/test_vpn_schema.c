#ifndef vpn_schema_TEST
#define vpn_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define vpn_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/vpn_schema.h"
vpn_schema_t* instantiate_vpn_schema(int include_optional);



vpn_schema_t* instantiate_vpn_schema(int include_optional) {
  vpn_schema_t* vpn_schema = NULL;
  if (include_optional) {
    vpn_schema = vpn_schema_create(
      "openvpn",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "connected",
      {"error":"connection timed out"}
    );
  } else {
    vpn_schema = vpn_schema_create(
      "openvpn",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "connected",
      {"error":"connection timed out"}
    );
  }

  return vpn_schema;
}


#ifdef vpn_schema_MAIN

void test_vpn_schema(int include_optional) {
    vpn_schema_t* vpn_schema_1 = instantiate_vpn_schema(include_optional);

	cJSON* jsonvpn_schema_1 = vpn_schema_convertToJSON(vpn_schema_1);
	printf("vpn_schema :\n%s\n", cJSON_Print(jsonvpn_schema_1));
	vpn_schema_t* vpn_schema_2 = vpn_schema_parseFromJSON(jsonvpn_schema_1);
	cJSON* jsonvpn_schema_2 = vpn_schema_convertToJSON(vpn_schema_2);
	printf("repeating vpn_schema:\n%s\n", cJSON_Print(jsonvpn_schema_2));
}

int main() {
  test_vpn_schema(1);
  test_vpn_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // vpn_schema_MAIN
#endif // vpn_schema_TEST
