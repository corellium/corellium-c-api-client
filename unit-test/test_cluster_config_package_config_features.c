#ifndef cluster_config_package_config_features_TEST
#define cluster_config_package_config_features_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_package_config_features_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_package_config_features.h"
cluster_config_package_config_features_t* instantiate_cluster_config_package_config_features(int include_optional);



cluster_config_package_config_features_t* instantiate_cluster_config_package_config_features(int include_optional) {
  cluster_config_package_config_features_t* cluster_config_package_config_features = NULL;
  if (include_optional) {
    cluster_config_package_config_features = cluster_config_package_config_features_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    cluster_config_package_config_features = cluster_config_package_config_features_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return cluster_config_package_config_features;
}


#ifdef cluster_config_package_config_features_MAIN

void test_cluster_config_package_config_features(int include_optional) {
    cluster_config_package_config_features_t* cluster_config_package_config_features_1 = instantiate_cluster_config_package_config_features(include_optional);

	cJSON* jsoncluster_config_package_config_features_1 = cluster_config_package_config_features_convertToJSON(cluster_config_package_config_features_1);
	printf("cluster_config_package_config_features :\n%s\n", cJSON_Print(jsoncluster_config_package_config_features_1));
	cluster_config_package_config_features_t* cluster_config_package_config_features_2 = cluster_config_package_config_features_parseFromJSON(jsoncluster_config_package_config_features_1);
	cJSON* jsoncluster_config_package_config_features_2 = cluster_config_package_config_features_convertToJSON(cluster_config_package_config_features_2);
	printf("repeating cluster_config_package_config_features:\n%s\n", cJSON_Print(jsoncluster_config_package_config_features_2));
}

int main() {
  test_cluster_config_package_config_features(1);
  test_cluster_config_package_config_features(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_package_config_features_MAIN
#endif // cluster_config_package_config_features_TEST
