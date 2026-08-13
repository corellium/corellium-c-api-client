#ifndef create_network_connection_options_TEST
#define create_network_connection_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_network_connection_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_network_connection_options.h"
create_network_connection_options_t* instantiate_create_network_connection_options(int include_optional);



create_network_connection_options_t* instantiate_create_network_connection_options(int include_optional) {
  create_network_connection_options_t* create_network_connection_options = NULL;
  if (include_optional) {
    create_network_connection_options = create_network_connection_options_create(
      "0",
      "0",
      "0",
      0
    );
  } else {
    create_network_connection_options = create_network_connection_options_create(
      "0",
      "0",
      "0",
      0
    );
  }

  return create_network_connection_options;
}


#ifdef create_network_connection_options_MAIN

void test_create_network_connection_options(int include_optional) {
    create_network_connection_options_t* create_network_connection_options_1 = instantiate_create_network_connection_options(include_optional);

	cJSON* jsoncreate_network_connection_options_1 = create_network_connection_options_convertToJSON(create_network_connection_options_1);
	printf("create_network_connection_options :\n%s\n", cJSON_Print(jsoncreate_network_connection_options_1));
	create_network_connection_options_t* create_network_connection_options_2 = create_network_connection_options_parseFromJSON(jsoncreate_network_connection_options_1);
	cJSON* jsoncreate_network_connection_options_2 = create_network_connection_options_convertToJSON(create_network_connection_options_2);
	printf("repeating create_network_connection_options:\n%s\n", cJSON_Print(jsoncreate_network_connection_options_2));
}

int main() {
  test_create_network_connection_options(1);
  test_create_network_connection_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_network_connection_options_MAIN
#endif // create_network_connection_options_TEST
