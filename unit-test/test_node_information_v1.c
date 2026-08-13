#ifndef node_information_v1_TEST
#define node_information_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define node_information_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/node_information_v1.h"
node_information_v1_t* instantiate_node_information_v1(int include_optional);



node_information_v1_t* instantiate_node_information_v1(int include_optional) {
  node_information_v1_t* node_information_v1 = NULL;
  if (include_optional) {
    node_information_v1 = node_information_v1_create(
      "0",
      "0",
      "0",
      1.337,
      list_createList()
    );
  } else {
    node_information_v1 = node_information_v1_create(
      "0",
      "0",
      "0",
      1.337,
      list_createList()
    );
  }

  return node_information_v1;
}


#ifdef node_information_v1_MAIN

void test_node_information_v1(int include_optional) {
    node_information_v1_t* node_information_v1_1 = instantiate_node_information_v1(include_optional);

	cJSON* jsonnode_information_v1_1 = node_information_v1_convertToJSON(node_information_v1_1);
	printf("node_information_v1 :\n%s\n", cJSON_Print(jsonnode_information_v1_1));
	node_information_v1_t* node_information_v1_2 = node_information_v1_parseFromJSON(jsonnode_information_v1_1);
	cJSON* jsonnode_information_v1_2 = node_information_v1_convertToJSON(node_information_v1_2);
	printf("repeating node_information_v1:\n%s\n", cJSON_Print(jsonnode_information_v1_2));
}

int main() {
  test_node_information_v1(1);
  test_node_information_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // node_information_v1_MAIN
#endif // node_information_v1_TEST
