#ifndef cluster_config_ipsw_filters_inner_device_TEST
#define cluster_config_ipsw_filters_inner_device_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_ipsw_filters_inner_device_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_ipsw_filters_inner_device.h"
cluster_config_ipsw_filters_inner_device_t* instantiate_cluster_config_ipsw_filters_inner_device(int include_optional);



cluster_config_ipsw_filters_inner_device_t* instantiate_cluster_config_ipsw_filters_inner_device(int include_optional) {
  cluster_config_ipsw_filters_inner_device_t* cluster_config_ipsw_filters_inner_device = NULL;
  if (include_optional) {
    cluster_config_ipsw_filters_inner_device = cluster_config_ipsw_filters_inner_device_create(
      "0"
    );
  } else {
    cluster_config_ipsw_filters_inner_device = cluster_config_ipsw_filters_inner_device_create(
      "0"
    );
  }

  return cluster_config_ipsw_filters_inner_device;
}


#ifdef cluster_config_ipsw_filters_inner_device_MAIN

void test_cluster_config_ipsw_filters_inner_device(int include_optional) {
    cluster_config_ipsw_filters_inner_device_t* cluster_config_ipsw_filters_inner_device_1 = instantiate_cluster_config_ipsw_filters_inner_device(include_optional);

	cJSON* jsoncluster_config_ipsw_filters_inner_device_1 = cluster_config_ipsw_filters_inner_device_convertToJSON(cluster_config_ipsw_filters_inner_device_1);
	printf("cluster_config_ipsw_filters_inner_device :\n%s\n", cJSON_Print(jsoncluster_config_ipsw_filters_inner_device_1));
	cluster_config_ipsw_filters_inner_device_t* cluster_config_ipsw_filters_inner_device_2 = cluster_config_ipsw_filters_inner_device_parseFromJSON(jsoncluster_config_ipsw_filters_inner_device_1);
	cJSON* jsoncluster_config_ipsw_filters_inner_device_2 = cluster_config_ipsw_filters_inner_device_convertToJSON(cluster_config_ipsw_filters_inner_device_2);
	printf("repeating cluster_config_ipsw_filters_inner_device:\n%s\n", cJSON_Print(jsoncluster_config_ipsw_filters_inner_device_2));
}

int main() {
  test_cluster_config_ipsw_filters_inner_device(1);
  test_cluster_config_ipsw_filters_inner_device(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_ipsw_filters_inner_device_MAIN
#endif // cluster_config_ipsw_filters_inner_device_TEST
