#ifndef message_body_any_of_TEST
#define message_body_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_body_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_body_any_of.h"
message_body_any_of_t* instantiate_message_body_any_of(int include_optional);



message_body_any_of_t* instantiate_message_body_any_of(int include_optional) {
  message_body_any_of_t* message_body_any_of = NULL;
  if (include_optional) {
    message_body_any_of = message_body_any_of_create(
      "0",
      "0"
    );
  } else {
    message_body_any_of = message_body_any_of_create(
      "0",
      "0"
    );
  }

  return message_body_any_of;
}


#ifdef message_body_any_of_MAIN

void test_message_body_any_of(int include_optional) {
    message_body_any_of_t* message_body_any_of_1 = instantiate_message_body_any_of(include_optional);

	cJSON* jsonmessage_body_any_of_1 = message_body_any_of_convertToJSON(message_body_any_of_1);
	printf("message_body_any_of :\n%s\n", cJSON_Print(jsonmessage_body_any_of_1));
	message_body_any_of_t* message_body_any_of_2 = message_body_any_of_parseFromJSON(jsonmessage_body_any_of_1);
	cJSON* jsonmessage_body_any_of_2 = message_body_any_of_convertToJSON(message_body_any_of_2);
	printf("repeating message_body_any_of:\n%s\n", cJSON_Print(jsonmessage_body_any_of_2));
}

int main() {
  test_message_body_any_of(1);
  test_message_body_any_of(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_body_any_of_MAIN
#endif // message_body_any_of_TEST
