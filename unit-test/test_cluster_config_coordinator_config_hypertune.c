#ifndef cluster_config_coordinator_config_hypertune_TEST
#define cluster_config_coordinator_config_hypertune_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_hypertune_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_hypertune.h"
cluster_config_coordinator_config_hypertune_t* instantiate_cluster_config_coordinator_config_hypertune(int include_optional);



cluster_config_coordinator_config_hypertune_t* instantiate_cluster_config_coordinator_config_hypertune(int include_optional) {
  cluster_config_coordinator_config_hypertune_t* cluster_config_coordinator_config_hypertune = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_hypertune = cluster_config_coordinator_config_hypertune_create(
      "0",
      "0",
      "0"
    );
  } else {
    cluster_config_coordinator_config_hypertune = cluster_config_coordinator_config_hypertune_create(
      "0",
      "0",
      "0"
    );
  }

  return cluster_config_coordinator_config_hypertune;
}


#ifdef cluster_config_coordinator_config_hypertune_MAIN

void test_cluster_config_coordinator_config_hypertune(int include_optional) {
    cluster_config_coordinator_config_hypertune_t* cluster_config_coordinator_config_hypertune_1 = instantiate_cluster_config_coordinator_config_hypertune(include_optional);

	cJSON* jsoncluster_config_coordinator_config_hypertune_1 = cluster_config_coordinator_config_hypertune_convertToJSON(cluster_config_coordinator_config_hypertune_1);
	printf("cluster_config_coordinator_config_hypertune :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_hypertune_1));
	cluster_config_coordinator_config_hypertune_t* cluster_config_coordinator_config_hypertune_2 = cluster_config_coordinator_config_hypertune_parseFromJSON(jsoncluster_config_coordinator_config_hypertune_1);
	cJSON* jsoncluster_config_coordinator_config_hypertune_2 = cluster_config_coordinator_config_hypertune_convertToJSON(cluster_config_coordinator_config_hypertune_2);
	printf("repeating cluster_config_coordinator_config_hypertune:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_hypertune_2));
}

int main() {
  test_cluster_config_coordinator_config_hypertune(1);
  test_cluster_config_coordinator_config_hypertune(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_hypertune_MAIN
#endif // cluster_config_coordinator_config_hypertune_TEST
