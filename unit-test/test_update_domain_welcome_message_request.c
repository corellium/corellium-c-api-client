#ifndef update_domain_welcome_message_request_TEST
#define update_domain_welcome_message_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_domain_welcome_message_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_domain_welcome_message_request.h"
update_domain_welcome_message_request_t* instantiate_update_domain_welcome_message_request(int include_optional);



update_domain_welcome_message_request_t* instantiate_update_domain_welcome_message_request(int include_optional) {
  update_domain_welcome_message_request_t* update_domain_welcome_message_request = NULL;
  if (include_optional) {
    update_domain_welcome_message_request = update_domain_welcome_message_request_create(
      "0",
      1
    );
  } else {
    update_domain_welcome_message_request = update_domain_welcome_message_request_create(
      "0",
      1
    );
  }

  return update_domain_welcome_message_request;
}


#ifdef update_domain_welcome_message_request_MAIN

void test_update_domain_welcome_message_request(int include_optional) {
    update_domain_welcome_message_request_t* update_domain_welcome_message_request_1 = instantiate_update_domain_welcome_message_request(include_optional);

	cJSON* jsonupdate_domain_welcome_message_request_1 = update_domain_welcome_message_request_convertToJSON(update_domain_welcome_message_request_1);
	printf("update_domain_welcome_message_request :\n%s\n", cJSON_Print(jsonupdate_domain_welcome_message_request_1));
	update_domain_welcome_message_request_t* update_domain_welcome_message_request_2 = update_domain_welcome_message_request_parseFromJSON(jsonupdate_domain_welcome_message_request_1);
	cJSON* jsonupdate_domain_welcome_message_request_2 = update_domain_welcome_message_request_convertToJSON(update_domain_welcome_message_request_2);
	printf("repeating update_domain_welcome_message_request:\n%s\n", cJSON_Print(jsonupdate_domain_welcome_message_request_2));
}

int main() {
  test_update_domain_welcome_message_request(1);
  test_update_domain_welcome_message_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_domain_welcome_message_request_MAIN
#endif // update_domain_welcome_message_request_TEST
