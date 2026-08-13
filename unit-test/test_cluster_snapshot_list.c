#ifndef cluster_snapshot_list_TEST
#define cluster_snapshot_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_snapshot_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_snapshot_list.h"
cluster_snapshot_list_t* instantiate_cluster_snapshot_list(int include_optional);



cluster_snapshot_list_t* instantiate_cluster_snapshot_list(int include_optional) {
  cluster_snapshot_list_t* cluster_snapshot_list = NULL;
  if (include_optional) {
    cluster_snapshot_list = cluster_snapshot_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    cluster_snapshot_list = cluster_snapshot_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return cluster_snapshot_list;
}


#ifdef cluster_snapshot_list_MAIN

void test_cluster_snapshot_list(int include_optional) {
    cluster_snapshot_list_t* cluster_snapshot_list_1 = instantiate_cluster_snapshot_list(include_optional);

	cJSON* jsoncluster_snapshot_list_1 = cluster_snapshot_list_convertToJSON(cluster_snapshot_list_1);
	printf("cluster_snapshot_list :\n%s\n", cJSON_Print(jsoncluster_snapshot_list_1));
	cluster_snapshot_list_t* cluster_snapshot_list_2 = cluster_snapshot_list_parseFromJSON(jsoncluster_snapshot_list_1);
	cJSON* jsoncluster_snapshot_list_2 = cluster_snapshot_list_convertToJSON(cluster_snapshot_list_2);
	printf("repeating cluster_snapshot_list:\n%s\n", cJSON_Print(jsoncluster_snapshot_list_2));
}

int main() {
  test_cluster_snapshot_list(1);
  test_cluster_snapshot_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_snapshot_list_MAIN
#endif // cluster_snapshot_list_TEST
