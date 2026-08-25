#ifndef interconnect_protocol_TEST
#define interconnect_protocol_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define interconnect_protocol_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/interconnect_protocol.h"
interconnect_protocol_t* instantiate_interconnect_protocol(int include_optional);



interconnect_protocol_t* instantiate_interconnect_protocol(int include_optional) {
  interconnect_protocol_t* interconnect_protocol = NULL;
  if (include_optional) {
    interconnect_protocol = interconnect_protocol_create(
    );
  } else {
    interconnect_protocol = interconnect_protocol_create(
    );
  }

  return interconnect_protocol;
}


#ifdef interconnect_protocol_MAIN

void test_interconnect_protocol(int include_optional) {
    interconnect_protocol_t* interconnect_protocol_1 = instantiate_interconnect_protocol(include_optional);

	cJSON* jsoninterconnect_protocol_1 = interconnect_protocol_convertToJSON(interconnect_protocol_1);
	printf("interconnect_protocol :\n%s\n", cJSON_Print(jsoninterconnect_protocol_1));
	interconnect_protocol_t* interconnect_protocol_2 = interconnect_protocol_parseFromJSON(jsoninterconnect_protocol_1);
	cJSON* jsoninterconnect_protocol_2 = interconnect_protocol_convertToJSON(interconnect_protocol_2);
	printf("repeating interconnect_protocol:\n%s\n", cJSON_Print(jsoninterconnect_protocol_2));
}

int main() {
  test_interconnect_protocol(1);
  test_interconnect_protocol(0);

  printf("Hello world \n");
  return 0;
}

#endif // interconnect_protocol_MAIN
#endif // interconnect_protocol_TEST
