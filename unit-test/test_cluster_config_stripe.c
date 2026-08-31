#ifndef cluster_config_stripe_TEST
#define cluster_config_stripe_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_stripe_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_stripe.h"
cluster_config_stripe_t* instantiate_cluster_config_stripe(int include_optional);



cluster_config_stripe_t* instantiate_cluster_config_stripe(int include_optional) {
  cluster_config_stripe_t* cluster_config_stripe = NULL;
  if (include_optional) {
    cluster_config_stripe = cluster_config_stripe_create(
      "0",
      "0",
      "0"
    );
  } else {
    cluster_config_stripe = cluster_config_stripe_create(
      "0",
      "0",
      "0"
    );
  }

  return cluster_config_stripe;
}


#ifdef cluster_config_stripe_MAIN

void test_cluster_config_stripe(int include_optional) {
    cluster_config_stripe_t* cluster_config_stripe_1 = instantiate_cluster_config_stripe(include_optional);

	cJSON* jsoncluster_config_stripe_1 = cluster_config_stripe_convertToJSON(cluster_config_stripe_1);
	printf("cluster_config_stripe :\n%s\n", cJSON_Print(jsoncluster_config_stripe_1));
	cluster_config_stripe_t* cluster_config_stripe_2 = cluster_config_stripe_parseFromJSON(jsoncluster_config_stripe_1);
	cJSON* jsoncluster_config_stripe_2 = cluster_config_stripe_convertToJSON(cluster_config_stripe_2);
	printf("repeating cluster_config_stripe:\n%s\n", cJSON_Print(jsoncluster_config_stripe_2));
}

int main() {
  test_cluster_config_stripe(1);
  test_cluster_config_stripe(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_stripe_MAIN
#endif // cluster_config_stripe_TEST
