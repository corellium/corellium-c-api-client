#ifndef cluster_node_total_TEST
#define cluster_node_total_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_node_total_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_node_total.h"
cluster_node_total_t* instantiate_cluster_node_total(int include_optional);



cluster_node_total_t* instantiate_cluster_node_total(int include_optional) {
  cluster_node_total_t* cluster_node_total = NULL;
  if (include_optional) {
    cluster_node_total = cluster_node_total_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    cluster_node_total = cluster_node_total_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return cluster_node_total;
}


#ifdef cluster_node_total_MAIN

void test_cluster_node_total(int include_optional) {
    cluster_node_total_t* cluster_node_total_1 = instantiate_cluster_node_total(include_optional);

	cJSON* jsoncluster_node_total_1 = cluster_node_total_convertToJSON(cluster_node_total_1);
	printf("cluster_node_total :\n%s\n", cJSON_Print(jsoncluster_node_total_1));
	cluster_node_total_t* cluster_node_total_2 = cluster_node_total_parseFromJSON(jsoncluster_node_total_1);
	cJSON* jsoncluster_node_total_2 = cluster_node_total_convertToJSON(cluster_node_total_2);
	printf("repeating cluster_node_total:\n%s\n", cJSON_Print(jsoncluster_node_total_2));
}

int main() {
  test_cluster_node_total(1);
  test_cluster_node_total(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_node_total_MAIN
#endif // cluster_node_total_TEST
