#ifndef touch_curve_input_request_v1_TEST
#define touch_curve_input_request_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define touch_curve_input_request_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/touch_curve_input_request_v1.h"
touch_curve_input_request_v1_t* instantiate_touch_curve_input_request_v1(int include_optional);



touch_curve_input_request_v1_t* instantiate_touch_curve_input_request_v1(int include_optional) {
  touch_curve_input_request_v1_t* touch_curve_input_request_v1 = NULL;
  if (include_optional) {
    touch_curve_input_request_v1 = touch_curve_input_request_v1_create(
      0,
      0,
      list_createList(),
      list_createList(),
      list_createList(),
      1,
      56,
      56
    );
  } else {
    touch_curve_input_request_v1 = touch_curve_input_request_v1_create(
      0,
      0,
      list_createList(),
      list_createList(),
      list_createList(),
      1,
      56,
      56
    );
  }

  return touch_curve_input_request_v1;
}


#ifdef touch_curve_input_request_v1_MAIN

void test_touch_curve_input_request_v1(int include_optional) {
    touch_curve_input_request_v1_t* touch_curve_input_request_v1_1 = instantiate_touch_curve_input_request_v1(include_optional);

	cJSON* jsontouch_curve_input_request_v1_1 = touch_curve_input_request_v1_convertToJSON(touch_curve_input_request_v1_1);
	printf("touch_curve_input_request_v1 :\n%s\n", cJSON_Print(jsontouch_curve_input_request_v1_1));
	touch_curve_input_request_v1_t* touch_curve_input_request_v1_2 = touch_curve_input_request_v1_parseFromJSON(jsontouch_curve_input_request_v1_1);
	cJSON* jsontouch_curve_input_request_v1_2 = touch_curve_input_request_v1_convertToJSON(touch_curve_input_request_v1_2);
	printf("repeating touch_curve_input_request_v1:\n%s\n", cJSON_Print(jsontouch_curve_input_request_v1_2));
}

int main() {
  test_touch_curve_input_request_v1(1);
  test_touch_curve_input_request_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // touch_curve_input_request_v1_MAIN
#endif // touch_curve_input_request_v1_TEST
