#ifndef rotate_body_v1_TEST
#define rotate_body_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rotate_body_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rotate_body_v1.h"
rotate_body_v1_t* instantiate_rotate_body_v1(int include_optional);



rotate_body_v1_t* instantiate_rotate_body_v1(int include_optional) {
  rotate_body_v1_t* rotate_body_v1 = NULL;
  if (include_optional) {
    rotate_body_v1 = rotate_body_v1_create(
      corellium_api_rotate_body_v1_ORIENTATION_1
    );
  } else {
    rotate_body_v1 = rotate_body_v1_create(
      corellium_api_rotate_body_v1_ORIENTATION_1
    );
  }

  return rotate_body_v1;
}


#ifdef rotate_body_v1_MAIN

void test_rotate_body_v1(int include_optional) {
    rotate_body_v1_t* rotate_body_v1_1 = instantiate_rotate_body_v1(include_optional);

	cJSON* jsonrotate_body_v1_1 = rotate_body_v1_convertToJSON(rotate_body_v1_1);
	printf("rotate_body_v1 :\n%s\n", cJSON_Print(jsonrotate_body_v1_1));
	rotate_body_v1_t* rotate_body_v1_2 = rotate_body_v1_parseFromJSON(jsonrotate_body_v1_1);
	cJSON* jsonrotate_body_v1_2 = rotate_body_v1_convertToJSON(rotate_body_v1_2);
	printf("repeating rotate_body_v1:\n%s\n", cJSON_Print(jsonrotate_body_v1_2));
}

int main() {
  test_rotate_body_v1(1);
  test_rotate_body_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // rotate_body_v1_MAIN
#endif // rotate_body_v1_TEST
