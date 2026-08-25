#ifndef create_instance_response_TEST
#define create_instance_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_instance_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_instance_response.h"
create_instance_response_t* instantiate_create_instance_response(int include_optional);



create_instance_response_t* instantiate_create_instance_response(int include_optional) {
  create_instance_response_t* create_instance_response = NULL;
  if (include_optional) {
    create_instance_response = create_instance_response_create(
      "0",
      corellium_api_create_instance_response_STATE_creating
    );
  } else {
    create_instance_response = create_instance_response_create(
      "0",
      corellium_api_create_instance_response_STATE_creating
    );
  }

  return create_instance_response;
}


#ifdef create_instance_response_MAIN

void test_create_instance_response(int include_optional) {
    create_instance_response_t* create_instance_response_1 = instantiate_create_instance_response(include_optional);

	cJSON* jsoncreate_instance_response_1 = create_instance_response_convertToJSON(create_instance_response_1);
	printf("create_instance_response :\n%s\n", cJSON_Print(jsoncreate_instance_response_1));
	create_instance_response_t* create_instance_response_2 = create_instance_response_parseFromJSON(jsoncreate_instance_response_1);
	cJSON* jsoncreate_instance_response_2 = create_instance_response_convertToJSON(create_instance_response_2);
	printf("repeating create_instance_response:\n%s\n", cJSON_Print(jsoncreate_instance_response_2));
}

int main() {
  test_create_instance_response(1);
  test_create_instance_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_instance_response_MAIN
#endif // create_instance_response_TEST
