#ifndef cluster_node_available_TEST
#define cluster_node_available_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_node_available_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_node_available.h"
cluster_node_available_t* instantiate_cluster_node_available(int include_optional);



cluster_node_available_t* instantiate_cluster_node_available(int include_optional) {
  cluster_node_available_t* cluster_node_available = NULL;
  if (include_optional) {
    cluster_node_available = cluster_node_available_create(
      30,
      32768,
      2412.18,
      32,
      2
    );
  } else {
    cluster_node_available = cluster_node_available_create(
      30,
      32768,
      2412.18,
      32,
      2
    );
  }

  return cluster_node_available;
}


#ifdef cluster_node_available_MAIN

void test_cluster_node_available(int include_optional) {
    cluster_node_available_t* cluster_node_available_1 = instantiate_cluster_node_available(include_optional);

	cJSON* jsoncluster_node_available_1 = cluster_node_available_convertToJSON(cluster_node_available_1);
	printf("cluster_node_available :\n%s\n", cJSON_Print(jsoncluster_node_available_1));
	cluster_node_available_t* cluster_node_available_2 = cluster_node_available_parseFromJSON(jsoncluster_node_available_1);
	cJSON* jsoncluster_node_available_2 = cluster_node_available_convertToJSON(cluster_node_available_2);
	printf("repeating cluster_node_available:\n%s\n", cJSON_Print(jsoncluster_node_available_2));
}

int main() {
  test_cluster_node_available(1);
  test_cluster_node_available(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_node_available_MAIN
#endif // cluster_node_available_TEST
