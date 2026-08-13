#ifndef cluster_snapshot_v1_TEST
#define cluster_snapshot_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_snapshot_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_snapshot_v1.h"
cluster_snapshot_v1_t* instantiate_cluster_snapshot_v1(int include_optional);



cluster_snapshot_v1_t* instantiate_cluster_snapshot_v1(int include_optional) {
  cluster_snapshot_v1_t* cluster_snapshot_v1 = NULL;
  if (include_optional) {
    cluster_snapshot_v1 = cluster_snapshot_v1_create(
      "0"
    );
  } else {
    cluster_snapshot_v1 = cluster_snapshot_v1_create(
      "0"
    );
  }

  return cluster_snapshot_v1;
}


#ifdef cluster_snapshot_v1_MAIN

void test_cluster_snapshot_v1(int include_optional) {
    cluster_snapshot_v1_t* cluster_snapshot_v1_1 = instantiate_cluster_snapshot_v1(include_optional);

	cJSON* jsoncluster_snapshot_v1_1 = cluster_snapshot_v1_convertToJSON(cluster_snapshot_v1_1);
	printf("cluster_snapshot_v1 :\n%s\n", cJSON_Print(jsoncluster_snapshot_v1_1));
	cluster_snapshot_v1_t* cluster_snapshot_v1_2 = cluster_snapshot_v1_parseFromJSON(jsoncluster_snapshot_v1_1);
	cJSON* jsoncluster_snapshot_v1_2 = cluster_snapshot_v1_convertToJSON(cluster_snapshot_v1_2);
	printf("repeating cluster_snapshot_v1:\n%s\n", cJSON_Print(jsoncluster_snapshot_v1_2));
}

int main() {
  test_cluster_snapshot_v1(1);
  test_cluster_snapshot_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_snapshot_v1_MAIN
#endif // cluster_snapshot_v1_TEST
