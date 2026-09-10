#ifndef compute_node_file_list_TEST
#define compute_node_file_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define compute_node_file_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/compute_node_file_list.h"
compute_node_file_list_t* instantiate_compute_node_file_list(int include_optional);



compute_node_file_list_t* instantiate_compute_node_file_list(int include_optional) {
  compute_node_file_list_t* compute_node_file_list = NULL;
  if (include_optional) {
    compute_node_file_list = compute_node_file_list_create(
      list_createList()
    );
  } else {
    compute_node_file_list = compute_node_file_list_create(
      list_createList()
    );
  }

  return compute_node_file_list;
}


#ifdef compute_node_file_list_MAIN

void test_compute_node_file_list(int include_optional) {
    compute_node_file_list_t* compute_node_file_list_1 = instantiate_compute_node_file_list(include_optional);

	cJSON* jsoncompute_node_file_list_1 = compute_node_file_list_convertToJSON(compute_node_file_list_1);
	printf("compute_node_file_list :\n%s\n", cJSON_Print(jsoncompute_node_file_list_1));
	compute_node_file_list_t* compute_node_file_list_2 = compute_node_file_list_parseFromJSON(jsoncompute_node_file_list_1);
	cJSON* jsoncompute_node_file_list_2 = compute_node_file_list_convertToJSON(compute_node_file_list_2);
	printf("repeating compute_node_file_list:\n%s\n", cJSON_Print(jsoncompute_node_file_list_2));
}

int main() {
  test_compute_node_file_list(1);
  test_compute_node_file_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // compute_node_file_list_MAIN
#endif // compute_node_file_list_TEST
