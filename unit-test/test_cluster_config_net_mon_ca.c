#ifndef cluster_config_net_mon_ca_TEST
#define cluster_config_net_mon_ca_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_net_mon_ca_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_net_mon_ca.h"
cluster_config_net_mon_ca_t* instantiate_cluster_config_net_mon_ca(int include_optional);



cluster_config_net_mon_ca_t* instantiate_cluster_config_net_mon_ca(int include_optional) {
  cluster_config_net_mon_ca_t* cluster_config_net_mon_ca = NULL;
  if (include_optional) {
    cluster_config_net_mon_ca = cluster_config_net_mon_ca_create(
      "0",
      "0",
      "0"
    );
  } else {
    cluster_config_net_mon_ca = cluster_config_net_mon_ca_create(
      "0",
      "0",
      "0"
    );
  }

  return cluster_config_net_mon_ca;
}


#ifdef cluster_config_net_mon_ca_MAIN

void test_cluster_config_net_mon_ca(int include_optional) {
    cluster_config_net_mon_ca_t* cluster_config_net_mon_ca_1 = instantiate_cluster_config_net_mon_ca(include_optional);

	cJSON* jsoncluster_config_net_mon_ca_1 = cluster_config_net_mon_ca_convertToJSON(cluster_config_net_mon_ca_1);
	printf("cluster_config_net_mon_ca :\n%s\n", cJSON_Print(jsoncluster_config_net_mon_ca_1));
	cluster_config_net_mon_ca_t* cluster_config_net_mon_ca_2 = cluster_config_net_mon_ca_parseFromJSON(jsoncluster_config_net_mon_ca_1);
	cJSON* jsoncluster_config_net_mon_ca_2 = cluster_config_net_mon_ca_convertToJSON(cluster_config_net_mon_ca_2);
	printf("repeating cluster_config_net_mon_ca:\n%s\n", cJSON_Print(jsoncluster_config_net_mon_ca_2));
}

int main() {
  test_cluster_config_net_mon_ca(1);
  test_cluster_config_net_mon_ca(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_net_mon_ca_MAIN
#endif // cluster_config_net_mon_ca_TEST
