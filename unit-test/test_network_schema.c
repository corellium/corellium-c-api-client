#ifndef network_schema_TEST
#define network_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define network_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/network_schema.h"
network_schema_t* instantiate_network_schema(int include_optional);



network_schema_t* instantiate_network_schema(int include_optional) {
  network_schema_t* network_schema = NULL;
  if (include_optional) {
    network_schema = network_schema_create(
      list_createList(),
      list_createList()
    );
  } else {
    network_schema = network_schema_create(
      list_createList(),
      list_createList()
    );
  }

  return network_schema;
}


#ifdef network_schema_MAIN

void test_network_schema(int include_optional) {
    network_schema_t* network_schema_1 = instantiate_network_schema(include_optional);

	cJSON* jsonnetwork_schema_1 = network_schema_convertToJSON(network_schema_1);
	printf("network_schema :\n%s\n", cJSON_Print(jsonnetwork_schema_1));
	network_schema_t* network_schema_2 = network_schema_parseFromJSON(jsonnetwork_schema_1);
	cJSON* jsonnetwork_schema_2 = network_schema_convertToJSON(network_schema_2);
	printf("repeating network_schema:\n%s\n", cJSON_Print(jsonnetwork_schema_2));
}

int main() {
  test_network_schema(1);
  test_network_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // network_schema_MAIN
#endif // network_schema_TEST
