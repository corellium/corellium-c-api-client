#ifndef team_v1_TEST
#define team_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define team_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/team_v1.h"
team_v1_t* instantiate_team_v1(int include_optional);



team_v1_t* instantiate_team_v1(int include_optional) {
  team_v1_t* team_v1 = NULL;
  if (include_optional) {
    team_v1 = team_v1_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    team_v1 = team_v1_create(
      "0",
      "0",
      list_createList()
    );
  }

  return team_v1;
}


#ifdef team_v1_MAIN

void test_team_v1(int include_optional) {
    team_v1_t* team_v1_1 = instantiate_team_v1(include_optional);

	cJSON* jsonteam_v1_1 = team_v1_convertToJSON(team_v1_1);
	printf("team_v1 :\n%s\n", cJSON_Print(jsonteam_v1_1));
	team_v1_t* team_v1_2 = team_v1_parseFromJSON(jsonteam_v1_1);
	cJSON* jsonteam_v1_2 = team_v1_convertToJSON(team_v1_2);
	printf("repeating team_v1:\n%s\n", cJSON_Print(jsonteam_v1_2));
}

int main() {
  test_team_v1(1);
  test_team_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // team_v1_MAIN
#endif // team_v1_TEST
