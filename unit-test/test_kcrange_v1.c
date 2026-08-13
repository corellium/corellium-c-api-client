#ifndef kcrange_v1_TEST
#define kcrange_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define kcrange_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/kcrange_v1.h"
kcrange_v1_t* instantiate_kcrange_v1(int include_optional);



kcrange_v1_t* instantiate_kcrange_v1(int include_optional) {
  kcrange_v1_t* kcrange_v1 = NULL;
  if (include_optional) {
    kcrange_v1 = kcrange_v1_create(
      "0",
      list_createList()
    );
  } else {
    kcrange_v1 = kcrange_v1_create(
      "0",
      list_createList()
    );
  }

  return kcrange_v1;
}


#ifdef kcrange_v1_MAIN

void test_kcrange_v1(int include_optional) {
    kcrange_v1_t* kcrange_v1_1 = instantiate_kcrange_v1(include_optional);

	cJSON* jsonkcrange_v1_1 = kcrange_v1_convertToJSON(kcrange_v1_1);
	printf("kcrange_v1 :\n%s\n", cJSON_Print(jsonkcrange_v1_1));
	kcrange_v1_t* kcrange_v1_2 = kcrange_v1_parseFromJSON(jsonkcrange_v1_1);
	cJSON* jsonkcrange_v1_2 = kcrange_v1_convertToJSON(kcrange_v1_2);
	printf("repeating kcrange_v1:\n%s\n", cJSON_Print(jsonkcrange_v1_2));
}

int main() {
  test_kcrange_v1(1);
  test_kcrange_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // kcrange_v1_MAIN
#endif // kcrange_v1_TEST
