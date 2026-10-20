#ifndef create_team_body_TEST
#define create_team_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_team_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_team_body.h"
create_team_body_t* instantiate_create_team_body(int include_optional);



create_team_body_t* instantiate_create_team_body(int include_optional) {
  create_team_body_t* create_team_body = NULL;
  if (include_optional) {
    create_team_body = create_team_body_create(
      "Mobile QA"
    );
  } else {
    create_team_body = create_team_body_create(
      "Mobile QA"
    );
  }

  return create_team_body;
}


#ifdef create_team_body_MAIN

void test_create_team_body(int include_optional) {
    create_team_body_t* create_team_body_1 = instantiate_create_team_body(include_optional);

	cJSON* jsoncreate_team_body_1 = create_team_body_convertToJSON(create_team_body_1);
	printf("create_team_body :\n%s\n", cJSON_Print(jsoncreate_team_body_1));
	create_team_body_t* create_team_body_2 = create_team_body_parseFromJSON(jsoncreate_team_body_1);
	cJSON* jsoncreate_team_body_2 = create_team_body_convertToJSON(create_team_body_2);
	printf("repeating create_team_body:\n%s\n", cJSON_Print(jsoncreate_team_body_2));
}

int main() {
  test_create_team_body(1);
  test_create_team_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_team_body_MAIN
#endif // create_team_body_TEST
