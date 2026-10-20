#ifndef logging_v1_TEST
#define logging_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define logging_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/logging_v1.h"
logging_v1_t* instantiate_logging_v1(int include_optional);



logging_v1_t* instantiate_logging_v1(int include_optional) {
  logging_v1_t* logging_v1 = NULL;
  if (include_optional) {
    logging_v1 = logging_v1_create(
      1,
      1
    );
  } else {
    logging_v1 = logging_v1_create(
      1,
      1
    );
  }

  return logging_v1;
}


#ifdef logging_v1_MAIN

void test_logging_v1(int include_optional) {
    logging_v1_t* logging_v1_1 = instantiate_logging_v1(include_optional);

	cJSON* jsonlogging_v1_1 = logging_v1_convertToJSON(logging_v1_1);
	printf("logging_v1 :\n%s\n", cJSON_Print(jsonlogging_v1_1));
	logging_v1_t* logging_v1_2 = logging_v1_parseFromJSON(jsonlogging_v1_1);
	cJSON* jsonlogging_v1_2 = logging_v1_convertToJSON(logging_v1_2);
	printf("repeating logging_v1:\n%s\n", cJSON_Print(jsonlogging_v1_2));
}

int main() {
  test_logging_v1(1);
  test_logging_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // logging_v1_MAIN
#endif // logging_v1_TEST
