#ifndef user_snapshots_schema_TEST
#define user_snapshots_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_snapshots_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_snapshots_schema.h"
user_snapshots_schema_t* instantiate_user_snapshots_schema(int include_optional);



user_snapshots_schema_t* instantiate_user_snapshots_schema(int include_optional) {
  user_snapshots_schema_t* user_snapshots_schema = NULL;
  if (include_optional) {
    user_snapshots_schema = user_snapshots_schema_create(
      list_createList(),
      list_createList()
    );
  } else {
    user_snapshots_schema = user_snapshots_schema_create(
      list_createList(),
      list_createList()
    );
  }

  return user_snapshots_schema;
}


#ifdef user_snapshots_schema_MAIN

void test_user_snapshots_schema(int include_optional) {
    user_snapshots_schema_t* user_snapshots_schema_1 = instantiate_user_snapshots_schema(include_optional);

	cJSON* jsonuser_snapshots_schema_1 = user_snapshots_schema_convertToJSON(user_snapshots_schema_1);
	printf("user_snapshots_schema :\n%s\n", cJSON_Print(jsonuser_snapshots_schema_1));
	user_snapshots_schema_t* user_snapshots_schema_2 = user_snapshots_schema_parseFromJSON(jsonuser_snapshots_schema_1);
	cJSON* jsonuser_snapshots_schema_2 = user_snapshots_schema_convertToJSON(user_snapshots_schema_2);
	printf("repeating user_snapshots_schema:\n%s\n", cJSON_Print(jsonuser_snapshots_schema_2));
}

int main() {
  test_user_snapshots_schema(1);
  test_user_snapshots_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_snapshots_schema_MAIN
#endif // user_snapshots_schema_TEST
