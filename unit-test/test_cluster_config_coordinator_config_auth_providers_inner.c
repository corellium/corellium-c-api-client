#ifndef cluster_config_coordinator_config_auth_providers_inner_TEST
#define cluster_config_coordinator_config_auth_providers_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_auth_providers_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_auth_providers_inner.h"
cluster_config_coordinator_config_auth_providers_inner_t* instantiate_cluster_config_coordinator_config_auth_providers_inner(int include_optional);



cluster_config_coordinator_config_auth_providers_inner_t* instantiate_cluster_config_coordinator_config_auth_providers_inner(int include_optional) {
  cluster_config_coordinator_config_auth_providers_inner_t* cluster_config_coordinator_config_auth_providers_inner = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_auth_providers_inner = cluster_config_coordinator_config_auth_providers_inner_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    cluster_config_coordinator_config_auth_providers_inner = cluster_config_coordinator_config_auth_providers_inner_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  }

  return cluster_config_coordinator_config_auth_providers_inner;
}


#ifdef cluster_config_coordinator_config_auth_providers_inner_MAIN

void test_cluster_config_coordinator_config_auth_providers_inner(int include_optional) {
    cluster_config_coordinator_config_auth_providers_inner_t* cluster_config_coordinator_config_auth_providers_inner_1 = instantiate_cluster_config_coordinator_config_auth_providers_inner(include_optional);

	cJSON* jsoncluster_config_coordinator_config_auth_providers_inner_1 = cluster_config_coordinator_config_auth_providers_inner_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_1);
	printf("cluster_config_coordinator_config_auth_providers_inner :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_auth_providers_inner_1));
	cluster_config_coordinator_config_auth_providers_inner_t* cluster_config_coordinator_config_auth_providers_inner_2 = cluster_config_coordinator_config_auth_providers_inner_parseFromJSON(jsoncluster_config_coordinator_config_auth_providers_inner_1);
	cJSON* jsoncluster_config_coordinator_config_auth_providers_inner_2 = cluster_config_coordinator_config_auth_providers_inner_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_2);
	printf("repeating cluster_config_coordinator_config_auth_providers_inner:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_auth_providers_inner_2));
}

int main() {
  test_cluster_config_coordinator_config_auth_providers_inner(1);
  test_cluster_config_coordinator_config_auth_providers_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_auth_providers_inner_MAIN
#endif // cluster_config_coordinator_config_auth_providers_inner_TEST
