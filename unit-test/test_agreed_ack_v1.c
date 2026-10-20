#ifndef agreed_ack_v1_TEST
#define agreed_ack_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agreed_ack_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agreed_ack_v1.h"
agreed_ack_v1_t* instantiate_agreed_ack_v1(int include_optional);



agreed_ack_v1_t* instantiate_agreed_ack_v1(int include_optional) {
  agreed_ack_v1_t* agreed_ack_v1 = NULL;
  if (include_optional) {
    agreed_ack_v1 = agreed_ack_v1_create(
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    agreed_ack_v1 = agreed_ack_v1_create(
      "2013-10-20T19:20:30+01:00"
    );
  }

  return agreed_ack_v1;
}


#ifdef agreed_ack_v1_MAIN

void test_agreed_ack_v1(int include_optional) {
    agreed_ack_v1_t* agreed_ack_v1_1 = instantiate_agreed_ack_v1(include_optional);

	cJSON* jsonagreed_ack_v1_1 = agreed_ack_v1_convertToJSON(agreed_ack_v1_1);
	printf("agreed_ack_v1 :\n%s\n", cJSON_Print(jsonagreed_ack_v1_1));
	agreed_ack_v1_t* agreed_ack_v1_2 = agreed_ack_v1_parseFromJSON(jsonagreed_ack_v1_1);
	cJSON* jsonagreed_ack_v1_2 = agreed_ack_v1_convertToJSON(agreed_ack_v1_2);
	printf("repeating agreed_ack_v1:\n%s\n", cJSON_Print(jsonagreed_ack_v1_2));
}

int main() {
  test_agreed_ack_v1(1);
  test_agreed_ack_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // agreed_ack_v1_MAIN
#endif // agreed_ack_v1_TEST
