#ifndef cluster_config_coordinator_config_auth_providers_inner_any_of_1_TEST
#define cluster_config_coordinator_config_auth_providers_inner_any_of_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_auth_providers_inner_any_of_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_auth_providers_inner_any_of_1.h"
cluster_config_coordinator_config_auth_providers_inner_any_of_1_t* instantiate_cluster_config_coordinator_config_auth_providers_inner_any_of_1(int include_optional);



cluster_config_coordinator_config_auth_providers_inner_any_of_1_t* instantiate_cluster_config_coordinator_config_auth_providers_inner_any_of_1(int include_optional) {
  cluster_config_coordinator_config_auth_providers_inner_any_of_1_t* cluster_config_coordinator_config_auth_providers_inner_any_of_1 = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_auth_providers_inner_any_of_1 = cluster_config_coordinator_config_auth_providers_inner_any_of_1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    cluster_config_coordinator_config_auth_providers_inner_any_of_1 = cluster_config_coordinator_config_auth_providers_inner_any_of_1_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  }

  return cluster_config_coordinator_config_auth_providers_inner_any_of_1;
}


#ifdef cluster_config_coordinator_config_auth_providers_inner_any_of_1_MAIN

void test_cluster_config_coordinator_config_auth_providers_inner_any_of_1(int include_optional) {
    cluster_config_coordinator_config_auth_providers_inner_any_of_1_t* cluster_config_coordinator_config_auth_providers_inner_any_of_1_1 = instantiate_cluster_config_coordinator_config_auth_providers_inner_any_of_1(include_optional);

	cJSON* jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1_1 = cluster_config_coordinator_config_auth_providers_inner_any_of_1_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_any_of_1_1);
	printf("cluster_config_coordinator_config_auth_providers_inner_any_of_1 :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1_1));
	cluster_config_coordinator_config_auth_providers_inner_any_of_1_t* cluster_config_coordinator_config_auth_providers_inner_any_of_1_2 = cluster_config_coordinator_config_auth_providers_inner_any_of_1_parseFromJSON(jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1_1);
	cJSON* jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1_2 = cluster_config_coordinator_config_auth_providers_inner_any_of_1_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_any_of_1_2);
	printf("repeating cluster_config_coordinator_config_auth_providers_inner_any_of_1:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1_2));
}

int main() {
  test_cluster_config_coordinator_config_auth_providers_inner_any_of_1(1);
  test_cluster_config_coordinator_config_auth_providers_inner_any_of_1(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_auth_providers_inner_any_of_1_MAIN
#endif // cluster_config_coordinator_config_auth_providers_inner_any_of_1_TEST
