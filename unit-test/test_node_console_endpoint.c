#ifndef node_console_endpoint_TEST
#define node_console_endpoint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define node_console_endpoint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/node_console_endpoint.h"
node_console_endpoint_t* instantiate_node_console_endpoint(int include_optional);



node_console_endpoint_t* instantiate_node_console_endpoint(int include_optional) {
  node_console_endpoint_t* node_console_endpoint = NULL;
  if (include_optional) {
    node_console_endpoint = node_console_endpoint_create(
      "0"
    );
  } else {
    node_console_endpoint = node_console_endpoint_create(
      "0"
    );
  }

  return node_console_endpoint;
}


#ifdef node_console_endpoint_MAIN

void test_node_console_endpoint(int include_optional) {
    node_console_endpoint_t* node_console_endpoint_1 = instantiate_node_console_endpoint(include_optional);

	cJSON* jsonnode_console_endpoint_1 = node_console_endpoint_convertToJSON(node_console_endpoint_1);
	printf("node_console_endpoint :\n%s\n", cJSON_Print(jsonnode_console_endpoint_1));
	node_console_endpoint_t* node_console_endpoint_2 = node_console_endpoint_parseFromJSON(jsonnode_console_endpoint_1);
	cJSON* jsonnode_console_endpoint_2 = node_console_endpoint_convertToJSON(node_console_endpoint_2);
	printf("repeating node_console_endpoint:\n%s\n", cJSON_Print(jsonnode_console_endpoint_2));
}

int main() {
  test_node_console_endpoint(1);
  test_node_console_endpoint(0);

  printf("Hello world \n");
  return 0;
}

#endif // node_console_endpoint_MAIN
#endif // node_console_endpoint_TEST
