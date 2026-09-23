#ifndef flavor_frame_TEST
#define flavor_frame_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flavor_frame_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flavor_frame.h"
flavor_frame_t* instantiate_flavor_frame(int include_optional);

#include "test_flavor_frame_inner.c"
#include "test_flavor_frame_home.c"
#include "test_flavor_frame_dimensions.c"


flavor_frame_t* instantiate_flavor_frame(int include_optional) {
  flavor_frame_t* flavor_frame = NULL;
  if (include_optional) {
    flavor_frame = flavor_frame_create(
      "frames/iphone8.png",
      300,
      611.7106773823191,
       // false, not to have infinite recursion
      instantiate_flavor_frame_inner(0),
      {"top":544.8909299655568,"left":125.71756601607349,"width":48.220436280137775,"height":48.220436280137775},
       // false, not to have infinite recursion
      instantiate_flavor_frame_dimensions(0),
      2
    );
  } else {
    flavor_frame = flavor_frame_create(
      "frames/iphone8.png",
      300,
      611.7106773823191,
      NULL,
      {"top":544.8909299655568,"left":125.71756601607349,"width":48.220436280137775,"height":48.220436280137775},
      NULL,
      2
    );
  }

  return flavor_frame;
}


#ifdef flavor_frame_MAIN

void test_flavor_frame(int include_optional) {
    flavor_frame_t* flavor_frame_1 = instantiate_flavor_frame(include_optional);

	cJSON* jsonflavor_frame_1 = flavor_frame_convertToJSON(flavor_frame_1);
	printf("flavor_frame :\n%s\n", cJSON_Print(jsonflavor_frame_1));
	flavor_frame_t* flavor_frame_2 = flavor_frame_parseFromJSON(jsonflavor_frame_1);
	cJSON* jsonflavor_frame_2 = flavor_frame_convertToJSON(flavor_frame_2);
	printf("repeating flavor_frame:\n%s\n", cJSON_Print(jsonflavor_frame_2));
}

int main() {
  test_flavor_frame(1);
  test_flavor_frame(0);

  printf("Hello world \n");
  return 0;
}

#endif // flavor_frame_MAIN
#endif // flavor_frame_TEST
