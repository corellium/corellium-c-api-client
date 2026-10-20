#ifndef update_own_profile_body_TEST
#define update_own_profile_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_own_profile_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_own_profile_body.h"
update_own_profile_body_t* instantiate_update_own_profile_body(int include_optional);



update_own_profile_body_t* instantiate_update_own_profile_body(int include_optional) {
  update_own_profile_body_t* update_own_profile_body = NULL;
  if (include_optional) {
    update_own_profile_body = update_own_profile_body_create(
      "Jane Doe"
    );
  } else {
    update_own_profile_body = update_own_profile_body_create(
      "Jane Doe"
    );
  }

  return update_own_profile_body;
}


#ifdef update_own_profile_body_MAIN

void test_update_own_profile_body(int include_optional) {
    update_own_profile_body_t* update_own_profile_body_1 = instantiate_update_own_profile_body(include_optional);

	cJSON* jsonupdate_own_profile_body_1 = update_own_profile_body_convertToJSON(update_own_profile_body_1);
	printf("update_own_profile_body :\n%s\n", cJSON_Print(jsonupdate_own_profile_body_1));
	update_own_profile_body_t* update_own_profile_body_2 = update_own_profile_body_parseFromJSON(jsonupdate_own_profile_body_1);
	cJSON* jsonupdate_own_profile_body_2 = update_own_profile_body_convertToJSON(update_own_profile_body_2);
	printf("repeating update_own_profile_body:\n%s\n", cJSON_Print(jsonupdate_own_profile_body_2));
}

int main() {
  test_update_own_profile_body(1);
  test_update_own_profile_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_own_profile_body_MAIN
#endif // update_own_profile_body_TEST
