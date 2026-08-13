#ifndef insufficient_storage_error_v1_TEST
#define insufficient_storage_error_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define insufficient_storage_error_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/insufficient_storage_error_v1.h"
insufficient_storage_error_v1_t* instantiate_insufficient_storage_error_v1(int include_optional);



insufficient_storage_error_v1_t* instantiate_insufficient_storage_error_v1(int include_optional) {
  insufficient_storage_error_v1_t* insufficient_storage_error_v1 = NULL;
  if (include_optional) {
    insufficient_storage_error_v1 = insufficient_storage_error_v1_create(
      "0",
      "0",
      1.337,
      1.337,
      1.337
    );
  } else {
    insufficient_storage_error_v1 = insufficient_storage_error_v1_create(
      "0",
      "0",
      1.337,
      1.337,
      1.337
    );
  }

  return insufficient_storage_error_v1;
}


#ifdef insufficient_storage_error_v1_MAIN

void test_insufficient_storage_error_v1(int include_optional) {
    insufficient_storage_error_v1_t* insufficient_storage_error_v1_1 = instantiate_insufficient_storage_error_v1(include_optional);

	cJSON* jsoninsufficient_storage_error_v1_1 = insufficient_storage_error_v1_convertToJSON(insufficient_storage_error_v1_1);
	printf("insufficient_storage_error_v1 :\n%s\n", cJSON_Print(jsoninsufficient_storage_error_v1_1));
	insufficient_storage_error_v1_t* insufficient_storage_error_v1_2 = insufficient_storage_error_v1_parseFromJSON(jsoninsufficient_storage_error_v1_1);
	cJSON* jsoninsufficient_storage_error_v1_2 = insufficient_storage_error_v1_convertToJSON(insufficient_storage_error_v1_2);
	printf("repeating insufficient_storage_error_v1:\n%s\n", cJSON_Print(jsoninsufficient_storage_error_v1_2));
}

int main() {
  test_insufficient_storage_error_v1(1);
  test_insufficient_storage_error_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // insufficient_storage_error_v1_MAIN
#endif // insufficient_storage_error_v1_TEST
