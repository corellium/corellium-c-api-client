#ifndef teams_list_response_TEST
#define teams_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define teams_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/teams_list_response.h"
teams_list_response_t* instantiate_teams_list_response(int include_optional);



teams_list_response_t* instantiate_teams_list_response(int include_optional) {
  teams_list_response_t* teams_list_response = NULL;
  if (include_optional) {
    teams_list_response = teams_list_response_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  } else {
    teams_list_response = teams_list_response_create(
      list_createList(),
      25,
      137,
      25,
      0,
      true
    );
  }

  return teams_list_response;
}


#ifdef teams_list_response_MAIN

void test_teams_list_response(int include_optional) {
    teams_list_response_t* teams_list_response_1 = instantiate_teams_list_response(include_optional);

	cJSON* jsonteams_list_response_1 = teams_list_response_convertToJSON(teams_list_response_1);
	printf("teams_list_response :\n%s\n", cJSON_Print(jsonteams_list_response_1));
	teams_list_response_t* teams_list_response_2 = teams_list_response_parseFromJSON(jsonteams_list_response_1);
	cJSON* jsonteams_list_response_2 = teams_list_response_convertToJSON(teams_list_response_2);
	printf("repeating teams_list_response:\n%s\n", cJSON_Print(jsonteams_list_response_2));
}

int main() {
  test_teams_list_response(1);
  test_teams_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // teams_list_response_MAIN
#endif // teams_list_response_TEST
