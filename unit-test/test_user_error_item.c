#ifndef user_error_item_TEST
#define user_error_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_error_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_error_item.h"
user_error_item_t* instantiate_user_error_item(int include_optional);



user_error_item_t* instantiate_user_error_item(int include_optional) {
  user_error_item_t* user_error_item = NULL;
  if (include_optional) {
    user_error_item = user_error_item_create(
      "0",
      corellium_api_user_error_item_ERRORID_UserError,
      "0",
      "0",
      list_createList()
    );
  } else {
    user_error_item = user_error_item_create(
      "0",
      corellium_api_user_error_item_ERRORID_UserError,
      "0",
      "0",
      list_createList()
    );
  }

  return user_error_item;
}


#ifdef user_error_item_MAIN

void test_user_error_item(int include_optional) {
    user_error_item_t* user_error_item_1 = instantiate_user_error_item(include_optional);

	cJSON* jsonuser_error_item_1 = user_error_item_convertToJSON(user_error_item_1);
	printf("user_error_item :\n%s\n", cJSON_Print(jsonuser_error_item_1));
	user_error_item_t* user_error_item_2 = user_error_item_parseFromJSON(jsonuser_error_item_1);
	cJSON* jsonuser_error_item_2 = user_error_item_convertToJSON(user_error_item_2);
	printf("repeating user_error_item:\n%s\n", cJSON_Print(jsonuser_error_item_2));
}

int main() {
  test_user_error_item(1);
  test_user_error_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_error_item_MAIN
#endif // user_error_item_TEST
