#ifndef start_instance_body_TEST
#define start_instance_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define start_instance_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/start_instance_body.h"
start_instance_body_t* instantiate_start_instance_body(int include_optional);



start_instance_body_t* instantiate_start_instance_body(int include_optional) {
  start_instance_body_t* start_instance_body = NULL;
  if (include_optional) {
    start_instance_body = start_instance_body_create(
      true,
      true
    );
  } else {
    start_instance_body = start_instance_body_create(
      true,
      true
    );
  }

  return start_instance_body;
}


#ifdef start_instance_body_MAIN

void test_start_instance_body(int include_optional) {
    start_instance_body_t* start_instance_body_1 = instantiate_start_instance_body(include_optional);

	cJSON* jsonstart_instance_body_1 = start_instance_body_convertToJSON(start_instance_body_1);
	printf("start_instance_body :\n%s\n", cJSON_Print(jsonstart_instance_body_1));
	start_instance_body_t* start_instance_body_2 = start_instance_body_parseFromJSON(jsonstart_instance_body_1);
	cJSON* jsonstart_instance_body_2 = start_instance_body_convertToJSON(start_instance_body_2);
	printf("repeating start_instance_body:\n%s\n", cJSON_Print(jsonstart_instance_body_2));
}

int main() {
  test_start_instance_body(1);
  test_start_instance_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // start_instance_body_MAIN
#endif // start_instance_body_TEST
