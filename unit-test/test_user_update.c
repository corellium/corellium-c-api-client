#ifndef user_update_TEST
#define user_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_update.h"
user_update_t* instantiate_user_update(int include_optional);



user_update_t* instantiate_user_update(int include_optional) {
  user_update_t* user_update = NULL;
  if (include_optional) {
    user_update = user_update_create(
      "0",
      "0"
    );
  } else {
    user_update = user_update_create(
      "0",
      "0"
    );
  }

  return user_update;
}


#ifdef user_update_MAIN

void test_user_update(int include_optional) {
    user_update_t* user_update_1 = instantiate_user_update(include_optional);

	cJSON* jsonuser_update_1 = user_update_convertToJSON(user_update_1);
	printf("user_update :\n%s\n", cJSON_Print(jsonuser_update_1));
	user_update_t* user_update_2 = user_update_parseFromJSON(jsonuser_update_1);
	cJSON* jsonuser_update_2 = user_update_convertToJSON(user_update_2);
	printf("repeating user_update:\n%s\n", cJSON_Print(jsonuser_update_2));
}

int main() {
  test_user_update(1);
  test_user_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_update_MAIN
#endif // user_update_TEST
