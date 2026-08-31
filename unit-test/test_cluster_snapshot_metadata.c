#ifndef cluster_snapshot_metadata_TEST
#define cluster_snapshot_metadata_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_snapshot_metadata_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_snapshot_metadata.h"
cluster_snapshot_metadata_t* instantiate_cluster_snapshot_metadata(int include_optional);

#include "test_cluster_snapshot_metadata_boot_options.c"


cluster_snapshot_metadata_t* instantiate_cluster_snapshot_metadata(int include_optional) {
  cluster_snapshot_metadata_t* cluster_snapshot_metadata = NULL;
  if (include_optional) {
    cluster_snapshot_metadata = cluster_snapshot_metadata_create(
      1,
      1,
      1.337,
      1,
      null,
      0,
      "0",
      "0",
      "0",
      "0",
      1.337
    );
  } else {
    cluster_snapshot_metadata = cluster_snapshot_metadata_create(
      1,
      1,
      1.337,
      1,
      null,
      0,
      "0",
      "0",
      "0",
      "0",
      1.337
    );
  }

  return cluster_snapshot_metadata;
}


#ifdef cluster_snapshot_metadata_MAIN

void test_cluster_snapshot_metadata(int include_optional) {
    cluster_snapshot_metadata_t* cluster_snapshot_metadata_1 = instantiate_cluster_snapshot_metadata(include_optional);

	cJSON* jsoncluster_snapshot_metadata_1 = cluster_snapshot_metadata_convertToJSON(cluster_snapshot_metadata_1);
	printf("cluster_snapshot_metadata :\n%s\n", cJSON_Print(jsoncluster_snapshot_metadata_1));
	cluster_snapshot_metadata_t* cluster_snapshot_metadata_2 = cluster_snapshot_metadata_parseFromJSON(jsoncluster_snapshot_metadata_1);
	cJSON* jsoncluster_snapshot_metadata_2 = cluster_snapshot_metadata_convertToJSON(cluster_snapshot_metadata_2);
	printf("repeating cluster_snapshot_metadata:\n%s\n", cJSON_Print(jsoncluster_snapshot_metadata_2));
}

int main() {
  test_cluster_snapshot_metadata(1);
  test_cluster_snapshot_metadata(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_snapshot_metadata_MAIN
#endif // cluster_snapshot_metadata_TEST
