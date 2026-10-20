#ifndef delete_network_connection_options_TEST
#define delete_network_connection_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_network_connection_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_network_connection_options.h"
delete_network_connection_options_t* instantiate_delete_network_connection_options(int include_optional);



delete_network_connection_options_t* instantiate_delete_network_connection_options(int include_optional) {
  delete_network_connection_options_t* delete_network_connection_options = NULL;
  if (include_optional) {
    delete_network_connection_options = delete_network_connection_options_create(
      1
    );
  } else {
    delete_network_connection_options = delete_network_connection_options_create(
      1
    );
  }

  return delete_network_connection_options;
}


#ifdef delete_network_connection_options_MAIN

void test_delete_network_connection_options(int include_optional) {
    delete_network_connection_options_t* delete_network_connection_options_1 = instantiate_delete_network_connection_options(include_optional);

	cJSON* jsondelete_network_connection_options_1 = delete_network_connection_options_convertToJSON(delete_network_connection_options_1);
	printf("delete_network_connection_options :\n%s\n", cJSON_Print(jsondelete_network_connection_options_1));
	delete_network_connection_options_t* delete_network_connection_options_2 = delete_network_connection_options_parseFromJSON(jsondelete_network_connection_options_1);
	cJSON* jsondelete_network_connection_options_2 = delete_network_connection_options_convertToJSON(delete_network_connection_options_2);
	printf("repeating delete_network_connection_options:\n%s\n", cJSON_Print(jsondelete_network_connection_options_2));
}

int main() {
  test_delete_network_connection_options(1);
  test_delete_network_connection_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_network_connection_options_MAIN
#endif // delete_network_connection_options_TEST
