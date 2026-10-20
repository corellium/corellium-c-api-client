#ifndef input_response_v1_TEST
#define input_response_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_response_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_response_v1.h"
input_response_v1_t* instantiate_input_response_v1(int include_optional);



input_response_v1_t* instantiate_input_response_v1(int include_optional) {
  input_response_v1_t* input_response_v1 = NULL;
  if (include_optional) {
    input_response_v1 = input_response_v1_create(
      1.337
    );
  } else {
    input_response_v1 = input_response_v1_create(
      1.337
    );
  }

  return input_response_v1;
}


#ifdef input_response_v1_MAIN

void test_input_response_v1(int include_optional) {
    input_response_v1_t* input_response_v1_1 = instantiate_input_response_v1(include_optional);

	cJSON* jsoninput_response_v1_1 = input_response_v1_convertToJSON(input_response_v1_1);
	printf("input_response_v1 :\n%s\n", cJSON_Print(jsoninput_response_v1_1));
	input_response_v1_t* input_response_v1_2 = input_response_v1_parseFromJSON(jsoninput_response_v1_1);
	cJSON* jsoninput_response_v1_2 = input_response_v1_convertToJSON(input_response_v1_2);
	printf("repeating input_response_v1:\n%s\n", cJSON_Print(jsoninput_response_v1_2));
}

int main() {
  test_input_response_v1(1);
  test_input_response_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_response_v1_MAIN
#endif // input_response_v1_TEST
