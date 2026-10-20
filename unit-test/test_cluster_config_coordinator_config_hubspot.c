#ifndef cluster_config_coordinator_config_hubspot_TEST
#define cluster_config_coordinator_config_hubspot_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_hubspot_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_hubspot.h"
cluster_config_coordinator_config_hubspot_t* instantiate_cluster_config_coordinator_config_hubspot(int include_optional);



cluster_config_coordinator_config_hubspot_t* instantiate_cluster_config_coordinator_config_hubspot(int include_optional) {
  cluster_config_coordinator_config_hubspot_t* cluster_config_coordinator_config_hubspot = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_hubspot = cluster_config_coordinator_config_hubspot_create(
      "0",
      "0"
    );
  } else {
    cluster_config_coordinator_config_hubspot = cluster_config_coordinator_config_hubspot_create(
      "0",
      "0"
    );
  }

  return cluster_config_coordinator_config_hubspot;
}


#ifdef cluster_config_coordinator_config_hubspot_MAIN

void test_cluster_config_coordinator_config_hubspot(int include_optional) {
    cluster_config_coordinator_config_hubspot_t* cluster_config_coordinator_config_hubspot_1 = instantiate_cluster_config_coordinator_config_hubspot(include_optional);

	cJSON* jsoncluster_config_coordinator_config_hubspot_1 = cluster_config_coordinator_config_hubspot_convertToJSON(cluster_config_coordinator_config_hubspot_1);
	printf("cluster_config_coordinator_config_hubspot :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_hubspot_1));
	cluster_config_coordinator_config_hubspot_t* cluster_config_coordinator_config_hubspot_2 = cluster_config_coordinator_config_hubspot_parseFromJSON(jsoncluster_config_coordinator_config_hubspot_1);
	cJSON* jsoncluster_config_coordinator_config_hubspot_2 = cluster_config_coordinator_config_hubspot_convertToJSON(cluster_config_coordinator_config_hubspot_2);
	printf("repeating cluster_config_coordinator_config_hubspot:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_hubspot_2));
}

int main() {
  test_cluster_config_coordinator_config_hubspot(1);
  test_cluster_config_coordinator_config_hubspot(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_hubspot_MAIN
#endif // cluster_config_coordinator_config_hubspot_TEST
