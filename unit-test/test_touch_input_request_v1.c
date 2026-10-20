#ifndef touch_input_request_v1_TEST
#define touch_input_request_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define touch_input_request_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/touch_input_request_v1.h"
touch_input_request_v1_t* instantiate_touch_input_request_v1(int include_optional);



touch_input_request_v1_t* instantiate_touch_input_request_v1(int include_optional) {
  touch_input_request_v1_t* touch_input_request_v1 = NULL;
  if (include_optional) {
    touch_input_request_v1 = touch_input_request_v1_create(
      0,
      list_createList(),
      1,
      56
    );
  } else {
    touch_input_request_v1 = touch_input_request_v1_create(
      0,
      list_createList(),
      1,
      56
    );
  }

  return touch_input_request_v1;
}


#ifdef touch_input_request_v1_MAIN

void test_touch_input_request_v1(int include_optional) {
    touch_input_request_v1_t* touch_input_request_v1_1 = instantiate_touch_input_request_v1(include_optional);

	cJSON* jsontouch_input_request_v1_1 = touch_input_request_v1_convertToJSON(touch_input_request_v1_1);
	printf("touch_input_request_v1 :\n%s\n", cJSON_Print(jsontouch_input_request_v1_1));
	touch_input_request_v1_t* touch_input_request_v1_2 = touch_input_request_v1_parseFromJSON(jsontouch_input_request_v1_1);
	cJSON* jsontouch_input_request_v1_2 = touch_input_request_v1_convertToJSON(touch_input_request_v1_2);
	printf("repeating touch_input_request_v1:\n%s\n", cJSON_Print(jsontouch_input_request_v1_2));
}

int main() {
  test_touch_input_request_v1(1);
  test_touch_input_request_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // touch_input_request_v1_MAIN
#endif // touch_input_request_v1_TEST
