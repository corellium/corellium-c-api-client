#ifndef patch_project_body_quotas_TEST
#define patch_project_body_quotas_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_project_body_quotas_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_project_body_quotas.h"
patch_project_body_quotas_t* instantiate_patch_project_body_quotas(int include_optional);



patch_project_body_quotas_t* instantiate_patch_project_body_quotas(int include_optional) {
  patch_project_body_quotas_t* patch_project_body_quotas = NULL;
  if (include_optional) {
    patch_project_body_quotas = patch_project_body_quotas_create(
      0,
      0,
      0
    );
  } else {
    patch_project_body_quotas = patch_project_body_quotas_create(
      0,
      0,
      0
    );
  }

  return patch_project_body_quotas;
}


#ifdef patch_project_body_quotas_MAIN

void test_patch_project_body_quotas(int include_optional) {
    patch_project_body_quotas_t* patch_project_body_quotas_1 = instantiate_patch_project_body_quotas(include_optional);

	cJSON* jsonpatch_project_body_quotas_1 = patch_project_body_quotas_convertToJSON(patch_project_body_quotas_1);
	printf("patch_project_body_quotas :\n%s\n", cJSON_Print(jsonpatch_project_body_quotas_1));
	patch_project_body_quotas_t* patch_project_body_quotas_2 = patch_project_body_quotas_parseFromJSON(jsonpatch_project_body_quotas_1);
	cJSON* jsonpatch_project_body_quotas_2 = patch_project_body_quotas_convertToJSON(patch_project_body_quotas_2);
	printf("repeating patch_project_body_quotas:\n%s\n", cJSON_Print(jsonpatch_project_body_quotas_2));
}

int main() {
  test_patch_project_body_quotas(1);
  test_patch_project_body_quotas(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_project_body_quotas_MAIN
#endif // patch_project_body_quotas_TEST
