#ifndef cluster_node_TEST
#define cluster_node_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_node_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_node.h"
cluster_node_t* instantiate_cluster_node(int include_optional);

#include "test_cluster_node_reserved.c"
#include "test_cluster_node_total.c"
#include "test_cluster_node_available.c"


cluster_node_t* instantiate_cluster_node(int include_optional) {
  cluster_node_t* cluster_node = NULL;
  if (include_optional) {
    cluster_node = cluster_node_create(
       // false, not to have infinite recursion
      instantiate_cluster_node_reserved(0),
       // false, not to have infinite recursion
      instantiate_cluster_node_total(0),
       // false, not to have infinite recursion
      instantiate_cluster_node_available(0),
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    cluster_node = cluster_node_create(
      NULL,
      NULL,
      NULL,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return cluster_node;
}


#ifdef cluster_node_MAIN

void test_cluster_node(int include_optional) {
    cluster_node_t* cluster_node_1 = instantiate_cluster_node(include_optional);

	cJSON* jsoncluster_node_1 = cluster_node_convertToJSON(cluster_node_1);
	printf("cluster_node :\n%s\n", cJSON_Print(jsoncluster_node_1));
	cluster_node_t* cluster_node_2 = cluster_node_parseFromJSON(jsoncluster_node_1);
	cJSON* jsoncluster_node_2 = cluster_node_convertToJSON(cluster_node_2);
	printf("repeating cluster_node:\n%s\n", cJSON_Print(jsoncluster_node_2));
}

int main() {
  test_cluster_node(1);
  test_cluster_node(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_node_MAIN
#endif // cluster_node_TEST
