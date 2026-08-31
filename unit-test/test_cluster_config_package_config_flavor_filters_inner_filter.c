#ifndef cluster_config_package_config_flavor_filters_inner_filter_TEST
#define cluster_config_package_config_flavor_filters_inner_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_package_config_flavor_filters_inner_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_package_config_flavor_filters_inner_filter.h"
cluster_config_package_config_flavor_filters_inner_filter_t* instantiate_cluster_config_package_config_flavor_filters_inner_filter(int include_optional);



cluster_config_package_config_flavor_filters_inner_filter_t* instantiate_cluster_config_package_config_flavor_filters_inner_filter(int include_optional) {
  cluster_config_package_config_flavor_filters_inner_filter_t* cluster_config_package_config_flavor_filters_inner_filter = NULL;
  if (include_optional) {
    cluster_config_package_config_flavor_filters_inner_filter = cluster_config_package_config_flavor_filters_inner_filter_create(
      "0",
      "0"
    );
  } else {
    cluster_config_package_config_flavor_filters_inner_filter = cluster_config_package_config_flavor_filters_inner_filter_create(
      "0",
      "0"
    );
  }

  return cluster_config_package_config_flavor_filters_inner_filter;
}


#ifdef cluster_config_package_config_flavor_filters_inner_filter_MAIN

void test_cluster_config_package_config_flavor_filters_inner_filter(int include_optional) {
    cluster_config_package_config_flavor_filters_inner_filter_t* cluster_config_package_config_flavor_filters_inner_filter_1 = instantiate_cluster_config_package_config_flavor_filters_inner_filter(include_optional);

	cJSON* jsoncluster_config_package_config_flavor_filters_inner_filter_1 = cluster_config_package_config_flavor_filters_inner_filter_convertToJSON(cluster_config_package_config_flavor_filters_inner_filter_1);
	printf("cluster_config_package_config_flavor_filters_inner_filter :\n%s\n", cJSON_Print(jsoncluster_config_package_config_flavor_filters_inner_filter_1));
	cluster_config_package_config_flavor_filters_inner_filter_t* cluster_config_package_config_flavor_filters_inner_filter_2 = cluster_config_package_config_flavor_filters_inner_filter_parseFromJSON(jsoncluster_config_package_config_flavor_filters_inner_filter_1);
	cJSON* jsoncluster_config_package_config_flavor_filters_inner_filter_2 = cluster_config_package_config_flavor_filters_inner_filter_convertToJSON(cluster_config_package_config_flavor_filters_inner_filter_2);
	printf("repeating cluster_config_package_config_flavor_filters_inner_filter:\n%s\n", cJSON_Print(jsoncluster_config_package_config_flavor_filters_inner_filter_2));
}

int main() {
  test_cluster_config_package_config_flavor_filters_inner_filter(1);
  test_cluster_config_package_config_flavor_filters_inner_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_package_config_flavor_filters_inner_filter_MAIN
#endif // cluster_config_package_config_flavor_filters_inner_filter_TEST
