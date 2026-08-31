#ifndef cluster_config_coordinator_config_pipedrive_TEST
#define cluster_config_coordinator_config_pipedrive_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_pipedrive_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_pipedrive.h"
cluster_config_coordinator_config_pipedrive_t* instantiate_cluster_config_coordinator_config_pipedrive(int include_optional);



cluster_config_coordinator_config_pipedrive_t* instantiate_cluster_config_coordinator_config_pipedrive(int include_optional) {
  cluster_config_coordinator_config_pipedrive_t* cluster_config_coordinator_config_pipedrive = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_pipedrive = cluster_config_coordinator_config_pipedrive_create(
      "0"
    );
  } else {
    cluster_config_coordinator_config_pipedrive = cluster_config_coordinator_config_pipedrive_create(
      "0"
    );
  }

  return cluster_config_coordinator_config_pipedrive;
}


#ifdef cluster_config_coordinator_config_pipedrive_MAIN

void test_cluster_config_coordinator_config_pipedrive(int include_optional) {
    cluster_config_coordinator_config_pipedrive_t* cluster_config_coordinator_config_pipedrive_1 = instantiate_cluster_config_coordinator_config_pipedrive(include_optional);

	cJSON* jsoncluster_config_coordinator_config_pipedrive_1 = cluster_config_coordinator_config_pipedrive_convertToJSON(cluster_config_coordinator_config_pipedrive_1);
	printf("cluster_config_coordinator_config_pipedrive :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_pipedrive_1));
	cluster_config_coordinator_config_pipedrive_t* cluster_config_coordinator_config_pipedrive_2 = cluster_config_coordinator_config_pipedrive_parseFromJSON(jsoncluster_config_coordinator_config_pipedrive_1);
	cJSON* jsoncluster_config_coordinator_config_pipedrive_2 = cluster_config_coordinator_config_pipedrive_convertToJSON(cluster_config_coordinator_config_pipedrive_2);
	printf("repeating cluster_config_coordinator_config_pipedrive:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_pipedrive_2));
}

int main() {
  test_cluster_config_coordinator_config_pipedrive(1);
  test_cluster_config_coordinator_config_pipedrive(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_pipedrive_MAIN
#endif // cluster_config_coordinator_config_pipedrive_TEST
