#ifndef cluster_node_status_TEST
#define cluster_node_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_node_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_node_status.h"
cluster_node_status_t* instantiate_cluster_node_status(int include_optional);

#include "test_cluster_node_status_cluster_totals.c"


cluster_node_status_t* instantiate_cluster_node_status(int include_optional) {
  cluster_node_status_t* cluster_node_status = NULL;
  if (include_optional) {
    cluster_node_status = cluster_node_status_create(
       // false, not to have infinite recursion
      instantiate_cluster_node_status_cluster_totals(0),
      list_createList()
    );
  } else {
    cluster_node_status = cluster_node_status_create(
      NULL,
      list_createList()
    );
  }

  return cluster_node_status;
}


#ifdef cluster_node_status_MAIN

void test_cluster_node_status(int include_optional) {
    cluster_node_status_t* cluster_node_status_1 = instantiate_cluster_node_status(include_optional);

	cJSON* jsoncluster_node_status_1 = cluster_node_status_convertToJSON(cluster_node_status_1);
	printf("cluster_node_status :\n%s\n", cJSON_Print(jsoncluster_node_status_1));
	cluster_node_status_t* cluster_node_status_2 = cluster_node_status_parseFromJSON(jsoncluster_node_status_1);
	cJSON* jsoncluster_node_status_2 = cluster_node_status_convertToJSON(cluster_node_status_2);
	printf("repeating cluster_node_status:\n%s\n", cJSON_Print(jsoncluster_node_status_2));
}

int main() {
  test_cluster_node_status(1);
  test_cluster_node_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_node_status_MAIN
#endif // cluster_node_status_TEST
