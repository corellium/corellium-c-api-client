#ifndef cluster_configuration_payload_TEST
#define cluster_configuration_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_configuration_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_configuration_payload.h"
cluster_configuration_payload_t* instantiate_cluster_configuration_payload(int include_optional);

#include "test_coordinator_config_v1.c"
#include "test_ai_tools_config_v1.c"


cluster_configuration_payload_t* instantiate_cluster_configuration_payload(int include_optional) {
  cluster_configuration_payload_t* cluster_configuration_payload = NULL;
  if (include_optional) {
    cluster_configuration_payload = cluster_configuration_payload_create(
      1.337,
       // false, not to have infinite recursion
      instantiate_coordinator_config_v1(0),
       // false, not to have infinite recursion
      instantiate_ai_tools_config_v1(0)
    );
  } else {
    cluster_configuration_payload = cluster_configuration_payload_create(
      1.337,
      NULL,
      NULL
    );
  }

  return cluster_configuration_payload;
}


#ifdef cluster_configuration_payload_MAIN

void test_cluster_configuration_payload(int include_optional) {
    cluster_configuration_payload_t* cluster_configuration_payload_1 = instantiate_cluster_configuration_payload(include_optional);

	cJSON* jsoncluster_configuration_payload_1 = cluster_configuration_payload_convertToJSON(cluster_configuration_payload_1);
	printf("cluster_configuration_payload :\n%s\n", cJSON_Print(jsoncluster_configuration_payload_1));
	cluster_configuration_payload_t* cluster_configuration_payload_2 = cluster_configuration_payload_parseFromJSON(jsoncluster_configuration_payload_1);
	cJSON* jsoncluster_configuration_payload_2 = cluster_configuration_payload_convertToJSON(cluster_configuration_payload_2);
	printf("repeating cluster_configuration_payload:\n%s\n", cJSON_Print(jsoncluster_configuration_payload_2));
}

int main() {
  test_cluster_configuration_payload(1);
  test_cluster_configuration_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_configuration_payload_MAIN
#endif // cluster_configuration_payload_TEST
