#ifndef paginated_assessments_TEST
#define paginated_assessments_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paginated_assessments_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paginated_assessments.h"
paginated_assessments_t* instantiate_paginated_assessments(int include_optional);



paginated_assessments_t* instantiate_paginated_assessments(int include_optional) {
  paginated_assessments_t* paginated_assessments = NULL;
  if (include_optional) {
    paginated_assessments = paginated_assessments_create(
      56,
      56,
      56,
      56,
      list_createList()
    );
  } else {
    paginated_assessments = paginated_assessments_create(
      56,
      56,
      56,
      56,
      list_createList()
    );
  }

  return paginated_assessments;
}


#ifdef paginated_assessments_MAIN

void test_paginated_assessments(int include_optional) {
    paginated_assessments_t* paginated_assessments_1 = instantiate_paginated_assessments(include_optional);

	cJSON* jsonpaginated_assessments_1 = paginated_assessments_convertToJSON(paginated_assessments_1);
	printf("paginated_assessments :\n%s\n", cJSON_Print(jsonpaginated_assessments_1));
	paginated_assessments_t* paginated_assessments_2 = paginated_assessments_parseFromJSON(jsonpaginated_assessments_1);
	cJSON* jsonpaginated_assessments_2 = paginated_assessments_convertToJSON(paginated_assessments_2);
	printf("repeating paginated_assessments:\n%s\n", cJSON_Print(jsonpaginated_assessments_2));
}

int main() {
  test_paginated_assessments(1);
  test_paginated_assessments(0);

  printf("Hello world \n");
  return 0;
}

#endif // paginated_assessments_MAIN
#endif // paginated_assessments_TEST
