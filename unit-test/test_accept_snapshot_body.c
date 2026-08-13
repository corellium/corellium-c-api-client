#ifndef accept_snapshot_body_TEST
#define accept_snapshot_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accept_snapshot_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accept_snapshot_body.h"
accept_snapshot_body_t* instantiate_accept_snapshot_body(int include_optional);



accept_snapshot_body_t* instantiate_accept_snapshot_body(int include_optional) {
  accept_snapshot_body_t* accept_snapshot_body = NULL;
  if (include_optional) {
    accept_snapshot_body = accept_snapshot_body_create(
      "0",
      "0"
    );
  } else {
    accept_snapshot_body = accept_snapshot_body_create(
      "0",
      "0"
    );
  }

  return accept_snapshot_body;
}


#ifdef accept_snapshot_body_MAIN

void test_accept_snapshot_body(int include_optional) {
    accept_snapshot_body_t* accept_snapshot_body_1 = instantiate_accept_snapshot_body(include_optional);

	cJSON* jsonaccept_snapshot_body_1 = accept_snapshot_body_convertToJSON(accept_snapshot_body_1);
	printf("accept_snapshot_body :\n%s\n", cJSON_Print(jsonaccept_snapshot_body_1));
	accept_snapshot_body_t* accept_snapshot_body_2 = accept_snapshot_body_parseFromJSON(jsonaccept_snapshot_body_1);
	cJSON* jsonaccept_snapshot_body_2 = accept_snapshot_body_convertToJSON(accept_snapshot_body_2);
	printf("repeating accept_snapshot_body:\n%s\n", cJSON_Print(jsonaccept_snapshot_body_2));
}

int main() {
  test_accept_snapshot_body(1);
  test_accept_snapshot_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // accept_snapshot_body_MAIN
#endif // accept_snapshot_body_TEST
