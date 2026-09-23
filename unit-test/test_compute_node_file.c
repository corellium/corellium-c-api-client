#ifndef compute_node_file_TEST
#define compute_node_file_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define compute_node_file_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/compute_node_file.h"
compute_node_file_t* instantiate_compute_node_file(int include_optional);



compute_node_file_t* instantiate_compute_node_file(int include_optional) {
  compute_node_file_t* compute_node_file = NULL;
  if (include_optional) {
    compute_node_file = compute_node_file_create(
      "/mnt/charm_f7f9832a-f824-416f-a5ea-4adfe34754b5_tmp/strace-0",
      268435456,
      "2026-03-17T11:41:05Z"
    );
  } else {
    compute_node_file = compute_node_file_create(
      "/mnt/charm_f7f9832a-f824-416f-a5ea-4adfe34754b5_tmp/strace-0",
      268435456,
      "2026-03-17T11:41:05Z"
    );
  }

  return compute_node_file;
}


#ifdef compute_node_file_MAIN

void test_compute_node_file(int include_optional) {
    compute_node_file_t* compute_node_file_1 = instantiate_compute_node_file(include_optional);

	cJSON* jsoncompute_node_file_1 = compute_node_file_convertToJSON(compute_node_file_1);
	printf("compute_node_file :\n%s\n", cJSON_Print(jsoncompute_node_file_1));
	compute_node_file_t* compute_node_file_2 = compute_node_file_parseFromJSON(jsoncompute_node_file_1);
	cJSON* jsoncompute_node_file_2 = compute_node_file_convertToJSON(compute_node_file_2);
	printf("repeating compute_node_file:\n%s\n", cJSON_Print(jsoncompute_node_file_2));
}

int main() {
  test_compute_node_file(1);
  test_compute_node_file(0);

  printf("Hello world \n");
  return 0;
}

#endif // compute_node_file_MAIN
#endif // compute_node_file_TEST
