#ifndef cluster_config_coordinator_config_TEST
#define cluster_config_coordinator_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config.h"
cluster_config_coordinator_config_t* instantiate_cluster_config_coordinator_config(int include_optional);

#include "test_cluster_config_coordinator_config_trial.c"
#include "test_cluster_config_coordinator_config_ensure_domain.c"
#include "test_cluster_config_coordinator_config_hubspot.c"
#include "test_cluster_config_coordinator_config_hypertune.c"
#include "test_cluster_config_coordinator_config_aws_marketplace.c"
#include "test_cluster_config_coordinator_config_pipedrive.c"
#include "test_cluster_config_coordinator_config_webplayer.c"


cluster_config_coordinator_config_t* instantiate_cluster_config_coordinator_config(int include_optional) {
  cluster_config_coordinator_config_t* cluster_config_coordinator_config = NULL;
  if (include_optional) {
    cluster_config_coordinator_config = cluster_config_coordinator_config_create(
      "0",
      1.337,
      "0",
      "0",
      1.337,
      "0",
      "0",
      1,
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_trial(0),
      "0",
      list_createList(),
      1.337,
      "0",
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_ensure_domain(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_hubspot(0),
      "0",
      1.337,
      1.337,
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_hypertune(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_aws_marketplace(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_pipedrive(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_webplayer(0),
      "0",
      "0",
      "0",
      0,
      "0",
      "0",
      1,
      "0",
      "0"
    );
  } else {
    cluster_config_coordinator_config = cluster_config_coordinator_config_create(
      "0",
      1.337,
      "0",
      "0",
      1.337,
      "0",
      "0",
      1,
      "0",
      1.337,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      1,
      list_createList(),
      NULL,
      "0",
      list_createList(),
      1.337,
      "0",
      NULL,
      NULL,
      "0",
      1.337,
      1.337,
      NULL,
      NULL,
      NULL,
      NULL,
      "0",
      "0",
      "0",
      0,
      "0",
      "0",
      1,
      "0",
      "0"
    );
  }

  return cluster_config_coordinator_config;
}


#ifdef cluster_config_coordinator_config_MAIN

void test_cluster_config_coordinator_config(int include_optional) {
    cluster_config_coordinator_config_t* cluster_config_coordinator_config_1 = instantiate_cluster_config_coordinator_config(include_optional);

	cJSON* jsoncluster_config_coordinator_config_1 = cluster_config_coordinator_config_convertToJSON(cluster_config_coordinator_config_1);
	printf("cluster_config_coordinator_config :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_1));
	cluster_config_coordinator_config_t* cluster_config_coordinator_config_2 = cluster_config_coordinator_config_parseFromJSON(jsoncluster_config_coordinator_config_1);
	cJSON* jsoncluster_config_coordinator_config_2 = cluster_config_coordinator_config_convertToJSON(cluster_config_coordinator_config_2);
	printf("repeating cluster_config_coordinator_config:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_2));
}

int main() {
  test_cluster_config_coordinator_config(1);
  test_cluster_config_coordinator_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_MAIN
#endif // cluster_config_coordinator_config_TEST
