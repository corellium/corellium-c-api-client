#ifndef text_input_request_TEST
#define text_input_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define text_input_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/text_input_request.h"
text_input_request_t* instantiate_text_input_request(int include_optional);



text_input_request_t* instantiate_text_input_request(int include_optional) {
  text_input_request_t* text_input_request = NULL;
  if (include_optional) {
    text_input_request = text_input_request_create(
      "0",
      56
    );
  } else {
    text_input_request = text_input_request_create(
      "0",
      56
    );
  }

  return text_input_request;
}


#ifdef text_input_request_MAIN

void test_text_input_request(int include_optional) {
    text_input_request_t* text_input_request_1 = instantiate_text_input_request(include_optional);

	cJSON* jsontext_input_request_1 = text_input_request_convertToJSON(text_input_request_1);
	printf("text_input_request :\n%s\n", cJSON_Print(jsontext_input_request_1));
	text_input_request_t* text_input_request_2 = text_input_request_parseFromJSON(jsontext_input_request_1);
	cJSON* jsontext_input_request_2 = text_input_request_convertToJSON(text_input_request_2);
	printf("repeating text_input_request:\n%s\n", cJSON_Print(jsontext_input_request_2));
}

int main() {
  test_text_input_request(1);
  test_text_input_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // text_input_request_MAIN
#endif // text_input_request_TEST
