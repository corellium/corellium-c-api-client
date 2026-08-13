#ifndef flavor_frame_inner_TEST
#define flavor_frame_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flavor_frame_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flavor_frame_inner.h"
flavor_frame_inner_t* instantiate_flavor_frame_inner(int include_optional);



flavor_frame_inner_t* instantiate_flavor_frame_inner(int include_optional) {
  flavor_frame_inner_t* flavor_frame_inner = NULL;
  if (include_optional) {
    flavor_frame_inner = flavor_frame_inner_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    flavor_frame_inner = flavor_frame_inner_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return flavor_frame_inner;
}


#ifdef flavor_frame_inner_MAIN

void test_flavor_frame_inner(int include_optional) {
    flavor_frame_inner_t* flavor_frame_inner_1 = instantiate_flavor_frame_inner(include_optional);

	cJSON* jsonflavor_frame_inner_1 = flavor_frame_inner_convertToJSON(flavor_frame_inner_1);
	printf("flavor_frame_inner :\n%s\n", cJSON_Print(jsonflavor_frame_inner_1));
	flavor_frame_inner_t* flavor_frame_inner_2 = flavor_frame_inner_parseFromJSON(jsonflavor_frame_inner_1);
	cJSON* jsonflavor_frame_inner_2 = flavor_frame_inner_convertToJSON(flavor_frame_inner_2);
	printf("repeating flavor_frame_inner:\n%s\n", cJSON_Print(jsonflavor_frame_inner_2));
}

int main() {
  test_flavor_frame_inner(1);
  test_flavor_frame_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // flavor_frame_inner_MAIN
#endif // flavor_frame_inner_TEST
