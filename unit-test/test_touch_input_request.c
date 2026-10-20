#ifndef touch_input_request_TEST
#define touch_input_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define touch_input_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/touch_input_request.h"
touch_input_request_t* instantiate_touch_input_request(int include_optional);



touch_input_request_t* instantiate_touch_input_request(int include_optional) {
  touch_input_request_t* touch_input_request = NULL;
  if (include_optional) {
    touch_input_request = touch_input_request_create(
      [[100,200]],
      ["finger"],
      true,
      100
    );
  } else {
    touch_input_request = touch_input_request_create(
      [[100,200]],
      ["finger"],
      true,
      100
    );
  }

  return touch_input_request;
}


#ifdef touch_input_request_MAIN

void test_touch_input_request(int include_optional) {
    touch_input_request_t* touch_input_request_1 = instantiate_touch_input_request(include_optional);

	cJSON* jsontouch_input_request_1 = touch_input_request_convertToJSON(touch_input_request_1);
	printf("touch_input_request :\n%s\n", cJSON_Print(jsontouch_input_request_1));
	touch_input_request_t* touch_input_request_2 = touch_input_request_parseFromJSON(jsontouch_input_request_1);
	cJSON* jsontouch_input_request_2 = touch_input_request_convertToJSON(touch_input_request_2);
	printf("repeating touch_input_request:\n%s\n", cJSON_Print(jsontouch_input_request_2));
}

int main() {
  test_touch_input_request(1);
  test_touch_input_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // touch_input_request_MAIN
#endif // touch_input_request_TEST
