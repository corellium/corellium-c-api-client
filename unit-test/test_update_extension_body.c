#ifndef update_extension_body_TEST
#define update_extension_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_extension_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_extension_body.h"
update_extension_body_t* instantiate_update_extension_body(int include_optional);



update_extension_body_t* instantiate_update_extension_body(int include_optional) {
  update_extension_body_t* update_extension_body = NULL;
  if (include_optional) {
    update_extension_body = update_extension_body_create(
      false
    );
  } else {
    update_extension_body = update_extension_body_create(
      false
    );
  }

  return update_extension_body;
}


#ifdef update_extension_body_MAIN

void test_update_extension_body(int include_optional) {
    update_extension_body_t* update_extension_body_1 = instantiate_update_extension_body(include_optional);

	cJSON* jsonupdate_extension_body_1 = update_extension_body_convertToJSON(update_extension_body_1);
	printf("update_extension_body :\n%s\n", cJSON_Print(jsonupdate_extension_body_1));
	update_extension_body_t* update_extension_body_2 = update_extension_body_parseFromJSON(jsonupdate_extension_body_1);
	cJSON* jsonupdate_extension_body_2 = update_extension_body_convertToJSON(update_extension_body_2);
	printf("repeating update_extension_body:\n%s\n", cJSON_Print(jsonupdate_extension_body_2));
}

int main() {
  test_update_extension_body(1);
  test_update_extension_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_extension_body_MAIN
#endif // update_extension_body_TEST
