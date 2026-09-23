#ifndef update_team_body_TEST
#define update_team_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_team_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_team_body.h"
update_team_body_t* instantiate_update_team_body(int include_optional);



update_team_body_t* instantiate_update_team_body(int include_optional) {
  update_team_body_t* update_team_body = NULL;
  if (include_optional) {
    update_team_body = update_team_body_create(
      "Mobile QA"
    );
  } else {
    update_team_body = update_team_body_create(
      "Mobile QA"
    );
  }

  return update_team_body;
}


#ifdef update_team_body_MAIN

void test_update_team_body(int include_optional) {
    update_team_body_t* update_team_body_1 = instantiate_update_team_body(include_optional);

	cJSON* jsonupdate_team_body_1 = update_team_body_convertToJSON(update_team_body_1);
	printf("update_team_body :\n%s\n", cJSON_Print(jsonupdate_team_body_1));
	update_team_body_t* update_team_body_2 = update_team_body_parseFromJSON(jsonupdate_team_body_1);
	cJSON* jsonupdate_team_body_2 = update_team_body_convertToJSON(update_team_body_2);
	printf("repeating update_team_body:\n%s\n", cJSON_Print(jsonupdate_team_body_2));
}

int main() {
  test_update_team_body(1);
  test_update_team_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_team_body_MAIN
#endif // update_team_body_TEST
