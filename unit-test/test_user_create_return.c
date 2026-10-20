#ifndef user_create_return_TEST
#define user_create_return_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_create_return_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_create_return.h"
user_create_return_t* instantiate_user_create_return(int include_optional);



user_create_return_t* instantiate_user_create_return(int include_optional) {
  user_create_return_t* user_create_return = NULL;
  if (include_optional) {
    user_create_return = user_create_return_create(
      "0"
    );
  } else {
    user_create_return = user_create_return_create(
      "0"
    );
  }

  return user_create_return;
}


#ifdef user_create_return_MAIN

void test_user_create_return(int include_optional) {
    user_create_return_t* user_create_return_1 = instantiate_user_create_return(include_optional);

	cJSON* jsonuser_create_return_1 = user_create_return_convertToJSON(user_create_return_1);
	printf("user_create_return :\n%s\n", cJSON_Print(jsonuser_create_return_1));
	user_create_return_t* user_create_return_2 = user_create_return_parseFromJSON(jsonuser_create_return_1);
	cJSON* jsonuser_create_return_2 = user_create_return_convertToJSON(user_create_return_2);
	printf("repeating user_create_return:\n%s\n", cJSON_Print(jsonuser_create_return_2));
}

int main() {
  test_user_create_return(1);
  test_user_create_return(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_create_return_MAIN
#endif // user_create_return_TEST
