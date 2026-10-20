#ifndef cluster_config_ipsw_filters_inner_version_TEST
#define cluster_config_ipsw_filters_inner_version_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_ipsw_filters_inner_version_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_ipsw_filters_inner_version.h"
cluster_config_ipsw_filters_inner_version_t* instantiate_cluster_config_ipsw_filters_inner_version(int include_optional);



cluster_config_ipsw_filters_inner_version_t* instantiate_cluster_config_ipsw_filters_inner_version(int include_optional) {
  cluster_config_ipsw_filters_inner_version_t* cluster_config_ipsw_filters_inner_version = NULL;
  if (include_optional) {
    cluster_config_ipsw_filters_inner_version = cluster_config_ipsw_filters_inner_version_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    cluster_config_ipsw_filters_inner_version = cluster_config_ipsw_filters_inner_version_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return cluster_config_ipsw_filters_inner_version;
}


#ifdef cluster_config_ipsw_filters_inner_version_MAIN

void test_cluster_config_ipsw_filters_inner_version(int include_optional) {
    cluster_config_ipsw_filters_inner_version_t* cluster_config_ipsw_filters_inner_version_1 = instantiate_cluster_config_ipsw_filters_inner_version(include_optional);

	cJSON* jsoncluster_config_ipsw_filters_inner_version_1 = cluster_config_ipsw_filters_inner_version_convertToJSON(cluster_config_ipsw_filters_inner_version_1);
	printf("cluster_config_ipsw_filters_inner_version :\n%s\n", cJSON_Print(jsoncluster_config_ipsw_filters_inner_version_1));
	cluster_config_ipsw_filters_inner_version_t* cluster_config_ipsw_filters_inner_version_2 = cluster_config_ipsw_filters_inner_version_parseFromJSON(jsoncluster_config_ipsw_filters_inner_version_1);
	cJSON* jsoncluster_config_ipsw_filters_inner_version_2 = cluster_config_ipsw_filters_inner_version_convertToJSON(cluster_config_ipsw_filters_inner_version_2);
	printf("repeating cluster_config_ipsw_filters_inner_version:\n%s\n", cJSON_Print(jsoncluster_config_ipsw_filters_inner_version_2));
}

int main() {
  test_cluster_config_ipsw_filters_inner_version(1);
  test_cluster_config_ipsw_filters_inner_version(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_ipsw_filters_inner_version_MAIN
#endif // cluster_config_ipsw_filters_inner_version_TEST
