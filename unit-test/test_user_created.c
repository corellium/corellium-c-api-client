#ifndef user_created_TEST
#define user_created_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_created_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_created.h"
user_created_t* instantiate_user_created(int include_optional);



user_created_t* instantiate_user_created(int include_optional) {
  user_created_t* user_created = NULL;
  if (include_optional) {
    user_created = user_created_create(
      "0"
    );
  } else {
    user_created = user_created_create(
      "0"
    );
  }

  return user_created;
}


#ifdef user_created_MAIN

void test_user_created(int include_optional) {
    user_created_t* user_created_1 = instantiate_user_created(include_optional);

	cJSON* jsonuser_created_1 = user_created_convertToJSON(user_created_1);
	printf("user_created :\n%s\n", cJSON_Print(jsonuser_created_1));
	user_created_t* user_created_2 = user_created_parseFromJSON(jsonuser_created_1);
	cJSON* jsonuser_created_2 = user_created_convertToJSON(user_created_2);
	printf("repeating user_created:\n%s\n", cJSON_Print(jsonuser_created_2));
}

int main() {
  test_user_created(1);
  test_user_created(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_created_MAIN
#endif // user_created_TEST
