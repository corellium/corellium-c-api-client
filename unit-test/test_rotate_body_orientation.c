#ifndef rotate_body_orientation_TEST
#define rotate_body_orientation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rotate_body_orientation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rotate_body_orientation.h"
rotate_body_orientation_t* instantiate_rotate_body_orientation(int include_optional);



rotate_body_orientation_t* instantiate_rotate_body_orientation(int include_optional) {
  rotate_body_orientation_t* rotate_body_orientation = NULL;
  if (include_optional) {
    rotate_body_orientation = rotate_body_orientation_create(
    );
  } else {
    rotate_body_orientation = rotate_body_orientation_create(
    );
  }

  return rotate_body_orientation;
}


#ifdef rotate_body_orientation_MAIN

void test_rotate_body_orientation(int include_optional) {
    rotate_body_orientation_t* rotate_body_orientation_1 = instantiate_rotate_body_orientation(include_optional);

	cJSON* jsonrotate_body_orientation_1 = rotate_body_orientation_convertToJSON(rotate_body_orientation_1);
	printf("rotate_body_orientation :\n%s\n", cJSON_Print(jsonrotate_body_orientation_1));
	rotate_body_orientation_t* rotate_body_orientation_2 = rotate_body_orientation_parseFromJSON(jsonrotate_body_orientation_1);
	cJSON* jsonrotate_body_orientation_2 = rotate_body_orientation_convertToJSON(rotate_body_orientation_2);
	printf("repeating rotate_body_orientation:\n%s\n", cJSON_Print(jsonrotate_body_orientation_2));
}

int main() {
  test_rotate_body_orientation(1);
  test_rotate_body_orientation(0);

  printf("Hello world \n");
  return 0;
}

#endif // rotate_body_orientation_MAIN
#endif // rotate_body_orientation_TEST
