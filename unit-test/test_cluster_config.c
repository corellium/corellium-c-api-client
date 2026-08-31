#ifndef cluster_config_TEST
#define cluster_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config.h"
cluster_config_t* instantiate_cluster_config(int include_optional);

#include "test_cluster_config_stripe.c"
#include "test_cluster_config_maintenance.c"
#include "test_cluster_config_net_mon_ca.c"
#include "test_cluster_config_coordinator_config.c"
#include "test_cluster_config_setup_config.c"
#include "test_cluster_config_node_specific_config.c"
#include "test_cluster_config_package_config.c"
#include "test_cluster_config_firmware_service_config.c"


cluster_config_t* instantiate_cluster_config(int include_optional) {
  cluster_config_t* cluster_config = NULL;
  if (include_optional) {
    cluster_config = cluster_config_create(
      list_createList(),
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      1,
      "0",
      list_createList(),
      corellium_api_cluster_config_NETWORKTYPE_bridged,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_cluster_config_stripe(0),
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_cluster_config_maintenance(0),
      "0",
      1,
      "0",
      "0",
      1,
       // false, not to have infinite recursion
      instantiate_cluster_config_net_mon_ca(0),
      56,
      1.337,
      1.337,
      1,
      "0",
      1,
      1,
      "0",
      "0",
      1,
      0,
      "0",
      "0",
      "0",
      1,
      1.337,
      1.337,
       // false, not to have infinite recursion
      instantiate_cluster_config_coordinator_config(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_setup_config(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_node_specific_config(0),
       // false, not to have infinite recursion
      instantiate_cluster_config_package_config(0),
      1.337,
      1,
      1,
      list_createList(),
      "0",
      "0",
      "0",
      1,
      1,
      list_createList(),
      "0",
      "0",
      "0",
      1.337,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_cluster_config_firmware_service_config(0)
    );
  } else {
    cluster_config = cluster_config_create(
      list_createList(),
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      1,
      "0",
      list_createList(),
      corellium_api_cluster_config_NETWORKTYPE_bridged,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1,
      NULL,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      NULL,
      "0",
      1,
      "0",
      "0",
      1,
      NULL,
      56,
      1.337,
      1.337,
      1,
      "0",
      1,
      1,
      "0",
      "0",
      1,
      0,
      "0",
      "0",
      "0",
      1,
      1.337,
      1.337,
      NULL,
      NULL,
      NULL,
      NULL,
      1.337,
      1,
      1,
      list_createList(),
      "0",
      "0",
      "0",
      1,
      1,
      list_createList(),
      "0",
      "0",
      "0",
      1.337,
      list_createList(),
      NULL
    );
  }

  return cluster_config;
}


#ifdef cluster_config_MAIN

void test_cluster_config(int include_optional) {
    cluster_config_t* cluster_config_1 = instantiate_cluster_config(include_optional);

	cJSON* jsoncluster_config_1 = cluster_config_convertToJSON(cluster_config_1);
	printf("cluster_config :\n%s\n", cJSON_Print(jsoncluster_config_1));
	cluster_config_t* cluster_config_2 = cluster_config_parseFromJSON(jsoncluster_config_1);
	cJSON* jsoncluster_config_2 = cluster_config_convertToJSON(cluster_config_2);
	printf("repeating cluster_config:\n%s\n", cJSON_Print(jsoncluster_config_2));
}

int main() {
  test_cluster_config(1);
  test_cluster_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_MAIN
#endif // cluster_config_TEST
