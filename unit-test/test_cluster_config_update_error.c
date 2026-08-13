#ifndef cluster_config_update_error_TEST
#define cluster_config_update_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cluster_config_update_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cluster_config_update_error.h"
cluster_config_update_error_t* instantiate_cluster_config_update_error(int include_optional);



cluster_config_update_error_t* instantiate_cluster_config_update_error(int include_optional) {
  cluster_config_update_error_t* cluster_config_update_error = NULL;
  if (include_optional) {
    cluster_config_update_error = cluster_config_update_error_create(
      "0",
      list_createList()
    );
  } else {
    cluster_config_update_error = cluster_config_update_error_create(
      "0",
      list_createList()
    );
  }

  return cluster_config_update_error;
}


#ifdef cluster_config_update_error_MAIN

void test_cluster_config_update_error(int include_optional) {
    cluster_config_update_error_t* cluster_config_update_error_1 = instantiate_cluster_config_update_error(include_optional);

	cJSON* jsoncluster_config_update_error_1 = cluster_config_update_error_convertToJSON(cluster_config_update_error_1);
	printf("cluster_config_update_error :\n%s\n", cJSON_Print(jsoncluster_config_update_error_1));
	cluster_config_update_error_t* cluster_config_update_error_2 = cluster_config_update_error_parseFromJSON(jsoncluster_config_update_error_1);
	cJSON* jsoncluster_config_update_error_2 = cluster_config_update_error_convertToJSON(cluster_config_update_error_2);
	printf("repeating cluster_config_update_error:\n%s\n", cJSON_Print(jsoncluster_config_update_error_2));
}

int main() {
  test_cluster_config_update_error(1);
  test_cluster_config_update_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // cluster_config_update_error_MAIN
#endif // cluster_config_update_error_TEST
