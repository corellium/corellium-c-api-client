#ifndef cluster_node_reserved_TEST
#define cluster_node_reserved_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_node_reserved_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_node_reserved.h"
cluster_node_reserved_t* instantiate_cluster_node_reserved(int include_optional);



cluster_node_reserved_t* instantiate_cluster_node_reserved(int include_optional) {
  cluster_node_reserved_t* cluster_node_reserved = NULL;
  if (include_optional) {
    cluster_node_reserved = cluster_node_reserved_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    cluster_node_reserved = cluster_node_reserved_create(
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return cluster_node_reserved;
}


#ifdef cluster_node_reserved_MAIN

void test_cluster_node_reserved(int include_optional) {
    cluster_node_reserved_t* cluster_node_reserved_1 = instantiate_cluster_node_reserved(include_optional);

	cJSON* jsoncluster_node_reserved_1 = cluster_node_reserved_convertToJSON(cluster_node_reserved_1);
	printf("cluster_node_reserved :\n%s\n", cJSON_Print(jsoncluster_node_reserved_1));
	cluster_node_reserved_t* cluster_node_reserved_2 = cluster_node_reserved_parseFromJSON(jsoncluster_node_reserved_1);
	cJSON* jsoncluster_node_reserved_2 = cluster_node_reserved_convertToJSON(cluster_node_reserved_2);
	printf("repeating cluster_node_reserved:\n%s\n", cJSON_Print(jsoncluster_node_reserved_2));
}

int main() {
  test_cluster_node_reserved(1);
  test_cluster_node_reserved(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_node_reserved_MAIN
#endif // cluster_node_reserved_TEST
