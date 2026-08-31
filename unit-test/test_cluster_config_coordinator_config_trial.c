#ifndef cluster_config_coordinator_config_trial_TEST
#define cluster_config_coordinator_config_trial_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_coordinator_config_trial_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_coordinator_config_trial.h"
cluster_config_coordinator_config_trial_t* instantiate_cluster_config_coordinator_config_trial(int include_optional);



cluster_config_coordinator_config_trial_t* instantiate_cluster_config_coordinator_config_trial(int include_optional) {
  cluster_config_coordinator_config_trial_t* cluster_config_coordinator_config_trial = NULL;
  if (include_optional) {
    cluster_config_coordinator_config_trial = cluster_config_coordinator_config_trial_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    cluster_config_coordinator_config_trial = cluster_config_coordinator_config_trial_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return cluster_config_coordinator_config_trial;
}


#ifdef cluster_config_coordinator_config_trial_MAIN

void test_cluster_config_coordinator_config_trial(int include_optional) {
    cluster_config_coordinator_config_trial_t* cluster_config_coordinator_config_trial_1 = instantiate_cluster_config_coordinator_config_trial(include_optional);

	cJSON* jsoncluster_config_coordinator_config_trial_1 = cluster_config_coordinator_config_trial_convertToJSON(cluster_config_coordinator_config_trial_1);
	printf("cluster_config_coordinator_config_trial :\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_trial_1));
	cluster_config_coordinator_config_trial_t* cluster_config_coordinator_config_trial_2 = cluster_config_coordinator_config_trial_parseFromJSON(jsoncluster_config_coordinator_config_trial_1);
	cJSON* jsoncluster_config_coordinator_config_trial_2 = cluster_config_coordinator_config_trial_convertToJSON(cluster_config_coordinator_config_trial_2);
	printf("repeating cluster_config_coordinator_config_trial:\n%s\n", cJSON_Print(jsoncluster_config_coordinator_config_trial_2));
}

int main() {
  test_cluster_config_coordinator_config_trial(1);
  test_cluster_config_coordinator_config_trial(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_coordinator_config_trial_MAIN
#endif // cluster_config_coordinator_config_trial_TEST
