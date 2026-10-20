#ifndef hypertune_hash_response_TEST
#define hypertune_hash_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hypertune_hash_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hypertune_hash_response.h"
hypertune_hash_response_t* instantiate_hypertune_hash_response(int include_optional);



hypertune_hash_response_t* instantiate_hypertune_hash_response(int include_optional) {
  hypertune_hash_response_t* hypertune_hash_response = NULL;
  if (include_optional) {
    hypertune_hash_response = hypertune_hash_response_create(
      "0"
    );
  } else {
    hypertune_hash_response = hypertune_hash_response_create(
      "0"
    );
  }

  return hypertune_hash_response;
}


#ifdef hypertune_hash_response_MAIN

void test_hypertune_hash_response(int include_optional) {
    hypertune_hash_response_t* hypertune_hash_response_1 = instantiate_hypertune_hash_response(include_optional);

	cJSON* jsonhypertune_hash_response_1 = hypertune_hash_response_convertToJSON(hypertune_hash_response_1);
	printf("hypertune_hash_response :\n%s\n", cJSON_Print(jsonhypertune_hash_response_1));
	hypertune_hash_response_t* hypertune_hash_response_2 = hypertune_hash_response_parseFromJSON(jsonhypertune_hash_response_1);
	cJSON* jsonhypertune_hash_response_2 = hypertune_hash_response_convertToJSON(hypertune_hash_response_2);
	printf("repeating hypertune_hash_response:\n%s\n", cJSON_Print(jsonhypertune_hash_response_2));
}

int main() {
  test_hypertune_hash_response(1);
  test_hypertune_hash_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // hypertune_hash_response_MAIN
#endif // hypertune_hash_response_TEST
