#ifndef cluster_config_ai_tools_config_TEST
#define cluster_config_ai_tools_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_ai_tools_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_ai_tools_config.h"
cluster_config_ai_tools_config_t* instantiate_cluster_config_ai_tools_config(int include_optional);



cluster_config_ai_tools_config_t* instantiate_cluster_config_ai_tools_config(int include_optional) {
  cluster_config_ai_tools_config_t* cluster_config_ai_tools_config = NULL;
  if (include_optional) {
    cluster_config_ai_tools_config = cluster_config_ai_tools_config_create(
      1
    );
  } else {
    cluster_config_ai_tools_config = cluster_config_ai_tools_config_create(
      1
    );
  }

  return cluster_config_ai_tools_config;
}


#ifdef cluster_config_ai_tools_config_MAIN

void test_cluster_config_ai_tools_config(int include_optional) {
    cluster_config_ai_tools_config_t* cluster_config_ai_tools_config_1 = instantiate_cluster_config_ai_tools_config(include_optional);

	cJSON* jsoncluster_config_ai_tools_config_1 = cluster_config_ai_tools_config_convertToJSON(cluster_config_ai_tools_config_1);
	printf("cluster_config_ai_tools_config :\n%s\n", cJSON_Print(jsoncluster_config_ai_tools_config_1));
	cluster_config_ai_tools_config_t* cluster_config_ai_tools_config_2 = cluster_config_ai_tools_config_parseFromJSON(jsoncluster_config_ai_tools_config_1);
	cJSON* jsoncluster_config_ai_tools_config_2 = cluster_config_ai_tools_config_convertToJSON(cluster_config_ai_tools_config_2);
	printf("repeating cluster_config_ai_tools_config:\n%s\n", cJSON_Print(jsoncluster_config_ai_tools_config_2));
}

int main() {
  test_cluster_config_ai_tools_config(1);
  test_cluster_config_ai_tools_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_ai_tools_config_MAIN
#endif // cluster_config_ai_tools_config_TEST
