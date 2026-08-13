#ifndef team_user_TEST
#define team_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define team_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/team_user.h"
team_user_t* instantiate_team_user(int include_optional);



team_user_t* instantiate_team_user(int include_optional) {
  team_user_t* team_user = NULL;
  if (include_optional) {
    team_user = team_user_create(
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1,
      1
    );
  } else {
    team_user = team_user_create(
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1,
      1
    );
  }

  return team_user;
}


#ifdef team_user_MAIN

void test_team_user(int include_optional) {
    team_user_t* team_user_1 = instantiate_team_user(include_optional);

	cJSON* jsonteam_user_1 = team_user_convertToJSON(team_user_1);
	printf("team_user :\n%s\n", cJSON_Print(jsonteam_user_1));
	team_user_t* team_user_2 = team_user_parseFromJSON(jsonteam_user_1);
	cJSON* jsonteam_user_2 = team_user_convertToJSON(team_user_2);
	printf("repeating team_user:\n%s\n", cJSON_Print(jsonteam_user_2));
}

int main() {
  test_team_user(1);
  test_team_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // team_user_MAIN
#endif // team_user_TEST
