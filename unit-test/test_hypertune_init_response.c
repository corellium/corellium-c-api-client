#ifndef hypertune_init_response_TEST
#define hypertune_init_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hypertune_init_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hypertune_init_response.h"
hypertune_init_response_t* instantiate_hypertune_init_response(int include_optional);



hypertune_init_response_t* instantiate_hypertune_init_response(int include_optional) {
  hypertune_init_response_t* hypertune_init_response = NULL;
  if (include_optional) {
    hypertune_init_response = hypertune_init_response_create(
      1.337,
      "0",
      0,
      0,
      0
    );
  } else {
    hypertune_init_response = hypertune_init_response_create(
      1.337,
      "0",
      0,
      0,
      0
    );
  }

  return hypertune_init_response;
}


#ifdef hypertune_init_response_MAIN

void test_hypertune_init_response(int include_optional) {
    hypertune_init_response_t* hypertune_init_response_1 = instantiate_hypertune_init_response(include_optional);

	cJSON* jsonhypertune_init_response_1 = hypertune_init_response_convertToJSON(hypertune_init_response_1);
	printf("hypertune_init_response :\n%s\n", cJSON_Print(jsonhypertune_init_response_1));
	hypertune_init_response_t* hypertune_init_response_2 = hypertune_init_response_parseFromJSON(jsonhypertune_init_response_1);
	cJSON* jsonhypertune_init_response_2 = hypertune_init_response_convertToJSON(hypertune_init_response_2);
	printf("repeating hypertune_init_response:\n%s\n", cJSON_Print(jsonhypertune_init_response_2));
}

int main() {
  test_hypertune_init_response(1);
  test_hypertune_init_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // hypertune_init_response_MAIN
#endif // hypertune_init_response_TEST
