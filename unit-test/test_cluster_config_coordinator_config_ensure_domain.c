#ifndef cluster_config_coordinator_config_ensure_domain_TEST
#define cluster_config_coordinator_config_ensure_domain_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_ensure_domain_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_ensure_domain.h"
cluster_config_coordinator_config_ensure_domain_t* instantiate_cluster_config_coordinator_config_ensure_domain(int include_optional);

#include "test_cluster_config_coordinator_config_ensure_domain_quotas.c"
#include "test_cluster_config_coordinator_config_ensure_domain_properties.c"


cluster_config_coordinator_config_ensure_domain_t* instantiate_cluster_config_coordinator_config_ensure_domain(int include_optional) {
  cluster_config_coordinator_config_ensure_domain_t* cluster_config_coordinator_config_ensure_domain = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_ensure_domain = cluster_config_coordinator_config_ensure_domain_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_ensure_domain_quotas(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config_ensure_domain_properties(0),
      "0",
      1,
      1
    );
  } else {
    cluster_config_coordinator_config_ensure_domain = cluster_config_coordinator_config_ensure_domain_create(
      "0",
      "0",
      NULL,
      NULL,
      "0",
      1,
      1
    );
  }

  return cluster_config_coordinator_config_ensure_domain;
}


#ifdef cluster_config_coordinator_config_ensure_domain_MAIN

void test_cluster_config_coordinator_config_ensure_domain(int include_optional) {
    cluster_config_coordinator_config_ensure_domain_t* cluster_config_coordinator_config_ensure_domain_1 = instantiate_cluster_config_coordinator_config_ensure_domain(include_optional);

	cJSON* jsoncluster_config_coordinator_config_ensure_domain_1 = cluster_config_coordinator_config_ensure_domain_convertToJSON(cluster_config_coordinator_config_ensure_domain_1);
	printf("cluster_config_coordinator_config_ensure_domain :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_ensure_domain_1));
	cluster_config_coordinator_config_ensure_domain_t* cluster_config_coordinator_config_ensure_domain_2 = cluster_config_coordinator_config_ensure_domain_parseFromJSON(jsoncluster_config_coordinator_config_ensure_domain_1);
	cJSON* jsoncluster_config_coordinator_config_ensure_domain_2 = cluster_config_coordinator_config_ensure_domain_convertToJSON(cluster_config_coordinator_config_ensure_domain_2);
	printf("repeating cluster_config_coordinator_config_ensure_domain:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_ensure_domain_2));
}

int main() {
  test_cluster_config_coordinator_config_ensure_domain(1);
  test_cluster_config_coordinator_config_ensure_domain(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_ensure_domain_MAIN
#endif // cluster_config_coordinator_config_ensure_domain_TEST
