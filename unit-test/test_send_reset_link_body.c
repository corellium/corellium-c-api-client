#ifndef send_reset_link_body_TEST
#define send_reset_link_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_reset_link_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_reset_link_body.h"
send_reset_link_body_t* instantiate_send_reset_link_body(int include_optional);



send_reset_link_body_t* instantiate_send_reset_link_body(int include_optional) {
  send_reset_link_body_t* send_reset_link_body = NULL;
  if (include_optional) {
    send_reset_link_body = send_reset_link_body_create(
      "jane.doe@example.com"
    );
  } else {
    send_reset_link_body = send_reset_link_body_create(
      "jane.doe@example.com"
    );
  }

  return send_reset_link_body;
}


#ifdef send_reset_link_body_MAIN

void test_send_reset_link_body(int include_optional) {
    send_reset_link_body_t* send_reset_link_body_1 = instantiate_send_reset_link_body(include_optional);

	cJSON* jsonsend_reset_link_body_1 = send_reset_link_body_convertToJSON(send_reset_link_body_1);
	printf("send_reset_link_body :\n%s\n", cJSON_Print(jsonsend_reset_link_body_1));
	send_reset_link_body_t* send_reset_link_body_2 = send_reset_link_body_parseFromJSON(jsonsend_reset_link_body_1);
	cJSON* jsonsend_reset_link_body_2 = send_reset_link_body_convertToJSON(send_reset_link_body_2);
	printf("repeating send_reset_link_body:\n%s\n", cJSON_Print(jsonsend_reset_link_body_2));
}

int main() {
  test_send_reset_link_body(1);
  test_send_reset_link_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_reset_link_body_MAIN
#endif // send_reset_link_body_TEST
