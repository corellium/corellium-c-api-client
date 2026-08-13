#ifndef user_snapshots_TEST
#define user_snapshots_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_snapshots_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_snapshots.h"
user_snapshots_t* instantiate_user_snapshots(int include_optional);

#include "test_shared_snapshots_info.c"
#include "test_shared_snapshots_info.c"


user_snapshots_t* instantiate_user_snapshots(int include_optional) {
  user_snapshots_t* user_snapshots = NULL;
  if (include_optional) {
    user_snapshots = user_snapshots_create(
       // false, not to have infinite recursion
      instantiate_shared_snapshots_info(0),
       // false, not to have infinite recursion
      instantiate_shared_snapshots_info(0)
    );
  } else {
    user_snapshots = user_snapshots_create(
      NULL,
      NULL
    );
  }

  return user_snapshots;
}


#ifdef user_snapshots_MAIN

void test_user_snapshots(int include_optional) {
    user_snapshots_t* user_snapshots_1 = instantiate_user_snapshots(include_optional);

	cJSON* jsonuser_snapshots_1 = user_snapshots_convertToJSON(user_snapshots_1);
	printf("user_snapshots :\n%s\n", cJSON_Print(jsonuser_snapshots_1));
	user_snapshots_t* user_snapshots_2 = user_snapshots_parseFromJSON(jsonuser_snapshots_1);
	cJSON* jsonuser_snapshots_2 = user_snapshots_convertToJSON(user_snapshots_2);
	printf("repeating user_snapshots:\n%s\n", cJSON_Print(jsonuser_snapshots_2));
}

int main() {
  test_user_snapshots(1);
  test_user_snapshots(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_snapshots_MAIN
#endif // user_snapshots_TEST
