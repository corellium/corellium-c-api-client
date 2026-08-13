#ifndef volume_options_v1_TEST
#define volume_options_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define volume_options_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/volume_options_v1.h"
volume_options_v1_t* instantiate_volume_options_v1(int include_optional);



volume_options_v1_t* instantiate_volume_options_v1(int include_optional) {
  volume_options_v1_t* volume_options_v1 = NULL;
  if (include_optional) {
    volume_options_v1 = volume_options_v1_create(
      1.337,
      "0"
    );
  } else {
    volume_options_v1 = volume_options_v1_create(
      1.337,
      "0"
    );
  }

  return volume_options_v1;
}


#ifdef volume_options_v1_MAIN

void test_volume_options_v1(int include_optional) {
    volume_options_v1_t* volume_options_v1_1 = instantiate_volume_options_v1(include_optional);

	cJSON* jsonvolume_options_v1_1 = volume_options_v1_convertToJSON(volume_options_v1_1);
	printf("volume_options_v1 :\n%s\n", cJSON_Print(jsonvolume_options_v1_1));
	volume_options_v1_t* volume_options_v1_2 = volume_options_v1_parseFromJSON(jsonvolume_options_v1_1);
	cJSON* jsonvolume_options_v1_2 = volume_options_v1_convertToJSON(volume_options_v1_2);
	printf("repeating volume_options_v1:\n%s\n", cJSON_Print(jsonvolume_options_v1_2));
}

int main() {
  test_volume_options_v1(1);
  test_volume_options_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // volume_options_v1_MAIN
#endif // volume_options_v1_TEST
