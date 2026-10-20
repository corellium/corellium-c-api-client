#ifndef cluster_config_coordinator_config_auth_providers_inner_any_of_TEST
#define cluster_config_coordinator_config_auth_providers_inner_any_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_auth_providers_inner_any_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_auth_providers_inner_any_of.h"
cluster_config_coordinator_config_auth_providers_inner_any_of_t* instantiate_cluster_config_coordinator_config_auth_providers_inner_any_of(int include_optional);



cluster_config_coordinator_config_auth_providers_inner_any_of_t* instantiate_cluster_config_coordinator_config_auth_providers_inner_any_of(int include_optional) {
  cluster_config_coordinator_config_auth_providers_inner_any_of_t* cluster_config_coordinator_config_auth_providers_inner_any_of = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_auth_providers_inner_any_of = cluster_config_coordinator_config_auth_providers_inner_any_of_create(
      "0"
    );
  } else {
    cluster_config_coordinator_config_auth_providers_inner_any_of = cluster_config_coordinator_config_auth_providers_inner_any_of_create(
      "0"
    );
  }

  return cluster_config_coordinator_config_auth_providers_inner_any_of;
}


#ifdef cluster_config_coordinator_config_auth_providers_inner_any_of_MAIN

void test_cluster_config_coordinator_config_auth_providers_inner_any_of(int include_optional) {
    cluster_config_coordinator_config_auth_providers_inner_any_of_t* cluster_config_coordinator_config_auth_providers_inner_any_of_1 = instantiate_cluster_config_coordinator_config_auth_providers_inner_any_of(include_optional);

	cJSON* jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1 = cluster_config_coordinator_config_auth_providers_inner_any_of_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_any_of_1);
	printf("cluster_config_coordinator_config_auth_providers_inner_any_of :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1));
	cluster_config_coordinator_config_auth_providers_inner_any_of_t* cluster_config_coordinator_config_auth_providers_inner_any_of_2 = cluster_config_coordinator_config_auth_providers_inner_any_of_parseFromJSON(jsoncluster_config_coordinator_config_auth_providers_inner_any_of_1);
	cJSON* jsoncluster_config_coordinator_config_auth_providers_inner_any_of_2 = cluster_config_coordinator_config_auth_providers_inner_any_of_convertToJSON(cluster_config_coordinator_config_auth_providers_inner_any_of_2);
	printf("repeating cluster_config_coordinator_config_auth_providers_inner_any_of:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_auth_providers_inner_any_of_2));
}

int main() {
  test_cluster_config_coordinator_config_auth_providers_inner_any_of(1);
  test_cluster_config_coordinator_config_auth_providers_inner_any_of(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_auth_providers_inner_any_of_MAIN
#endif // cluster_config_coordinator_config_auth_providers_inner_any_of_TEST
