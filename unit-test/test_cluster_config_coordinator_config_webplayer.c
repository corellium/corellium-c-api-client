#ifndef cluster_config_coordinator_config_webplayer_TEST
#define cluster_config_coordinator_config_webplayer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_webplayer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_webplayer.h"
cluster_config_coordinator_config_webplayer_t* instantiate_cluster_config_coordinator_config_webplayer(int include_optional);



cluster_config_coordinator_config_webplayer_t* instantiate_cluster_config_coordinator_config_webplayer(int include_optional) {
  cluster_config_coordinator_config_webplayer_t* cluster_config_coordinator_config_webplayer = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_webplayer = cluster_config_coordinator_config_webplayer_create(
      1.337,
      1.337
    );
  } else {
    cluster_config_coordinator_config_webplayer = cluster_config_coordinator_config_webplayer_create(
      1.337,
      1.337
    );
  }

  return cluster_config_coordinator_config_webplayer;
}


#ifdef cluster_config_coordinator_config_webplayer_MAIN

void test_cluster_config_coordinator_config_webplayer(int include_optional) {
    cluster_config_coordinator_config_webplayer_t* cluster_config_coordinator_config_webplayer_1 = instantiate_cluster_config_coordinator_config_webplayer(include_optional);

	cJSON* jsoncluster_config_coordinator_config_webplayer_1 = cluster_config_coordinator_config_webplayer_convertToJSON(cluster_config_coordinator_config_webplayer_1);
	printf("cluster_config_coordinator_config_webplayer :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_webplayer_1));
	cluster_config_coordinator_config_webplayer_t* cluster_config_coordinator_config_webplayer_2 = cluster_config_coordinator_config_webplayer_parseFromJSON(jsoncluster_config_coordinator_config_webplayer_1);
	cJSON* jsoncluster_config_coordinator_config_webplayer_2 = cluster_config_coordinator_config_webplayer_convertToJSON(cluster_config_coordinator_config_webplayer_2);
	printf("repeating cluster_config_coordinator_config_webplayer:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_webplayer_2));
}

int main() {
  test_cluster_config_coordinator_config_webplayer(1);
  test_cluster_config_coordinator_config_webplayer(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_webplayer_MAIN
#endif // cluster_config_coordinator_config_webplayer_TEST
