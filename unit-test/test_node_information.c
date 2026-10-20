#ifndef node_information_TEST
#define node_information_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define node_information_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/node_information.h"
node_information_t* instantiate_node_information(int include_optional);



node_information_t* instantiate_node_information(int include_optional) {
  node_information_t* node_information = NULL;
  if (include_optional) {
    node_information = node_information_create(
      "2x3ZOdu4pshouoY0kttRPoiIk5s",
      "10.0.0.12",
      "node-01.example.com",
      22,
      ["controller","compute"]
    );
  } else {
    node_information = node_information_create(
      "2x3ZOdu4pshouoY0kttRPoiIk5s",
      "10.0.0.12",
      "node-01.example.com",
      22,
      ["controller","compute"]
    );
  }

  return node_information;
}


#ifdef node_information_MAIN

void test_node_information(int include_optional) {
    node_information_t* node_information_1 = instantiate_node_information(include_optional);

	cJSON* jsonnode_information_1 = node_information_convertToJSON(node_information_1);
	printf("node_information :\n%s\n", cJSON_Print(jsonnode_information_1));
	node_information_t* node_information_2 = node_information_parseFromJSON(jsonnode_information_1);
	cJSON* jsonnode_information_2 = node_information_convertToJSON(node_information_2);
	printf("repeating node_information:\n%s\n", cJSON_Print(jsonnode_information_2));
}

int main() {
  test_node_information(1);
  test_node_information(0);

  printf("Hello world \n");
  return 0;
}

#endif // node_information_MAIN
#endif // node_information_TEST
