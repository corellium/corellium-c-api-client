#ifndef team_created_TEST
#define team_created_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define team_created_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/team_created.h"
team_created_t* instantiate_team_created(int include_optional);



team_created_t* instantiate_team_created(int include_optional) {
  team_created_t* team_created = NULL;
  if (include_optional) {
    team_created = team_created_create(
      "089c8ffd-ca4d-4d35-80ab-0847d18b7213"
    );
  } else {
    team_created = team_created_create(
      "089c8ffd-ca4d-4d35-80ab-0847d18b7213"
    );
  }

  return team_created;
}


#ifdef team_created_MAIN

void test_team_created(int include_optional) {
    team_created_t* team_created_1 = instantiate_team_created(include_optional);

	cJSON* jsonteam_created_1 = team_created_convertToJSON(team_created_1);
	printf("team_created :\n%s\n", cJSON_Print(jsonteam_created_1));
	team_created_t* team_created_2 = team_created_parseFromJSON(jsonteam_created_1);
	cJSON* jsonteam_created_2 = team_created_convertToJSON(team_created_2);
	printf("repeating team_created:\n%s\n", cJSON_Print(jsonteam_created_2));
}

int main() {
  test_team_created(1);
  test_team_created(0);

  printf("Hello world \n");
  return 0;
}

#endif // team_created_MAIN
#endif // team_created_TEST
