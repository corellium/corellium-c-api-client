#ifndef update_network_connection_body_TEST
#define update_network_connection_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_network_connection_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_network_connection_body.h"
update_network_connection_body_t* instantiate_update_network_connection_body(int include_optional);

#include "test_network_connection_config.c"


update_network_connection_body_t* instantiate_update_network_connection_body(int include_optional) {
  update_network_connection_body_t* update_network_connection_body = NULL;
  if (include_optional) {
    update_network_connection_body = update_network_connection_body_create(
      "0",
      null,
      1
    );
  } else {
    update_network_connection_body = update_network_connection_body_create(
      "0",
      null,
      1
    );
  }

  return update_network_connection_body;
}


#ifdef update_network_connection_body_MAIN

void test_update_network_connection_body(int include_optional) {
    update_network_connection_body_t* update_network_connection_body_1 = instantiate_update_network_connection_body(include_optional);

	cJSON* jsonupdate_network_connection_body_1 = update_network_connection_body_convertToJSON(update_network_connection_body_1);
	printf("update_network_connection_body :\n%s\n", cJSON_Print(jsonupdate_network_connection_body_1));
	update_network_connection_body_t* update_network_connection_body_2 = update_network_connection_body_parseFromJSON(jsonupdate_network_connection_body_1);
	cJSON* jsonupdate_network_connection_body_2 = update_network_connection_body_convertToJSON(update_network_connection_body_2);
	printf("repeating update_network_connection_body:\n%s\n", cJSON_Print(jsonupdate_network_connection_body_2));
}

int main() {
  test_update_network_connection_body(1);
  test_update_network_connection_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_network_connection_body_MAIN
#endif // update_network_connection_body_TEST
