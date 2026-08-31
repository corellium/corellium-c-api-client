#ifndef cluster_config_maintenance_TEST
#define cluster_config_maintenance_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_maintenance_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_maintenance.h"
cluster_config_maintenance_t* instantiate_cluster_config_maintenance(int include_optional);



cluster_config_maintenance_t* instantiate_cluster_config_maintenance(int include_optional) {
  cluster_config_maintenance_t* cluster_config_maintenance = NULL;
  if (include_optional) {
    cluster_config_maintenance = cluster_config_maintenance_create(
      "0",
      "0"
    );
  } else {
    cluster_config_maintenance = cluster_config_maintenance_create(
      "0",
      "0"
    );
  }

  return cluster_config_maintenance;
}


#ifdef cluster_config_maintenance_MAIN

void test_cluster_config_maintenance(int include_optional) {
    cluster_config_maintenance_t* cluster_config_maintenance_1 = instantiate_cluster_config_maintenance(include_optional);

	cJSON* jsoncluster_config_maintenance_1 = cluster_config_maintenance_convertToJSON(cluster_config_maintenance_1);
	printf("cluster_config_maintenance :\n%s\n", cJSON_Print(jsoncluster_config_maintenance_1));
	cluster_config_maintenance_t* cluster_config_maintenance_2 = cluster_config_maintenance_parseFromJSON(jsoncluster_config_maintenance_1);
	cJSON* jsoncluster_config_maintenance_2 = cluster_config_maintenance_convertToJSON(cluster_config_maintenance_2);
	printf("repeating cluster_config_maintenance:\n%s\n", cJSON_Print(jsoncluster_config_maintenance_2));
}

int main() {
  test_cluster_config_maintenance(1);
  test_cluster_config_maintenance(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_maintenance_MAIN
#endif // cluster_config_maintenance_TEST
