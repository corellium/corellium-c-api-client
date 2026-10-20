#ifndef cluster_snapshot_status_TEST
#define cluster_snapshot_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_snapshot_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_snapshot_status.h"
cluster_snapshot_status_t* instantiate_cluster_snapshot_status(int include_optional);



cluster_snapshot_status_t* instantiate_cluster_snapshot_status(int include_optional) {
  cluster_snapshot_status_t* cluster_snapshot_status = NULL;
  if (include_optional) {
    cluster_snapshot_status = cluster_snapshot_status_create(
      "creating",
      false
    );
  } else {
    cluster_snapshot_status = cluster_snapshot_status_create(
      "creating",
      false
    );
  }

  return cluster_snapshot_status;
}


#ifdef cluster_snapshot_status_MAIN

void test_cluster_snapshot_status(int include_optional) {
    cluster_snapshot_status_t* cluster_snapshot_status_1 = instantiate_cluster_snapshot_status(include_optional);

	cJSON* jsoncluster_snapshot_status_1 = cluster_snapshot_status_convertToJSON(cluster_snapshot_status_1);
	printf("cluster_snapshot_status :\n%s\n", cJSON_Print(jsoncluster_snapshot_status_1));
	cluster_snapshot_status_t* cluster_snapshot_status_2 = cluster_snapshot_status_parseFromJSON(jsoncluster_snapshot_status_1);
	cJSON* jsoncluster_snapshot_status_2 = cluster_snapshot_status_convertToJSON(cluster_snapshot_status_2);
	printf("repeating cluster_snapshot_status:\n%s\n", cJSON_Print(jsoncluster_snapshot_status_2));
}

int main() {
  test_cluster_snapshot_status(1);
  test_cluster_snapshot_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_snapshot_status_MAIN
#endif // cluster_snapshot_status_TEST
