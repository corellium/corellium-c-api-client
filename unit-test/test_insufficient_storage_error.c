#ifndef insufficient_storage_error_TEST
#define insufficient_storage_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define insufficient_storage_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/insufficient_storage_error.h"
insufficient_storage_error_t* instantiate_insufficient_storage_error(int include_optional);



insufficient_storage_error_t* instantiate_insufficient_storage_error(int include_optional) {
  insufficient_storage_error_t* insufficient_storage_error = NULL;
  if (include_optional) {
    insufficient_storage_error = insufficient_storage_error_create(
      "There is not enough storage space to store the requested file",
      corellium_api_insufficient_storage_error_ERRORID_InsufficientStorage,
      2199023255552,
      1073741824,
      3448156160
    );
  } else {
    insufficient_storage_error = insufficient_storage_error_create(
      "There is not enough storage space to store the requested file",
      corellium_api_insufficient_storage_error_ERRORID_InsufficientStorage,
      2199023255552,
      1073741824,
      3448156160
    );
  }

  return insufficient_storage_error;
}


#ifdef insufficient_storage_error_MAIN

void test_insufficient_storage_error(int include_optional) {
    insufficient_storage_error_t* insufficient_storage_error_1 = instantiate_insufficient_storage_error(include_optional);

	cJSON* jsoninsufficient_storage_error_1 = insufficient_storage_error_convertToJSON(insufficient_storage_error_1);
	printf("insufficient_storage_error :\n%s\n", cJSON_Print(jsoninsufficient_storage_error_1));
	insufficient_storage_error_t* insufficient_storage_error_2 = insufficient_storage_error_parseFromJSON(jsoninsufficient_storage_error_1);
	cJSON* jsoninsufficient_storage_error_2 = insufficient_storage_error_convertToJSON(insufficient_storage_error_2);
	printf("repeating insufficient_storage_error:\n%s\n", cJSON_Print(jsoninsufficient_storage_error_2));
}

int main() {
  test_insufficient_storage_error(1);
  test_insufficient_storage_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // insufficient_storage_error_MAIN
#endif // insufficient_storage_error_TEST
