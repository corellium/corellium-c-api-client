#ifndef patch_cluster_config_body_TEST
#define patch_cluster_config_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_cluster_config_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_cluster_config_body.h"
patch_cluster_config_body_t* instantiate_patch_cluster_config_body(int include_optional);

#include "test_coordinator_config.c"
#include "test_patch_cluster_config_body_ai_tools_config.c"


patch_cluster_config_body_t* instantiate_patch_cluster_config_body(int include_optional) {
  patch_cluster_config_body_t* patch_cluster_config_body = NULL;
  if (include_optional) {
    patch_cluster_config_body = patch_cluster_config_body_create(
      10,
       // false, not to have infinite recursion
      instantiate_coordinator_config(0),
      null,
      "10.0.0.12"
    );
  } else {
    patch_cluster_config_body = patch_cluster_config_body_create(
      10,
      NULL,
      null,
      "10.0.0.12"
    );
  }

  return patch_cluster_config_body;
}


#ifdef patch_cluster_config_body_MAIN

void test_patch_cluster_config_body(int include_optional) {
    patch_cluster_config_body_t* patch_cluster_config_body_1 = instantiate_patch_cluster_config_body(include_optional);

	cJSON* jsonpatch_cluster_config_body_1 = patch_cluster_config_body_convertToJSON(patch_cluster_config_body_1);
	printf("patch_cluster_config_body :\n%s\n", cJSON_Print(jsonpatch_cluster_config_body_1));
	patch_cluster_config_body_t* patch_cluster_config_body_2 = patch_cluster_config_body_parseFromJSON(jsonpatch_cluster_config_body_1);
	cJSON* jsonpatch_cluster_config_body_2 = patch_cluster_config_body_convertToJSON(patch_cluster_config_body_2);
	printf("repeating patch_cluster_config_body:\n%s\n", cJSON_Print(jsonpatch_cluster_config_body_2));
}

int main() {
  test_patch_cluster_config_body(1);
  test_patch_cluster_config_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_cluster_config_body_MAIN
#endif // patch_cluster_config_body_TEST
