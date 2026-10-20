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
      "c67af9c0-26cd-4233-9782-436c842b60db",
      "pre-update-snapshot",
      "b6f1c9d2-8e47-4b3a-9c5d-2f1e8a7b6c5d",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
       // false, not to have infinite recursion
      instantiate_cluster_snapshot_status(0),
      corellium_api_cluster_snapshot_TYPE_iscsi,
      "10.0.0.12:6666",
       // false, not to have infinite recursion
      instantiate_cluster_snapshot_metadata(0),
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    cluster_snapshot = cluster_snapshot_create(
      "c67af9c0-26cd-4233-9782-436c842b60db",
      "pre-update-snapshot",
      "b6f1c9d2-8e47-4b3a-9c5d-2f1e8a7b6c5d",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      NULL,
      corellium_api_cluster_snapshot_TYPE_iscsi,
      "10.0.0.12:6666",
      NULL,
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
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
