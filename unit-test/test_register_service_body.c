#ifndef register_service_body_TEST
#define register_service_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define register_service_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/register_service_body.h"
register_service_body_t* instantiate_register_service_body(int include_optional);



register_service_body_t* instantiate_register_service_body(int include_optional) {
  register_service_body_t* register_service_body = NULL;
  if (include_optional) {
    register_service_body = register_service_body_create(
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0"
    );
  } else {
    register_service_body = register_service_body_create(
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0"
    );
  }

  return register_service_body;
}


#ifdef register_service_body_MAIN

void test_register_service_body(int include_optional) {
    register_service_body_t* register_service_body_1 = instantiate_register_service_body(include_optional);

	cJSON* jsonregister_service_body_1 = register_service_body_convertToJSON(register_service_body_1);
	printf("register_service_body :\n%s\n", cJSON_Print(jsonregister_service_body_1));
	register_service_body_t* register_service_body_2 = register_service_body_parseFromJSON(jsonregister_service_body_1);
	cJSON* jsonregister_service_body_2 = register_service_body_convertToJSON(register_service_body_2);
	printf("repeating register_service_body:\n%s\n", cJSON_Print(jsonregister_service_body_2));
}

int main() {
  test_register_service_body(1);
  test_register_service_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // register_service_body_MAIN
#endif // register_service_body_TEST
