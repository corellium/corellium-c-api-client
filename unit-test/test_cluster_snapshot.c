#ifndef cluster_snapshot_TEST
#define cluster_snapshot_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_snapshot_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_snapshot.h"
cluster_snapshot_t* instantiate_cluster_snapshot(int include_optional);

#include "test_cluster_snapshot_status.c"
#include "test_cluster_snapshot_metadata.c"


cluster_snapshot_t* instantiate_cluster_snapshot(int include_optional) {
  cluster_snapshot_t* cluster_snapshot = NULL;
  if (include_optional) {
    cluster_snapshot = cluster_snapshot_create(
      "0",
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_cluster_snapshot_status(0),
      corellium_api_cluster_snapshot_TYPE_iscsi,
      "0",
       // false, not to have infinite recursion
      instantiate_cluster_snapshot_metadata(0),
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    cluster_snapshot = cluster_snapshot_create(
      "0",
      "0",
      "0",
      "0",
      NULL,
      corellium_api_cluster_snapshot_TYPE_iscsi,
      "0",
      NULL,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return cluster_snapshot;
}


#ifdef cluster_snapshot_MAIN

void test_cluster_snapshot(int include_optional) {
    cluster_snapshot_t* cluster_snapshot_1 = instantiate_cluster_snapshot(include_optional);

	cJSON* jsoncluster_snapshot_1 = cluster_snapshot_convertToJSON(cluster_snapshot_1);
	printf("cluster_snapshot :\n%s\n", cJSON_Print(jsoncluster_snapshot_1));
	cluster_snapshot_t* cluster_snapshot_2 = cluster_snapshot_parseFromJSON(jsoncluster_snapshot_1);
	cJSON* jsoncluster_snapshot_2 = cluster_snapshot_convertToJSON(cluster_snapshot_2);
	printf("repeating cluster_snapshot:\n%s\n", cJSON_Print(jsoncluster_snapshot_2));
}

int main() {
  test_cluster_snapshot(1);
  test_cluster_snapshot(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_snapshot_MAIN
#endif // cluster_snapshot_TEST
