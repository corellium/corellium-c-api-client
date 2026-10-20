#ifndef cluster_config_package_config_flavor_filters_inner_apply_TEST
#define cluster_config_package_config_flavor_filters_inner_apply_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_package_config_flavor_filters_inner_apply_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_package_config_flavor_filters_inner_apply.h"
cluster_config_package_config_flavor_filters_inner_apply_t* instantiate_cluster_config_package_config_flavor_filters_inner_apply(int include_optional);



cluster_config_package_config_flavor_filters_inner_apply_t* instantiate_cluster_config_package_config_flavor_filters_inner_apply(int include_optional) {
  cluster_config_package_config_flavor_filters_inner_apply_t* cluster_config_package_config_flavor_filters_inner_apply = NULL;
  if (include_optional) {
    cluster_config_package_config_flavor_filters_inner_apply = cluster_config_package_config_flavor_filters_inner_apply_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    cluster_config_package_config_flavor_filters_inner_apply = cluster_config_package_config_flavor_filters_inner_apply_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return cluster_config_package_config_flavor_filters_inner_apply;
}


#ifdef cluster_config_package_config_flavor_filters_inner_apply_MAIN

void test_cluster_config_package_config_flavor_filters_inner_apply(int include_optional) {
    cluster_config_package_config_flavor_filters_inner_apply_t* cluster_config_package_config_flavor_filters_inner_apply_1 = instantiate_cluster_config_package_config_flavor_filters_inner_apply(include_optional);

	cJSON* jsoncluster_config_package_config_flavor_filters_inner_apply_1 = cluster_config_package_config_flavor_filters_inner_apply_convertToJSON(cluster_config_package_config_flavor_filters_inner_apply_1);
	printf("cluster_config_package_config_flavor_filters_inner_apply :\n%s\n", cJSON_Print(jsoncluster_config_package_config_flavor_filters_inner_apply_1));
	cluster_config_package_config_flavor_filters_inner_apply_t* cluster_config_package_config_flavor_filters_inner_apply_2 = cluster_config_package_config_flavor_filters_inner_apply_parseFromJSON(jsoncluster_config_package_config_flavor_filters_inner_apply_1);
	cJSON* jsoncluster_config_package_config_flavor_filters_inner_apply_2 = cluster_config_package_config_flavor_filters_inner_apply_convertToJSON(cluster_config_package_config_flavor_filters_inner_apply_2);
	printf("repeating cluster_config_package_config_flavor_filters_inner_apply:\n%s\n", cJSON_Print(jsoncluster_config_package_config_flavor_filters_inner_apply_2));
}

int main() {
  test_cluster_config_package_config_flavor_filters_inner_apply(1);
  test_cluster_config_package_config_flavor_filters_inner_apply(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_package_config_flavor_filters_inner_apply_MAIN
#endif // cluster_config_package_config_flavor_filters_inner_apply_TEST
