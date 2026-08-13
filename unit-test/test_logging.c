#ifndef logging_TEST
#define logging_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define logging_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/logging.h"
logging_t* instantiate_logging(int include_optional);



logging_t* instantiate_logging(int include_optional) {
  logging_t* logging = NULL;
  if (include_optional) {
    logging = logging_create(
      1,
      1
    );
  } else {
    logging = logging_create(
      1,
      1
    );
  }

  return logging;
}


#ifdef logging_MAIN

void test_logging(int include_optional) {
    logging_t* logging_1 = instantiate_logging(include_optional);

	cJSON* jsonlogging_1 = logging_convertToJSON(logging_1);
	printf("logging :\n%s\n", cJSON_Print(jsonlogging_1));
	logging_t* logging_2 = logging_parseFromJSON(jsonlogging_1);
	cJSON* jsonlogging_2 = logging_convertToJSON(logging_2);
	printf("repeating logging:\n%s\n", cJSON_Print(jsonlogging_2));
}

int main() {
  test_logging(1);
  test_logging(0);

  printf("Hello world \n");
  return 0;
}

#endif // logging_MAIN
#endif // logging_TEST
