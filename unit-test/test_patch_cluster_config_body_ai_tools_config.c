#ifndef patch_cluster_config_body_ai_tools_config_TEST
#define patch_cluster_config_body_ai_tools_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_cluster_config_body_ai_tools_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_cluster_config_body_ai_tools_config.h"
patch_cluster_config_body_ai_tools_config_t* instantiate_patch_cluster_config_body_ai_tools_config(int include_optional);



patch_cluster_config_body_ai_tools_config_t* instantiate_patch_cluster_config_body_ai_tools_config(int include_optional) {
  patch_cluster_config_body_ai_tools_config_t* patch_cluster_config_body_ai_tools_config = NULL;
  if (include_optional) {
    patch_cluster_config_body_ai_tools_config = patch_cluster_config_body_ai_tools_config_create(
      true
    );
  } else {
    patch_cluster_config_body_ai_tools_config = patch_cluster_config_body_ai_tools_config_create(
      true
    );
  }

  return patch_cluster_config_body_ai_tools_config;
}


#ifdef patch_cluster_config_body_ai_tools_config_MAIN

void test_patch_cluster_config_body_ai_tools_config(int include_optional) {
    patch_cluster_config_body_ai_tools_config_t* patch_cluster_config_body_ai_tools_config_1 = instantiate_patch_cluster_config_body_ai_tools_config(include_optional);

	cJSON* jsonpatch_cluster_config_body_ai_tools_config_1 = patch_cluster_config_body_ai_tools_config_convertToJSON(patch_cluster_config_body_ai_tools_config_1);
	printf("patch_cluster_config_body_ai_tools_config :\n%s\n", cJSON_Print(jsonpatch_cluster_config_body_ai_tools_config_1));
	patch_cluster_config_body_ai_tools_config_t* patch_cluster_config_body_ai_tools_config_2 = patch_cluster_config_body_ai_tools_config_parseFromJSON(jsonpatch_cluster_config_body_ai_tools_config_1);
	cJSON* jsonpatch_cluster_config_body_ai_tools_config_2 = patch_cluster_config_body_ai_tools_config_convertToJSON(patch_cluster_config_body_ai_tools_config_2);
	printf("repeating patch_cluster_config_body_ai_tools_config:\n%s\n", cJSON_Print(jsonpatch_cluster_config_body_ai_tools_config_2));
}

int main() {
  test_patch_cluster_config_body_ai_tools_config(1);
  test_patch_cluster_config_body_ai_tools_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_cluster_config_body_ai_tools_config_MAIN
#endif // patch_cluster_config_body_ai_tools_config_TEST
