#ifndef cluster_config_coordinator_config_aws_marketplace_TEST
#define cluster_config_coordinator_config_aws_marketplace_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_aws_marketplace_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_aws_marketplace.h"
cluster_config_coordinator_config_aws_marketplace_t* instantiate_cluster_config_coordinator_config_aws_marketplace(int include_optional);



cluster_config_coordinator_config_aws_marketplace_t* instantiate_cluster_config_coordinator_config_aws_marketplace(int include_optional) {
  cluster_config_coordinator_config_aws_marketplace_t* cluster_config_coordinator_config_aws_marketplace = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_aws_marketplace = cluster_config_coordinator_config_aws_marketplace_create(
      "0",
      "0",
      "0",
      0
    );
  } else {
    cluster_config_coordinator_config_aws_marketplace = cluster_config_coordinator_config_aws_marketplace_create(
      "0",
      "0",
      "0",
      0
    );
  }

  return cluster_config_coordinator_config_aws_marketplace;
}


#ifdef cluster_config_coordinator_config_aws_marketplace_MAIN

void test_cluster_config_coordinator_config_aws_marketplace(int include_optional) {
    cluster_config_coordinator_config_aws_marketplace_t* cluster_config_coordinator_config_aws_marketplace_1 = instantiate_cluster_config_coordinator_config_aws_marketplace(include_optional);

	cJSON* jsoncluster_config_coordinator_config_aws_marketplace_1 = cluster_config_coordinator_config_aws_marketplace_convertToJSON(cluster_config_coordinator_config_aws_marketplace_1);
	printf("cluster_config_coordinator_config_aws_marketplace :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_aws_marketplace_1));
	cluster_config_coordinator_config_aws_marketplace_t* cluster_config_coordinator_config_aws_marketplace_2 = cluster_config_coordinator_config_aws_marketplace_parseFromJSON(jsoncluster_config_coordinator_config_aws_marketplace_1);
	cJSON* jsoncluster_config_coordinator_config_aws_marketplace_2 = cluster_config_coordinator_config_aws_marketplace_convertToJSON(cluster_config_coordinator_config_aws_marketplace_2);
	printf("repeating cluster_config_coordinator_config_aws_marketplace:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_aws_marketplace_2));
}

int main() {
  test_cluster_config_coordinator_config_aws_marketplace(1);
  test_cluster_config_coordinator_config_aws_marketplace(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_aws_marketplace_MAIN
#endif // cluster_config_coordinator_config_aws_marketplace_TEST
