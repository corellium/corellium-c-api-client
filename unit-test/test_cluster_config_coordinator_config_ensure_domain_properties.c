#ifndef cluster_config_coordinator_config_ensure_domain_properties_TEST
#define cluster_config_coordinator_config_ensure_domain_properties_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_ensure_domain_properties_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_ensure_domain_properties.h"
cluster_config_coordinator_config_ensure_domain_properties_t* instantiate_cluster_config_coordinator_config_ensure_domain_properties(int include_optional);



cluster_config_coordinator_config_ensure_domain_properties_t* instantiate_cluster_config_coordinator_config_ensure_domain_properties(int include_optional) {
  cluster_config_coordinator_config_ensure_domain_properties_t* cluster_config_coordinator_config_ensure_domain_properties = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_ensure_domain_properties = cluster_config_coordinator_config_ensure_domain_properties_create(
      "0",
      1,
      1
    );
  } else {
    cluster_config_coordinator_config_ensure_domain_properties = cluster_config_coordinator_config_ensure_domain_properties_create(
      "0",
      1,
      1
    );
  }

  return cluster_config_coordinator_config_ensure_domain_properties;
}


#ifdef cluster_config_coordinator_config_ensure_domain_properties_MAIN

void test_cluster_config_coordinator_config_ensure_domain_properties(int include_optional) {
    cluster_config_coordinator_config_ensure_domain_properties_t* cluster_config_coordinator_config_ensure_domain_properties_1 = instantiate_cluster_config_coordinator_config_ensure_domain_properties(include_optional);

	cJSON* jsoncluster_config_coordinator_config_ensure_domain_properties_1 = cluster_config_coordinator_config_ensure_domain_properties_convertToJSON(cluster_config_coordinator_config_ensure_domain_properties_1);
	printf("cluster_config_coordinator_config_ensure_domain_properties :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_ensure_domain_properties_1));
	cluster_config_coordinator_config_ensure_domain_properties_t* cluster_config_coordinator_config_ensure_domain_properties_2 = cluster_config_coordinator_config_ensure_domain_properties_parseFromJSON(jsoncluster_config_coordinator_config_ensure_domain_properties_1);
	cJSON* jsoncluster_config_coordinator_config_ensure_domain_properties_2 = cluster_config_coordinator_config_ensure_domain_properties_convertToJSON(cluster_config_coordinator_config_ensure_domain_properties_2);
	printf("repeating cluster_config_coordinator_config_ensure_domain_properties:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_ensure_domain_properties_2));
}

int main() {
  test_cluster_config_coordinator_config_ensure_domain_properties(1);
  test_cluster_config_coordinator_config_ensure_domain_properties(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_ensure_domain_properties_MAIN
#endif // cluster_config_coordinator_config_ensure_domain_properties_TEST
