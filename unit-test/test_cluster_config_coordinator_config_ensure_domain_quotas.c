#ifndef cluster_config_coordinator_config_ensure_domain_quotas_TEST
#define cluster_config_coordinator_config_ensure_domain_quotas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_ensure_domain_quotas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_ensure_domain_quotas.h"
cluster_config_coordinator_config_ensure_domain_quotas_t* instantiate_cluster_config_coordinator_config_ensure_domain_quotas(int include_optional);



cluster_config_coordinator_config_ensure_domain_quotas_t* instantiate_cluster_config_coordinator_config_ensure_domain_quotas(int include_optional) {
  cluster_config_coordinator_config_ensure_domain_quotas_t* cluster_config_coordinator_config_ensure_domain_quotas = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_ensure_domain_quotas = cluster_config_coordinator_config_ensure_domain_quotas_create(
      1.337
    );
  } else {
    cluster_config_coordinator_config_ensure_domain_quotas = cluster_config_coordinator_config_ensure_domain_quotas_create(
      1.337
    );
  }

  return cluster_config_coordinator_config_ensure_domain_quotas;
}


#ifdef cluster_config_coordinator_config_ensure_domain_quotas_MAIN

void test_cluster_config_coordinator_config_ensure_domain_quotas(int include_optional) {
    cluster_config_coordinator_config_ensure_domain_quotas_t* cluster_config_coordinator_config_ensure_domain_quotas_1 = instantiate_cluster_config_coordinator_config_ensure_domain_quotas(include_optional);

	cJSON* jsoncluster_config_coordinator_config_ensure_domain_quotas_1 = cluster_config_coordinator_config_ensure_domain_quotas_convertToJSON(cluster_config_coordinator_config_ensure_domain_quotas_1);
	printf("cluster_config_coordinator_config_ensure_domain_quotas :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_ensure_domain_quotas_1));
	cluster_config_coordinator_config_ensure_domain_quotas_t* cluster_config_coordinator_config_ensure_domain_quotas_2 = cluster_config_coordinator_config_ensure_domain_quotas_parseFromJSON(jsoncluster_config_coordinator_config_ensure_domain_quotas_1);
	cJSON* jsoncluster_config_coordinator_config_ensure_domain_quotas_2 = cluster_config_coordinator_config_ensure_domain_quotas_convertToJSON(cluster_config_coordinator_config_ensure_domain_quotas_2);
	printf("repeating cluster_config_coordinator_config_ensure_domain_quotas:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_ensure_domain_quotas_2));
}

int main() {
  test_cluster_config_coordinator_config_ensure_domain_quotas(1);
  test_cluster_config_coordinator_config_ensure_domain_quotas(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_ensure_domain_quotas_MAIN
#endif // cluster_config_coordinator_config_ensure_domain_quotas_TEST
