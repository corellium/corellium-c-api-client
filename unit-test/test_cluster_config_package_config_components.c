#ifndef cluster_config_package_config_components_TEST
#define cluster_config_package_config_components_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_package_config_components_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_package_config_components.h"
cluster_config_package_config_components_t* instantiate_cluster_config_package_config_components(int include_optional);



cluster_config_package_config_components_t* instantiate_cluster_config_package_config_components(int include_optional) {
  cluster_config_package_config_components_t* cluster_config_package_config_components = NULL;
  if (include_optional) {
    cluster_config_package_config_components = cluster_config_package_config_components_create(
      1
    );
  } else {
    cluster_config_package_config_components = cluster_config_package_config_components_create(
      1
    );
  }

  return cluster_config_package_config_components;
}


#ifdef cluster_config_package_config_components_MAIN

void test_cluster_config_package_config_components(int include_optional) {
    cluster_config_package_config_components_t* cluster_config_package_config_components_1 = instantiate_cluster_config_package_config_components(include_optional);

	cJSON* jsoncluster_config_package_config_components_1 = cluster_config_package_config_components_convertToJSON(cluster_config_package_config_components_1);
	printf("cluster_config_package_config_components :\n%s\n", cJSON_Print(jsoncluster_config_package_config_components_1));
	cluster_config_package_config_components_t* cluster_config_package_config_components_2 = cluster_config_package_config_components_parseFromJSON(jsoncluster_config_package_config_components_1);
	cJSON* jsoncluster_config_package_config_components_2 = cluster_config_package_config_components_convertToJSON(cluster_config_package_config_components_2);
	printf("repeating cluster_config_package_config_components:\n%s\n", cJSON_Print(jsoncluster_config_package_config_components_2));
}

int main() {
  test_cluster_config_package_config_components(1);
  test_cluster_config_package_config_components(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_package_config_components_MAIN
#endif // cluster_config_package_config_components_TEST
