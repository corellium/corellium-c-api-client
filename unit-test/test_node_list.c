#ifndef node_list_TEST
#define node_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define node_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/node_list.h"
node_list_t* instantiate_node_list(int include_optional);



node_list_t* instantiate_node_list(int include_optional) {
  node_list_t* node_list = NULL;
  if (include_optional) {
    node_list = node_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    node_list = node_list_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return node_list;
}


#ifdef node_list_MAIN

void test_node_list(int include_optional) {
    node_list_t* node_list_1 = instantiate_node_list(include_optional);

	cJSON* jsonnode_list_1 = node_list_convertToJSON(node_list_1);
	printf("node_list :\n%s\n", cJSON_Print(jsonnode_list_1));
	node_list_t* node_list_2 = node_list_parseFromJSON(jsonnode_list_1);
	cJSON* jsonnode_list_2 = node_list_convertToJSON(node_list_2);
	printf("repeating node_list:\n%s\n", cJSON_Print(jsonnode_list_2));
}

int main() {
  test_node_list(1);
  test_node_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // node_list_MAIN
#endif // node_list_TEST
