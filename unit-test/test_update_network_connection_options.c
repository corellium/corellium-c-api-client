#ifndef update_network_connection_options_TEST
#define update_network_connection_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_network_connection_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_network_connection_options.h"
update_network_connection_options_t* instantiate_update_network_connection_options(int include_optional);



update_network_connection_options_t* instantiate_update_network_connection_options(int include_optional) {
  update_network_connection_options_t* update_network_connection_options = NULL;
  if (include_optional) {
    update_network_connection_options = update_network_connection_options_create(
      "0",
      0,
      1
    );
  } else {
    update_network_connection_options = update_network_connection_options_create(
      "0",
      0,
      1
    );
  }

  return update_network_connection_options;
}


#ifdef update_network_connection_options_MAIN

void test_update_network_connection_options(int include_optional) {
    update_network_connection_options_t* update_network_connection_options_1 = instantiate_update_network_connection_options(include_optional);

	cJSON* jsonupdate_network_connection_options_1 = update_network_connection_options_convertToJSON(update_network_connection_options_1);
	printf("update_network_connection_options :\n%s\n", cJSON_Print(jsonupdate_network_connection_options_1));
	update_network_connection_options_t* update_network_connection_options_2 = update_network_connection_options_parseFromJSON(jsonupdate_network_connection_options_1);
	cJSON* jsonupdate_network_connection_options_2 = update_network_connection_options_convertToJSON(update_network_connection_options_2);
	printf("repeating update_network_connection_options:\n%s\n", cJSON_Print(jsonupdate_network_connection_options_2));
}

int main() {
  test_update_network_connection_options(1);
  test_update_network_connection_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_network_connection_options_MAIN
#endif // update_network_connection_options_TEST
