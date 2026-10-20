#ifndef text_input_request_v1_TEST
#define text_input_request_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define text_input_request_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/text_input_request_v1.h"
text_input_request_v1_t* instantiate_text_input_request_v1(int include_optional);



text_input_request_v1_t* instantiate_text_input_request_v1(int include_optional) {
  text_input_request_v1_t* text_input_request_v1 = NULL;
  if (include_optional) {
    text_input_request_v1 = text_input_request_v1_create(
      "0",
      56
    );
  } else {
    text_input_request_v1 = text_input_request_v1_create(
      "0",
      56
    );
  }

  return text_input_request_v1;
}


#ifdef text_input_request_v1_MAIN

void test_text_input_request_v1(int include_optional) {
    text_input_request_v1_t* text_input_request_v1_1 = instantiate_text_input_request_v1(include_optional);

	cJSON* jsontext_input_request_v1_1 = text_input_request_v1_convertToJSON(text_input_request_v1_1);
	printf("text_input_request_v1 :\n%s\n", cJSON_Print(jsontext_input_request_v1_1));
	text_input_request_v1_t* text_input_request_v1_2 = text_input_request_v1_parseFromJSON(jsontext_input_request_v1_1);
	cJSON* jsontext_input_request_v1_2 = text_input_request_v1_convertToJSON(text_input_request_v1_2);
	printf("repeating text_input_request_v1:\n%s\n", cJSON_Print(jsontext_input_request_v1_2));
}

int main() {
  test_text_input_request_v1(1);
  test_text_input_request_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // text_input_request_v1_MAIN
#endif // text_input_request_v1_TEST
