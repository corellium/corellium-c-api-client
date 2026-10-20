#ifndef node_updates_failed_TEST
#define node_updates_failed_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define node_updates_failed_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/node_updates_failed.h"
node_updates_failed_t* instantiate_node_updates_failed(int include_optional);



node_updates_failed_t* instantiate_node_updates_failed(int include_optional) {
  node_updates_failed_t* node_updates_failed = NULL;
  if (include_optional) {
    node_updates_failed = node_updates_failed_create(
      "0",
      list_createList()
    );
  } else {
    node_updates_failed = node_updates_failed_create(
      "0",
      list_createList()
    );
  }

  return node_updates_failed;
}


#ifdef node_updates_failed_MAIN

void test_node_updates_failed(int include_optional) {
    node_updates_failed_t* node_updates_failed_1 = instantiate_node_updates_failed(include_optional);

	cJSON* jsonnode_updates_failed_1 = node_updates_failed_convertToJSON(node_updates_failed_1);
	printf("node_updates_failed :\n%s\n", cJSON_Print(jsonnode_updates_failed_1));
	node_updates_failed_t* node_updates_failed_2 = node_updates_failed_parseFromJSON(jsonnode_updates_failed_1);
	cJSON* jsonnode_updates_failed_2 = node_updates_failed_convertToJSON(node_updates_failed_2);
	printf("repeating node_updates_failed:\n%s\n", cJSON_Print(jsonnode_updates_failed_2));
}

int main() {
  test_node_updates_failed(1);
  test_node_updates_failed(0);

  printf("Hello world \n");
  return 0;
}

#endif // node_updates_failed_MAIN
#endif // node_updates_failed_TEST
