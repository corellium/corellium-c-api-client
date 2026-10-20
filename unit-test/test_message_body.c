#ifndef message_body_TEST
#define message_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_body.h"
message_body_t* instantiate_message_body(int include_optional);



message_body_t* instantiate_message_body(int include_optional) {
  message_body_t* message_body = NULL;
  if (include_optional) {
    message_body = message_body_create(
      "+15555550123",
      "Hello from Corellium!",
      "deadbeef"
    );
  } else {
    message_body = message_body_create(
      "+15555550123",
      "Hello from Corellium!",
      "deadbeef"
    );
  }

  return message_body;
}


#ifdef message_body_MAIN

void test_message_body(int include_optional) {
    message_body_t* message_body_1 = instantiate_message_body(include_optional);

	cJSON* jsonmessage_body_1 = message_body_convertToJSON(message_body_1);
	printf("message_body :\n%s\n", cJSON_Print(jsonmessage_body_1));
	message_body_t* message_body_2 = message_body_parseFromJSON(jsonmessage_body_1);
	cJSON* jsonmessage_body_2 = message_body_convertToJSON(message_body_2);
	printf("repeating message_body:\n%s\n", cJSON_Print(jsonmessage_body_2));
}

int main() {
  test_message_body(1);
  test_message_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_body_MAIN
#endif // message_body_TEST
