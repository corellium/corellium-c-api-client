#ifndef flavor_frame_dimensions_TEST
#define flavor_frame_dimensions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flavor_frame_dimensions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flavor_frame_dimensions.h"
flavor_frame_dimensions_t* instantiate_flavor_frame_dimensions(int include_optional);



flavor_frame_dimensions_t* instantiate_flavor_frame_dimensions(int include_optional) {
  flavor_frame_dimensions_t* flavor_frame_dimensions = NULL;
  if (include_optional) {
    flavor_frame_dimensions = flavor_frame_dimensions_create(
      750,
      1334
    );
  } else {
    flavor_frame_dimensions = flavor_frame_dimensions_create(
      750,
      1334
    );
  }

  return flavor_frame_dimensions;
}


#ifdef flavor_frame_dimensions_MAIN

void test_flavor_frame_dimensions(int include_optional) {
    flavor_frame_dimensions_t* flavor_frame_dimensions_1 = instantiate_flavor_frame_dimensions(include_optional);

	cJSON* jsonflavor_frame_dimensions_1 = flavor_frame_dimensions_convertToJSON(flavor_frame_dimensions_1);
	printf("flavor_frame_dimensions :\n%s\n", cJSON_Print(jsonflavor_frame_dimensions_1));
	flavor_frame_dimensions_t* flavor_frame_dimensions_2 = flavor_frame_dimensions_parseFromJSON(jsonflavor_frame_dimensions_1);
	cJSON* jsonflavor_frame_dimensions_2 = flavor_frame_dimensions_convertToJSON(flavor_frame_dimensions_2);
	printf("repeating flavor_frame_dimensions:\n%s\n", cJSON_Print(jsonflavor_frame_dimensions_2));
}

int main() {
  test_flavor_frame_dimensions(1);
  test_flavor_frame_dimensions(0);

  printf("Hello world \n");
  return 0;
}

#endif // flavor_frame_dimensions_MAIN
#endif // flavor_frame_dimensions_TEST
