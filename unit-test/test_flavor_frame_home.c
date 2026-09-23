#ifndef flavor_frame_home_TEST
#define flavor_frame_home_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flavor_frame_home_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flavor_frame_home.h"
flavor_frame_home_t* instantiate_flavor_frame_home(int include_optional);



flavor_frame_home_t* instantiate_flavor_frame_home(int include_optional) {
  flavor_frame_home_t* flavor_frame_home = NULL;
  if (include_optional) {
    flavor_frame_home = flavor_frame_home_create(
      75.43053960964409,
      21.010332950631458,
      258.3237657864524,
      459.47187141216995
    );
  } else {
    flavor_frame_home = flavor_frame_home_create(
      75.43053960964409,
      21.010332950631458,
      258.3237657864524,
      459.47187141216995
    );
  }

  return flavor_frame_home;
}


#ifdef flavor_frame_home_MAIN

void test_flavor_frame_home(int include_optional) {
    flavor_frame_home_t* flavor_frame_home_1 = instantiate_flavor_frame_home(include_optional);

	cJSON* jsonflavor_frame_home_1 = flavor_frame_home_convertToJSON(flavor_frame_home_1);
	printf("flavor_frame_home :\n%s\n", cJSON_Print(jsonflavor_frame_home_1));
	flavor_frame_home_t* flavor_frame_home_2 = flavor_frame_home_parseFromJSON(jsonflavor_frame_home_1);
	cJSON* jsonflavor_frame_home_2 = flavor_frame_home_convertToJSON(flavor_frame_home_2);
	printf("repeating flavor_frame_home:\n%s\n", cJSON_Print(jsonflavor_frame_home_2));
}

int main() {
  test_flavor_frame_home(1);
  test_flavor_frame_home(0);

  printf("Hello world \n");
  return 0;
}

#endif // flavor_frame_home_MAIN
#endif // flavor_frame_home_TEST
