#ifndef artifacts_path_TEST
#define artifacts_path_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define artifacts_path_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/artifacts_path.h"
artifacts_path_t* instantiate_artifacts_path(int include_optional);



artifacts_path_t* instantiate_artifacts_path(int include_optional) {
  artifacts_path_t* artifacts_path = NULL;
  if (include_optional) {
    artifacts_path = artifacts_path_create(
      "/mnt/charm_f7f9832a-f824-416f-a5ea-4adfe34754b5_artifacts"
    );
  } else {
    artifacts_path = artifacts_path_create(
      "/mnt/charm_f7f9832a-f824-416f-a5ea-4adfe34754b5_artifacts"
    );
  }

  return artifacts_path;
}


#ifdef artifacts_path_MAIN

void test_artifacts_path(int include_optional) {
    artifacts_path_t* artifacts_path_1 = instantiate_artifacts_path(include_optional);

	cJSON* jsonartifacts_path_1 = artifacts_path_convertToJSON(artifacts_path_1);
	printf("artifacts_path :\n%s\n", cJSON_Print(jsonartifacts_path_1));
	artifacts_path_t* artifacts_path_2 = artifacts_path_parseFromJSON(jsonartifacts_path_1);
	cJSON* jsonartifacts_path_2 = artifacts_path_convertToJSON(artifacts_path_2);
	printf("repeating artifacts_path:\n%s\n", cJSON_Print(jsonartifacts_path_2));
}

int main() {
  test_artifacts_path(1);
  test_artifacts_path(0);

  printf("Hello world \n");
  return 0;
}

#endif // artifacts_path_MAIN
#endif // artifacts_path_TEST
