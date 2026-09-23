#ifndef project_key_TEST
#define project_key_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define project_key_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/project_key.h"
project_key_t* instantiate_project_key(int include_optional);



project_key_t* instantiate_project_key(int include_optional) {
  project_key_t* project_key = NULL;
  if (include_optional) {
    project_key = project_key_create(
      corellium_api_project_key_KIND_ssh,
      "Build server key",
      "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIJUlGdieyRXdiVIyQjqthDE1YzmwzH0ZeZuHkBuC9Gwr user@example.com",
      "9c1098dc-e881-41fb-b3af-e2d5ddd55d86",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "82:af:e7:ec:8c:03:17:fa:32:89:d7:e3:93:e2:9e:72",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    project_key = project_key_create(
      corellium_api_project_key_KIND_ssh,
      "Build server key",
      "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIJUlGdieyRXdiVIyQjqthDE1YzmwzH0ZeZuHkBuC9Gwr user@example.com",
      "9c1098dc-e881-41fb-b3af-e2d5ddd55d86",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "82:af:e7:ec:8c:03:17:fa:32:89:d7:e3:93:e2:9e:72",
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return project_key;
}


#ifdef project_key_MAIN

void test_project_key(int include_optional) {
    project_key_t* project_key_1 = instantiate_project_key(include_optional);

	cJSON* jsonproject_key_1 = project_key_convertToJSON(project_key_1);
	printf("project_key :\n%s\n", cJSON_Print(jsonproject_key_1));
	project_key_t* project_key_2 = project_key_parseFromJSON(jsonproject_key_1);
	cJSON* jsonproject_key_2 = project_key_convertToJSON(project_key_2);
	printf("repeating project_key:\n%s\n", cJSON_Print(jsonproject_key_2));
}

int main() {
  test_project_key(1);
  test_project_key(0);

  printf("Hello world \n");
  return 0;
}

#endif // project_key_MAIN
#endif // project_key_TEST
