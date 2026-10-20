#ifndef change_password_body_TEST
#define change_password_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define change_password_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/change_password_body.h"
change_password_body_t* instantiate_change_password_body(int include_optional);



change_password_body_t* instantiate_change_password_body(int include_optional) {
  change_password_body_t* change_password_body = NULL;
  if (include_optional) {
    change_password_body = change_password_body_create(
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "<redacted>",
      "<redacted>"
    );
  } else {
    change_password_body = change_password_body_create(
      "e8c5b7ea-aa5f-4a4a-bdca-0c67060b5320",
      "<redacted>",
      "<redacted>"
    );
  }

  return change_password_body;
}


#ifdef change_password_body_MAIN

void test_change_password_body(int include_optional) {
    change_password_body_t* change_password_body_1 = instantiate_change_password_body(include_optional);

	cJSON* jsonchange_password_body_1 = change_password_body_convertToJSON(change_password_body_1);
	printf("change_password_body :\n%s\n", cJSON_Print(jsonchange_password_body_1));
	change_password_body_t* change_password_body_2 = change_password_body_parseFromJSON(jsonchange_password_body_1);
	cJSON* jsonchange_password_body_2 = change_password_body_convertToJSON(change_password_body_2);
	printf("repeating change_password_body:\n%s\n", cJSON_Print(jsonchange_password_body_2));
}

int main() {
  test_change_password_body(1);
  test_change_password_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // change_password_body_MAIN
#endif // change_password_body_TEST
