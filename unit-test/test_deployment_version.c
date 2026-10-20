#ifndef deployment_version_TEST
#define deployment_version_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define deployment_version_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/deployment_version.h"
deployment_version_t* instantiate_deployment_version(int include_optional);



deployment_version_t* instantiate_deployment_version(int include_optional) {
  deployment_version_t* deployment_version = NULL;
  if (include_optional) {
    deployment_version = deployment_version_create(
      "0",
      "0",
      "a",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    deployment_version = deployment_version_create(
      "0",
      "0",
      "a",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return deployment_version;
}


#ifdef deployment_version_MAIN

void test_deployment_version(int include_optional) {
    deployment_version_t* deployment_version_1 = instantiate_deployment_version(include_optional);

	cJSON* jsondeployment_version_1 = deployment_version_convertToJSON(deployment_version_1);
	printf("deployment_version :\n%s\n", cJSON_Print(jsondeployment_version_1));
	deployment_version_t* deployment_version_2 = deployment_version_parseFromJSON(jsondeployment_version_1);
	cJSON* jsondeployment_version_2 = deployment_version_convertToJSON(deployment_version_2);
	printf("repeating deployment_version:\n%s\n", cJSON_Print(jsondeployment_version_2));
}

int main() {
  test_deployment_version(1);
  test_deployment_version(0);

  printf("Hello world \n");
  return 0;
}

#endif // deployment_version_MAIN
#endif // deployment_version_TEST
