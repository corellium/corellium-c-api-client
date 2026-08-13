#ifndef user_create_TEST
#define user_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_create.h"
user_create_t* instantiate_user_create(int include_optional);



user_create_t* instantiate_user_create(int include_optional) {
  user_create_t* user_create = NULL;
  if (include_optional) {
    user_create = user_create_create(
      "0",
      "0",
      "0",
      "0",
      1,
      1
    );
  } else {
    user_create = user_create_create(
      "0",
      "0",
      "0",
      "0",
      1,
      1
    );
  }

  return user_create;
}


#ifdef user_create_MAIN

void test_user_create(int include_optional) {
    user_create_t* user_create_1 = instantiate_user_create(include_optional);

	cJSON* jsonuser_create_1 = user_create_convertToJSON(user_create_1);
	printf("user_create :\n%s\n", cJSON_Print(jsonuser_create_1));
	user_create_t* user_create_2 = user_create_parseFromJSON(jsonuser_create_1);
	cJSON* jsonuser_create_2 = user_create_convertToJSON(user_create_2);
	printf("repeating user_create:\n%s\n", cJSON_Print(jsonuser_create_2));
}

int main() {
  test_user_create(1);
  test_user_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_create_MAIN
#endif // user_create_TEST
