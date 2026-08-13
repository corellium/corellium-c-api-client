#ifndef input_response_TEST
#define input_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define input_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/input_response.h"
input_response_t* instantiate_input_response(int include_optional);



input_response_t* instantiate_input_response(int include_optional) {
  input_response_t* input_response = NULL;
  if (include_optional) {
    input_response = input_response_create(
      1.337
    );
  } else {
    input_response = input_response_create(
      1.337
    );
  }

  return input_response;
}


#ifdef input_response_MAIN

void test_input_response(int include_optional) {
    input_response_t* input_response_1 = instantiate_input_response(include_optional);

	cJSON* jsoninput_response_1 = input_response_convertToJSON(input_response_1);
	printf("input_response :\n%s\n", cJSON_Print(jsoninput_response_1));
	input_response_t* input_response_2 = input_response_parseFromJSON(jsoninput_response_1);
	cJSON* jsoninput_response_2 = input_response_convertToJSON(input_response_2);
	printf("repeating input_response:\n%s\n", cJSON_Print(jsoninput_response_2));
}

int main() {
  test_input_response(1);
  test_input_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // input_response_MAIN
#endif // input_response_TEST
