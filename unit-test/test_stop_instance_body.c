#ifndef stop_instance_body_TEST
#define stop_instance_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stop_instance_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stop_instance_body.h"
stop_instance_body_t* instantiate_stop_instance_body(int include_optional);



stop_instance_body_t* instantiate_stop_instance_body(int include_optional) {
  stop_instance_body_t* stop_instance_body = NULL;
  if (include_optional) {
    stop_instance_body = stop_instance_body_create(
      1
    );
  } else {
    stop_instance_body = stop_instance_body_create(
      1
    );
  }

  return stop_instance_body;
}


#ifdef stop_instance_body_MAIN

void test_stop_instance_body(int include_optional) {
    stop_instance_body_t* stop_instance_body_1 = instantiate_stop_instance_body(include_optional);

	cJSON* jsonstop_instance_body_1 = stop_instance_body_convertToJSON(stop_instance_body_1);
	printf("stop_instance_body :\n%s\n", cJSON_Print(jsonstop_instance_body_1));
	stop_instance_body_t* stop_instance_body_2 = stop_instance_body_parseFromJSON(jsonstop_instance_body_1);
	cJSON* jsonstop_instance_body_2 = stop_instance_body_convertToJSON(stop_instance_body_2);
	printf("repeating stop_instance_body:\n%s\n", cJSON_Print(jsonstop_instance_body_2));
}

int main() {
  test_stop_instance_body(1);
  test_stop_instance_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // stop_instance_body_MAIN
#endif // stop_instance_body_TEST
